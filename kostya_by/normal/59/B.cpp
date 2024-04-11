//
//  main.cpp
//  fortune telling
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

int n, a[111], sum = 0, mn = -1;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        if (a[i] % 2 == 1)
        {
            if (mn == -1) mn = a[i];
            mn = min(mn, a[i]);
        }
    }
    if (sum % 2 == 1) 
    {
        cout << sum;
        return 0;
    }
    if (mn == -1) cout << 0; else cout << sum - mn;
    return 0;
}