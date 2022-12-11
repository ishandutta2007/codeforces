//
//  main.cpp
//  playlist_cf
//
//  Created by Sokol Kostya's MacBook on 28.01.11.
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

struct tman
{
    int l;
    long double p;
    tman() : l( 0 ), p( 0 ) {};
    tman( int l, double p ) : l( l ), p( p ) {};
};

int n;
long double ans = 0.0;
tman man[ 50500 ];

bool cmp( tman m1, tman m2 )
{
    if ( m1.l * m1.p * ( 1.0 - m2.p ) > m2.l * m2.p * ( 1.0 - m1.p ) ) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
    {   
        int l;
        double p;
        scanf("%d%lf", &l, &p);
        p *= 0.01;
        ans += 1.0 * l;
        man[i] = tman( l, p );
    }
    
    sort( man, man + n, cmp );
    
    long double cur = 0.0;
    for ( int i = 0; i < n; i++ )
    {
        ans += cur * ( 1.0 - man[i].p );
        cur += man[i].p * man[i].l;
    }
    cout << fixed << setprecision( 10 ) << ans << endl;
    return 0;
}