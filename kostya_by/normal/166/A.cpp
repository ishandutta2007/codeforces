//
//  main.cpp
//  ranklist
//
//  Created by Sokol Kostya's MacBook on 28.04.11.
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

int n, k, ll, rr;
vector< pair<int, int> > pp;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first > p2.first) return true;
    if (p1.first == p2.first && p1.second < p2.second) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pp.pb( mp(a, b) );
    }
    sort( pp.begin(), pp.end(), cmp );
    --k;
    ll = rr = k;
    while (true)
    {
        if (ll == 0) break;
        if (pp[ll - 1] != pp[k]) break;
        --ll;
    }
    while (true)
    {
        if (rr == n - 1) break;
        if (pp[rr + 1] != pp[k]) break;
        ++rr;
    }
    cout << rr - ll + 1;
    return 0;
}