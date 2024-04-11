//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 21.04.11.
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
const int cnt = 10;

using namespace std;

vector<int> dd;
int n;
long long ff[100000];

long long fun( int ii )
{
    if (ff[ii] != -1) return ff[ii];
    long long res = -5;
    for (int i = 1; i < ii; i++)
    {
        if (dd[ii] % dd[i] != 0) continue;
        int aa = dd[i];
        int bb = dd[ii] / dd[i];
        if (aa > bb) swap(aa, bb);
        res = max(res, fun( i ));
    }
    if (res == -5) res = 1;
    res += 1ll * dd[ii];
    ff[ii] = res;
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            dd.pb( i );
            if (i != (n / i) ) dd.pb( n / i );
        }
    }
    sort( dd.begin(), dd.end() );
    for (int i = 0; i < 100000; i++) ff[i] = -1;
    ff[0] = 1;
    cout << fun( dd.size() - 1 );
    
    return 0;
}