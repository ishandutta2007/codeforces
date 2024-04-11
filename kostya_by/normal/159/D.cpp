//
//  main.cpp
//  taskD
//
//  Created by Sokol Kostya's MacBook on 09.03.11.
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

int ff[2222][2222], n;
long long ed[2222], pref[2222], ans = 0;
string s;

int fun(int ii, int jj)
{
    if (ff[ii][jj] != -1) return ff[ii][jj];
    if (ii == jj)
    {
        ff[ii][jj] = 1;
        ed[jj]++;
        return 1;
    }
    if (ii + 1 == jj)
    {
        int res = 0;
        if (s[ii] == s[jj]) res = 1;
        ff[ii][jj] = res;
        ed[jj] += res;
        return res;
    }
    int res = 1;
    if (fun(ii + 1, jj - 1) == 0) res = 0;
    if (s[ii] != s[jj]) res = 0;
    ff[ii][jj] = res;
    ed[jj] += res;
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 0; i < 2222; i++)
        for (int j = 0; j < 2222; j++)
            ff[i][j] = -1;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            fun(i, j);
    pref[0] = ed[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + ed[i];
    for (int i = 1; i < n; i++)
        for (int j = i; j < n; j++)
            if (ff[i][j] == 1) ans += pref[i - 1];
    cout << ans;
    return 0;
}