//
//  main.cpp
//  electro
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

int n, p1, p2, p3, t1, t2, l[111], r[111], ans = 0;
int tp[2222];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    for (int i = 0; i < 2222; i++) tp[i] = 3;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j < r[i] + t1; j++) tp[j] = 1;
        for (int j = r[i] + t1; j < r[i] + t1 + t2; j++) tp[j] = 2;
    }
    for (int i = l[0]; i <= r[n - 1]; i++)
    {
        if (tp[i] == 1) ans += p1;
        if (tp[i] == 2) ans += p2;
        if (tp[i] == 3) ans += p3;
    }
    cout << ans - p1;
    return 0;
}