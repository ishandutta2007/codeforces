//
//  main.cpp
//  given a string
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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

int ans = 0, n;
string st;

int check(int i, int j)
{
    int res = 0;
    int len = j - i + 1;
    for (int k = 0; k < n; k++)
    {
        if (k + len - 1 == n) break;
        bool fl = true;
        for (int l = 0; l < len; l++) if (st[k + l] != st[i + l]) fl = false;
        res += fl;
    }
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> st;
    n = st.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            if (check(i, j) > 1) ans = max( ans, j - i + 1 );
        }
    cout << ans;
    return 0;
}