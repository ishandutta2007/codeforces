//
//  main.cpp
//  combination
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

pair<int, int> pp[1111];
int n, ans, cur = 1;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first > p2.first) return true;
    if (p1.first == p2.first && p1.second > p2.second) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pp[i].second >> pp[i].first;
    sort( pp, pp + n, cmp );
    for (int i = 0; i < n; i++)
    {
        if (cur == 0) break;
        ans += pp[i].second;
        cur += pp[i].first - 1;
    }
    cout << ans;
    return 0;
}