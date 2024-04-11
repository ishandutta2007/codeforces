//
//  main.cpp
//  cf139_easy
//
//  Created by Sokol Kostya's MacBook on 20.09.11.
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

long long n, ff[ 60 ];
int k;
vector< long long > ans;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ff[0] = 0;
    ff[1] = 1;
    cin >> n >> k;
    for ( int i = 2; i < 60; i++ )
    {
        for ( int j = 1; j <= k; j++ )
        {
            if ( i - j < 0 ) break;
            ff[i] += ff[i - j];
        }
        //cout << ff[i] << endl;
    }
    
    for ( int i = 59; i >= 0; i-- )
    {
        
        if ( ff[i] <= n )
        {
            ans.pb( ff[i] );
            n -= ff[i];
        }
        
    }
    
    cout << ans.size() << endl;
    for ( int i = 0; i < ans.size(); i++ ) cout << ans[i] << " ";
    
    return 0;
}