//
//  main.cpp
//  interesting game_cf_73
//
//  Created by Sokol Kostya's MacBook on 02.10.11.
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

int ff[ 111111 ], n, last[ 1111111 ], pref[ 111111 ], mn[ 111111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        bool fl = false;
        mn[i] = 1000000000;
        for ( int x = 2; x <= i ;x++ )
        {
            int sum = x * (x + 1) / 2;
            if ( sum > i ) break;
            long long ch = (long long)2 * i + x * x - x;
            long long zn = 2 * x;
            //cout << i << " " << x << " " << ch / zn << endl;
            if ( (ch / zn) > i ) break;
            if ( ch % zn != 0 ) continue;
            long long r = ch / zn;
            long long l = r - x + 1;
            if ( l <= 0 ) continue;
            fl = true;
            last[ pref[r] ^ pref[l - 1] ] = i;
            if ( (pref[r] ^ pref[l - 1]) == 0 ) mn[i] = min( x, mn[i] );
        }
        if ( fl == false ) ff[i] = 0; else
        {
            for ( int j = 0;;j++ )
            {
                if ( last[j] == i ) continue;
                ff[i] = j;
                break;
            }
        }
        pref[i] = pref[i - 1] ^ ff[i];
        //cout << i << " " << ff[i] << " " << mn[i] << endl;
    }
    if ( ff[n] == 0 )
    {
        cout << -1;
        return 0;
    }
    cout << mn[n];
    return 0;
}