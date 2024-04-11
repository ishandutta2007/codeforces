//
//  main.cpp
//  cf140div2B
//
//  Created by Sokol Kostya's MacBook on 26.09.11.
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

int n, m, where[ 111111 ], bb;
long long ff, ss;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
    {
        int a;
        scanf("%d", &a);
        where[ a ] = i;
    }
    scanf("%d", &m);
    for ( int i = 1; i <= m; i++ )
    {
        scanf("%d", &bb);
        ff += where[ bb ];
        ss += n - where[ bb ] + 1;
    }
    cout << ff << " " << ss << endl;
    return 0;
}