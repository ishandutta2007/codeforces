//
//  main.cpp
//  task3
//
//  Created by Sokol Kostya's MacBook on 13.01.11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
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

/*
int a[ 1111 ][ 1111 ];

int fun( int m )
{
    for ( int i = 1; i <= m; i++ ) a[1][i] = 0;
    a[1][m + 1] = 1;
    for ( int i = 2; i <= m + 1; i++ )
        for ( int j = 1; j <= m + 1; j++ )
            if ( j == 1 ) 
            {
                a[i][j] = a[i - 1][j + 1];
            } else if ( j == m + 1 )
            {
                a[i][j] = a[i - 1][j - 1];
            } else a[i][j] = a[i - 1][j - 1] ^ a[i - 1][j + 1];
    int sum = 0;
    for ( int i = 1; i <= m + 1; i++ ) sum += a[m + 1][i];
    return sum;
}*/

long long n, t;
long long f[ 70 ][ 70 ][ 2 ], a[ 70 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    /*for ( int i = 1; i <= 500; i++ )
    {
        cout << i << " " << fun( i ) << " " << __builtin_popcount(i + 1) << endl;
    }*/
    cin >> n >> t;
    long long pt = 1, val = 0;
    while ( pt < t ) pt *= 2, val++;
    if ( pt != t )
    {
        cout << 0;
        return 0;
    }
    n++;
    
    for ( int i = 0; i < 70; i++ ) a[i] = n % 2, n /= 2;
    reverse( a, a + 70 );
    //for ( int i = 0; i < 70; i++ ) cout << a[i]; cout << endl;
    
    f[0][0][0] = 1;
    for ( int i = 0; i < 69; i++ )
        for ( int j = 0; j < 69; j++ )
            for ( int k = 0; k < 2; k++ )
            {
                if ( f[i][j][k] == 0 ) continue;
                int aa = (int) a[i + 1];
                for ( int next = 0; next < 2; next++ )
                {
                    int ii = i + 1;
                    int jj = j + next;
                    int kk = k;
                    if ( k == 1 ) f[ii][jj][kk] += f[i][j][k];
                    if ( k == 0 )
                    {
                        if ( aa == 0 && next == 1 ) continue;
                        if ( aa == 1 && next == 0 ) kk = 1;
                        f[ii][jj][kk] += f[i][j][k];
                    }
                }
            }
    long long ans = f[69][val + 1][0] + f[69][val + 1][1];
    if ( val == 0 ) ans--;
    cout << ans << endl;
    
    return 0;
}