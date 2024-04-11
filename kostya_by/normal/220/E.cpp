//
//  main.cpp
//  elephant_and_inv
//
//  Created by Sokol Kostya's MacBook on 12.09.11.
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

struct summator
{
    int a[ 111111 ];
    summator()
    {
        clear();
    }
    void clear()
    {
        for ( int i = 0; i < 111111; i++ ) a[i] = 0;
    }
    void modify( int pos, int val )
    {
        while ( pos < 111111 )
        {
            a[pos] += val;
            pos = 2 * pos - ( pos & (pos - 1) );
        }
    }
    int fsum( int pos )
    {
        int res = 0;
        while ( pos != 0 )
        {
            res += a[pos];
            pos = pos & (pos - 1);
        }
        return res;
    }
};

int n, a[ 111111 ], b[ 111111 ], ll, rr;
long long k, num = 0, ans = 0;
map<int, int> mm;
summator s1, s2;

void compress()
{
    sort( b + 1, b + n + 1 );
    int id = 1;
    mm[ b[ 1 ] ] = id;
    for ( int i = 2; i <= n; i++ )
    {
        if ( b[i - 1] == b[i] ) continue;
        ++id;
        mm[ b[ i ] ] = id;
    }
    for ( int i = 1; i <= n; i++ ) a[i] = mm[ a[i] ];//, cout << a[i] << " "; cout << endl;
}

void inc_l()
{
    ++ll;
    num += s1.fsum( 100111 ) - s1.fsum( a[ ll ] );
    num += s2.fsum( a[ll] - 1 );
    s1.modify( a[ll], 1 );
}

void dec_l()
{
    num -= s1.fsum( 100111 ) - s1.fsum( a[ll] );
    num -= s2.fsum( a[ll] - 1 );
    s1.modify( a[ll], -1 );
    --ll;
}

void dec_r()
{
    --rr;
    num += s2.fsum( a[rr] - 1 );
    num += s1.fsum( 100111 ) - s1.fsum( a[rr] );
    s2.modify( a[rr], 1 );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]), b[i] = a[i];
    compress();
    
    ll = 0;
    rr = n + 1;
    
    dec_r();
    
    while ( ll + 1 < rr )
    {
        
        inc_l();
        if ( num > k )
        {
            dec_l();
            break;
        }
    }
    
    if ( ll == 0 )
    {
        cout << 0;
        return 0;
    }
    
    while ( rr != 1 )
    {
        //cout << ll << " " << rr << " " << num << endl;
        dec_r();
        ans += ll;
        if ( ll == rr ) dec_l(); 
        while ( num > k )
        {
            dec_l();
            if ( ll == 0 )
            {
                cout << ans;
                return 0;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}