//
//  main.cpp
//  find_pair
//
//  Created by Sokol Kostya's MacBook on 10.03.11.
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

int a[111111], n;
long long k, cur = 0, nn;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    nn = n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    a[n] = 2000000000;
    int h = 0, t = 0;
    long long hh, tt;
    while (h != n)
    {
        while (a[h] == a[t]) ++t;
        --t;
        hh = h; tt = t;
        //cout << cur << " " << tt << " " << hh << endl;
        if (cur + (tt - hh + 1) * nn < k)
        {
            cur += (tt - hh + 1) * nn;
            h = t + 1;
            t = h;
            continue;
        }
        long long id = (k - cur) / (tt - hh + 1); 
        if ((k - cur) % (tt - hh + 1) == 0) --id; 
        cout << a[h] << " " << a[ id ];
        return 0;
    }
    return 0;
}