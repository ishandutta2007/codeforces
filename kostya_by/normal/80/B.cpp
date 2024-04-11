//
//  main.cpp
//  t1c69
//
//  Created by Sokol Kostya's MacBook on 18.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main (int argc, const char * argv[])
{
    int hh, mm;
    scanf("%d:%d",&hh,&mm);
    if (hh >= 12) hh -= 12;
    hh = 60 * hh + mm;
    cout << fixed << setprecision(9) << (1.0 * 360 * hh) / 720 << " " << (1.0 * 360 * mm) / 60;
    return 0;
}