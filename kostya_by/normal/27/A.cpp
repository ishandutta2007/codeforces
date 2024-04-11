//
//  main.cpp
//  epic game
//
//  Created by Sokol Kostya's MacBook on 15.01.11.
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

int nod(int a, int b)
{
    if (a != 0) return nod(b % a, a); else return b;
}

double sqr(double x)
{
    return x * x;
}

int h = 0, p[20000];
char ss[2222222], s[2222222], ans[2222222];

int main (int argc, const char * argv[])
{
    int n, ans = 0, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        p[a]++;
    }
    for (int i = 1; i < 20000; i++)
    {
        if (p[i] == 0)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}