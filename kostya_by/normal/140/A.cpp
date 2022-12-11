//
//  main.cpp
//  round100task1
//
//  Created by Sokol Kostya's MacBook on 04.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>

typedef unsigned long long ull;
#define mp make_pair

const long double eps = 1e-7;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

double sqr(double x)
{
    return x * x;
}

int main (int argc, const char * argv[])
{
    int n, r, R, nn;
    cin >> n >> R >> r;
    if (n == 1 && r <= R)
    {
        cout << "YES";
        return 0;
    }
    if (n == 2)
    {
        if (R - 2 * r >= 0)
        {
            cout << "YES";
        } else cout << "NO";
        return 0;
    }
    if (R - 2 * r <= 0) 
    {
        cout << "NO";
        return 0;
    }
    double aa = R - r;
    double bb = sqrt(sqr(aa) - sqr(r));
   // cout << bb << endl;
    double alpha = acos(1.0 * (sqr(aa) + sqr(bb) - sqr(r)) / (2 * aa * bb));
    nn = floor(2 * pi / (2 * alpha) + eps);
    //cout << nn << endl;
    //cout << 2 * pi / (2 * alpha) << endl;
    if (nn >= n) cout << "YES"; else cout << "NO";
    return 0;
}