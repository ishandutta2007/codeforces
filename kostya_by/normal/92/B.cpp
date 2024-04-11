//
//  main.cpp
//  binary
//
//  Created by Sokol Kostya's MacBook on 03.05.11.
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

int a[1111111], ans = 0, n;
char st[1111111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st );
    n = strlen( st );
    for (int i = 0; i < n; i++) a[i] = st[i] - '0';
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            ans += a[0] / 2;
            break;
        }
        a[i - 1] += a[i] / 2;
        a[i] %= 2;
        if (a[i] == 1)
        {
            ans += 2;
            a[i - 1]++;
            continue;
        }
        ans++;
    }
    cout << ans;
    return 0;
}