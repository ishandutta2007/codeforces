//
//  main.cpp
//  task1
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

using namespace std;

int a[111][111], n, ans = 0;
bool used[111][111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++) used[i][i] = true;
    int ii = n - 1;
    int jj = 0;
    while (jj < n)
    {
        used[ii][jj] = true;
        --ii;
        ++jj;
    }
    for (int i = 0; i < n; i++) used[ n / 2 ][ i ] = used[ i ][ n / 2 ] = true;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) if (used[i][j] == true) ans += a[i][j];
    }
    
    cout << ans;
    
    return 0;
}