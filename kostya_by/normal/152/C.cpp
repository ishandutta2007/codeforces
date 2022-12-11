//
//  main.cpp
//  notebook
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
const long long mod = 1000000007;

using namespace std;

int n, m;
long long ans = 1;
string ss[111];
set< char > sst;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> ss[i];
    for (int j = 0; j < m; j++)
    {
        sst.clear();
        for (int i = 0; i < n; i++) sst.insert( ss[i][j] );
        long long cur = sst.size();
        ans *= cur;
        ans %= mod;
    }
    cout << ans;
    return 0;
}