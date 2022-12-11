//
//  main.cpp
//  lucky_tickets_cf
//
//  Created by Sokol Kostya's MacBook on 08.09.11.
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

map< pair<int, int>, int > aa, bb;
pair< int, int > a[ 100001 ], b[ 100001 ];
int xmax, ymax, w;
long long xx, yy, xans, yans;
long long cur = 0;

int gcd(int a, int b)
{
    if ( a != 0 ) return gcd( b % a, a ); else return b;  
}

int rev( int x )
{
    int res = 0;
    for ( ; x > 0; )
    {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> xmax >> ymax >> w;
    xx = xmax;
    yy = ymax;
    
    for ( int i = 1; i <= xmax; i++ )
    {
        int gg = gcd( i, rev(i) );
        pair< int, int > pii( i / gg, rev(i) / gg );
        a[i] = pii;
    }
    for ( int i = 1; i <= ymax; i++ )
    {
        int gg = gcd( i, rev(i) );
        pair< int, int > pii( rev(i) / gg, i / gg );
        b[i] = pii;
    }
    
    for ( int i = 1; i <= xmax; i++ )
    {
        aa[ a[i] ]++;
        yy = i;
    }
    for ( int i = 1; i <= ymax; i++ )
    {
        bb[ b[i] ]++;
        cur += aa[ b[i] ];
        yy = i;
        if ( cur >= w ) break;
    }
    
    if ( cur < w )
    {
        cout << -1;
        return 0;
    }

    xans = xx, yans = yy;
    
    while ( xx > 1 )
    {
        
        cur -= bb[ a[xx] ];
        aa[ a[xx] ]--;
        --xx;
        while ( cur < w )
        {
            if ( yy == ymax ) break;
            ++yy;
            cur += aa[ b[yy] ];
            bb[ b[yy] ]++;
        }
        if ( cur < w ) break;
        //cout << xx << " " << yy << " " << cur << endl;
        if ( xx * yy < xans * yans ) xans = xx, yans = yy;
    }
    
    cout << xans << " " << yans;
    
    return 0;
}