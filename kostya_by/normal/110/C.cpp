//
//  main.cpp
//  lucky sum of digits
//
//  Created by Sokol Kostya's MacBook on 21.01.11.
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
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int aa = -1, bb = -1;

int main (int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if ((n - 4 * i) < 0 || (n - 4 * i) % 7 != 0) continue;
        int j = (n - 4 * i) / 7;
        if (aa == -1)
        {
            aa = i; bb = j;
        }
        if (aa + bb > i + j)
        {
            aa = i; bb = j;
        }
        if ((aa + bb == i + j) && (i > aa))
        {
            aa = i; bb = j;
        }
    }
    if (aa == -1)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < aa; i++) printf("4"); 
    for (int j = 0; j < bb; j++) printf("7");
    return 0;
}