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

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n, nn, a[100][100];
   // bool used[100][100];
    cin >> n;
    nn = 2 * n + 1;
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        int ll = n + 1, rr = n + 1, val;
        if (i <= n + 1) val = i; else val = 2 * n + 1 - i + 1;
        while (val != 0)
        {
            a[i][ll] = a[i][rr] = val;
            --ll; ++rr;
            --val;
        }
    }
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        string out = "";
        for (int j = 1; j <= 2 * n + 1; j++) 
        {
            char ch;
            if (a[i][j] == 0) ch = ' '; else ch = '0' + a[i][j] - 1;
            out = out + ch + " ";
        }
        int ii = out.size();
        while (out[ii - 1] == ' ') --ii;
        for (int j = 0; j < ii; j++) cout << out[j]; 
        cout << endl;
    }
    return 0;
}