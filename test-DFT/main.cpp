//
//  main.cpp
//  test-DFT
//
//  Created by Anton Volkov on 05/04/2018.
//  Copyright © 2018 Anton Volkov. All rights reserved.
//

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

#include "HighResTImer.hpp"

HighResTimer timer("Tick counter");

int main() {
    cv::Mat complexI(2000, 2000, CV_32F, cv::Scalar(5.5f));
    cv::UMat compl1;
    
    complexI.copyTo(compl1);
    
    //DFT
    timer.start();
    timer.reset();

    cv::dft(compl1, compl1);
    
    timer.stop();
    
    printf("DFT time:\n");
    timer.printMilliseconds();
    timer.reset();

    return 0;
}
