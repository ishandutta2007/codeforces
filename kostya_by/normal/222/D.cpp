//
//  main.cpp
//  olympiad
//
//  Created by Sokol Kostya's MacBook on 10.09.11.
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

vector<int> a, b;
int n, x, ans = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &x);
    for ( int i = 0; i < n; i++ )
    {
        int aa;
        scanf("%d", &aa);
        a.pb( aa );
    }
    for ( int i = 0; i < n; i++ )
    {
        int aa;
        scanf("%d", &aa);
        b.pb( aa );
    }
    sort( a.begin(), a.end(), greater<int>() );
    sort( b.begin(), b.end(), greater<int>() );
    for (int i = 0; i < a.size(); i++)
    {
        
        while ( b.size() > 0 )
        {
            if ( b.back() + a[i] >= x ) break;
            b.pop_back();
        }
        if ( b.size() == 0 ) continue;
        b.pop_back();
        ++ans;
    }
    cout << "1 " << ans << endl;
    return 0;
}