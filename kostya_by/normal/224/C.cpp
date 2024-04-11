//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 16.09.11.
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

vector< int > st;
char s[ 111111 ];
int n, ff[ 111111 ], pp[ 111111 ], gg[ 111111 ], fun[ 111111 ], best = 0, l = 0, r = -1;

int sum(int l, int r)
{
    if ( l == 0 ) return pp[r];
    return pp[r] - pp[l - 1];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s );
    n = strlen( s );
    for ( int i = 0; i < n; i++ )
    {
        if ( s[i] == '(' || s[i] == '[' )
        {
            if ( s[i] == '[' ) pp[i] = 1; 
            st.pb( i );
            continue;
        }
        if ( s[i] == ')' )
        {
            if ( st.size() == 0 || s[ st.back() ] != '(' )
            {
                ff[i] = -1111;
                st.clear();
                continue;
            }
            ff[ i ] = st.back();
            st.pop_back();
            continue;
        }
        if ( s[i] == ']' )
        {
            if ( st.size() == 0 || s[ st.back() ] != '[' )
            {
                ff[i] = -1111;
                st.clear();
                continue;
            }
            ff[ i ] = st.back();
            st.pop_back();
            continue;
        }
    }
    
    for ( int i = 1; i < n; i++ ) pp[i] += pp[i - 1];
    
    for ( int i = 1; i < n; i++ )
    {
        
        if ( s[i] == ')' || s[i] == ']' )
        {
            if ( ff[i] == -1111 ) continue;
            int val = sum( ff[i], i );
            int pos = ff[i] - 1;
            gg[i] = ff[i];
            fun[i] = val;
            if ( pos != -1 )
            {
                
                if ( ( s[ pos ] == ')' || s[ pos ] == ']' ) && ff[pos] != -1111 )
                {
                    gg[i] = gg[pos];
                    fun[i] += fun[pos];
                }
            }
            
            if ( fun[i] >= best )
            {
                best = fun[i];
                l = gg[i];
                r = i;
            }
            //cout << i << " " << ff[i] << endl;
        }
        
    }
    
    cout << best << endl;
    for ( int i = l; i <= r; i++ ) putchar( s[i] );
    
    return 0;
}