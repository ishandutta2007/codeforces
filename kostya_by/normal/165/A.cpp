//
//  main.cpp
//  supercentral_point
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

bool cur[4];
int x[222], y[222], n, ans = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        cur[0] = cur[1] = cur[2] = cur[3] = false;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (x[i] == x[j])
            {
                if (y[i] < y[j]) cur[0] = true;
                if (y[i] > y[j]) cur[1] = true;
            }
            if (y[i] == y[j])
            {
                if (x[i] < x[j]) cur[2] = true;
                if (x[i] > x[j]) cur[3] = true;
            }
        }
        bool res = cur[0] && cur[1] && cur[2] && cur[3];
        ans += res;
    }
    cout << ans;
    return 0;
}