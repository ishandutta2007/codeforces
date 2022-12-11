//
//  main.cpp
//  lenta
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

int n, a, b, c, ans = -1;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> a >> b >> c;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            if (a * i + b * j > n) break;
            int k = n - (a * i + b * j);
            if (k % c != 0) continue;
            ans = max(ans, i + j + k / c);
        }
    cout << ans;
    return 0;
}