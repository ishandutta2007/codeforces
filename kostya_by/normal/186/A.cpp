//
//  main.cpp
//  comparing strings
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

char s1[111111], s2[111111];
vector<int> pp;
int n, m;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s1 ); gets( s2 );
    n = int( strlen( s1 ) );
    m = int( strlen( s2 ) );
    if (n != m)
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; i++) if (s1[i] != s2[i]) pp.pb( i );
    if (pp.size() != 2)
    {
        cout << "NO";
        return 0;
    }
    swap( s1[ pp[0] ], s1[ pp[1] ] );
    for (int i = 0; i < n; i++) if (s1[i] != s2[i])
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}