//
//  main.cpp
//  broken permutation
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

int n, a[1111], xx = 0, yy = 0, ll, rr;

int main (int argc, const char * argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll = 1; rr = n;
    while (a[ll] == ll)
    {
        ++ll;
        if (ll == n + 1) 
        {
            cout << "0 0";
            return 0;
        }
    }
    while (a[rr] == rr)
    {
        --rr;
    }
    for (int i = rr, cnt = 0; i >= ll; i--, cnt++)
    {
        //cout << a[i] << " " << ll + cnt << endl;
        if (a[i] == ll + cnt) continue;
        cout << "0 0";
        return 0;
    }
    cout << ll << " " << rr << endl;
    return 0;
}