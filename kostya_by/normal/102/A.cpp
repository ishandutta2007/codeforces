//
//  main.cpp
//  clothes
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

int n, a[111], m, ans = 1000000000;
bool ok[111][111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        ok[a][b] = ok[b][a] = true;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
            {
                int check = ok[i][j] + ok[j][k] + ok[i][k];
                if (check != 3) continue;
                ans = min(ans, a[i] + a[j] + a[k]);
            }
    if (ans == 1000000000) ans = -1;
    cout << ans;
    return 0;
}