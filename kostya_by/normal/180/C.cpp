//
//  main.cpp
//  letter
//
//  Created by Sokol Kostya's MacBook on 22.04.11.
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

char st[111111];
int ans = 1111111, n, pref1[111111], pref2[111111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st );
    n = int( strlen( st ) );
    for (int i = 0; i < n; i++)
    {
        int nn = st[i] - 'a';
        pref1[i + 1] = pref1[i];
        pref2[i + 1] = pref2[i];
        if (nn >= 0 && nn <= 25)
        {
            pref1[i + 1]++;
        } else pref2[i + 1]++;
    }
    
    ans = n - pref1[ n ];
    ans = min( ans, n - pref2[ n ] );
    
    for (int i = 1; i < n; i++)
    {
        int pen1 = pref1[i];
        int pen2 = pref2[n] - pref2[i];
        ans = min( ans, pen1 + pen2 );
    }
    
    cout << ans;
    
    return 0;
}