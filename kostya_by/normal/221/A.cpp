//
//  main.cpp
//  elephant and num
//
//  Created by Sokol Kostya's MacBook on 13.09.11.
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

int n, ans;

int fun( int x )
{
    int res = 0;
    while ( x != 0 )
    {
        res |= 1 << (x % 10);
        x /= 10;
    }
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    cout << n << " ";
    for ( int i = 1; i < n; i++ ) printf("%d ", i); 
    return 0;
}