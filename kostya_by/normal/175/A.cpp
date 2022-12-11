//
//  main.cpp
//  Robot Bicorn Attack
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

string st, fi, se, th;
int ans = -1;

int fun(string s)
{
    if (s.size() > 7) return -1;
    if (s == "0") return 0;
    if (s[0] == '0') return -1;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res *= 10;
        res += s[i] - '0';
    }
    if (res <= 1000000) return res; else return -1;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> st;
    for (int i = 1; i < st.size(); i++)
        for (int j = i + 1; j < st.size(); j++)
        {
            fi = se = th = "";
            for (int k = 0; k < i; k++) fi = fi + st[k];
            for (int k = i; k < j; k++) se = se + st[k];
            for (int k = j; k < st.size(); k++) th = th + st[k];
            int a = fun(fi);
            int b = fun(se);
            int c = fun(th);
            int mn = min(a, min(b, c));
            if (mn == -1) continue;
            ans = max(ans, a + b + c);
        }
    cout << ans;
    return 0;
}