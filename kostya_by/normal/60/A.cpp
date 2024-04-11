//
//  main.cpp
//  flakes
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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

string s1, s2;
int x, ll, rr, l, r, n, m;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    ll = 1;
    rr = n;
    for (int i = 0; i < m; i++)
    {
        cin >> s1 >> s1 >> s2 >> s1 >> x;
        if (s2 == "left")
        {
            l = 1;
            r = x - 1;
        }
        if (s2 == "right")
        {
            l = x + 1;
            r = n;
        }
        ll = max(ll, l);
        rr = min(rr, r);
    }
    if (ll > rr) cout << -1; else cout << rr - ll + 1;
    return 0;
}