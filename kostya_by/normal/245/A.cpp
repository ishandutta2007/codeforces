//
//  main.cpp
//  admin_cf
//
//  Created by Sokol Kostya's MacBook on 19.11.11.
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

int aa[ 3 ], bb[ 3 ], n, t, a, b;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cin >> t >> a >> b;
        aa[t] += a;
        bb[t] += b;
    }
    for ( int i = 1; i <= 2; i++ ) if ( aa[i] >= bb[i] ) cout << "LIVE\n"; else cout << "DEAD\n";
    return 0;
}