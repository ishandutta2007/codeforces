//
//  main.cpp
//  cf142_div2
//
//  Created by Sokol Kostya's MacBook on 01.10.11.
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

bool prime[ 1111111 ];
set< long long > good;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    prime[0] = prime[1] = true;
    for ( int i = 2; i * i < 1111111; i++ )
    {
        if ( prime[i] == true ) continue;
        int cur = i * i;
        while ( cur < 1111111 ) prime[cur] = true, cur += i;
    }
    for ( int i = 1; i < 1111111; i++ )
    {
        if ( prime[i] == false )
        {
            long long a = i;
            a *= a;
            good.insert( a );
        }
    }
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        long long a;
        cin >> a;
        if ( good.find( a ) != good.end() ) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    return 0;
}