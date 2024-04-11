//
//  main.cpp
//  rating
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

int mx[222], a[222][222], n, m, ans = 0;
string st;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> st;
        for (int j = 0; j < m; j++) 
        {
            a[i][j] = st[j] - '0';
            mx[j] = max( mx[j], a[i][j] );
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool fl = false;
        for (int j = 0; j < m; j++) if (a[i][j] == mx[j]) fl = true;
        ans += fl;
    }
    cout << ans;
    return 0;
}