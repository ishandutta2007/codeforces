//
//  main.cpp
//  alice bob chocolate
//
//  Created by Sokol Kostya's MacBook on 13.05.11.
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
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, t[111111], f1[111111], f2[111111], a, b;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    f1[0] = 0;
    for (int i = 1; i < n; i++) f1[i] = f1[i - 1] + t[i - 1];
    f2[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) f2[i] = f2[i + 1] + t[i + 1];
    for (int i = 0; i < n; i++)
    {
        if (f1[i] <= f2[i]) ++a; else ++b;
    }
    cout << a << " " << b << endl;
    return 0;
}