//
//  main.cpp
//  laconic princess
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

int n, a, b, sum = 0, mx, ans[111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> a >> b;
    if (a + b == 0)
    {
        for (int i = 0; i < n; i++) cout << 1 << " ";
        return 0;
    }
    if (a == 0 && b != 0)
    {
        ans[0] = 1;
        sum = 1;
        mx = 1;
        for (int i = 1; i < n; i++)
        {
            if (b == 0)
            {
                ans[i] = 1;
                continue;
            }
            --b;
            ans[i] = sum + 1;
            mx = max( mx, ans[i] );
            sum += sum + 1;
        }
        if (mx > 50000)
        {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        return 0;
    }
    if (a != 0 && b != 0)
    {
        ans[0] = 1;
        ans[1] = 2;
        sum = 3;
        mx = 2;
        --b;
        for (int i = 2; i < n; i++)
        {
            if (b != 0)
            {
                --b;
                ans[i] = sum + 1;
                mx = max( mx, ans[i] );
                sum += sum + 1;
                continue;
            }
            if (a != 0)
            {
                --a;
                ans[i] = mx + 1;
                sum += mx + 1;
                mx = max( mx, ans[i] );
                continue;
            }
            ans[i] = 1;
        }
        if (mx > 50000)
        {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        return 0;
    }
    if (a != 0 && b == 0)
    {
        if (a == n - 1)
        {
            cout << -1;
            return 0;
        }
        ans[0] = ans[1] = 1;
        for (int i = 2; i < n; i++)
        {
            if (a != 0)
            {
                ans[i] = ans[i - 1] + 1;
                --a;
                continue;
            }
            ans[i] = 1;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        return 0;
    }
    return 0;
}