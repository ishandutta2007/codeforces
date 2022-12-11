//
//  main.cpp
//  tor
//
//  Created by Sokol Kostya's MacBook on 09.01.11.
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
#include <iomanip>
#include <queue>
#include <stack>


typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int main (int argc, const char * argv[])
{   
    long long a, b, c = 0, aa[30], bb[30], pt = 1;
    cin >> a >> b;
    for (int i = 0; i < 30; i++)
    {
        aa[i] = a % 3;
        bb[i] = b % 3;
        c += ((bb[i] - aa[i] + 18) % 3) * pt;
        pt *= 3;
        a /= 3;
        b /= 3;
    }
    cout << c;
    return 0;
}