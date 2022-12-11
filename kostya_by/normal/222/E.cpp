//
//  main.cpp
//  decrypt_genom
//
//  Created by Sokol Kostya's MacBook on 10.09.11.
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
const long long mm = 1000000007;

using namespace std;

int k, m, id[ 1111 ];
long long n;

struct matrix
{
    long long a[ 52 ][ 52 ];
    matrix()
    {
        for ( int i = 0; i < 52; i++ )
            for ( int j = 0; j < 52; j++ )
                a[i][j] = 0;
    }
};

matrix operator*( matrix a, matrix b )
{
    matrix res;
    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < m; j++ )
            for ( int k = 0; k < m; k++ )
            {
                res.a[i][j] += a.a[i][k] * b.a[k][j];
                res.a[i][j] %= mm;
            }
    return res;
}

matrix bin( matrix m, long long pp )
{
    if ( pp == 1 ) return m;
    if ( pp % 2 == 1 )
    {
        matrix res = m * bin(m, pp - 1);
        return res;
    }
    if ( pp % 2 == 0 )
    {
        matrix res = bin(m, pp / 2);
        return res * res;
    }
}

matrix start;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for ( int i = 'a'; i <= 'z'; i++ ) id[ i ] = i - 'a';
    for ( int i = 'A'; i <= 'Z'; i++ ) id[ i ] = i - 'A' + 26;
    cin >> n >> m >> k;
    if ( n == 1 )
    {
        cout << m;
        return 0;
    }
    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < m; j++ )
            start.a[i][j] = 1;
    for ( int i = 0; i < k; i++ )
    {
        string s;
        cin >> s;
        int fi = id[ s[0] ], se = id[ s[1] ];
        start.a[fi][se] = 0;
    }
    n--;
    matrix res = bin(start, n);
    long long ans = 0;
    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < m; j++ )
        {
            ans += res.a[i][j];
            ans %= mm;
        }
    cout << ans;
    return 0;
}