//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 24.09.11.
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

long long a[ 111111 ], pref[ 111111 ], ans[ 111111 ];
int n, m;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        int aa;
        scanf("%d", &aa);
        a[i] = aa;
    }
    cin >> m;
    sort( a + 1, a + n + 1 );
    pref[0] = 0;
    for ( int i = 0; i < 111111; i++ ) ans[i] = -1;
    for ( int i = 1; i <= n; i++ ) pref[i] = pref[i - 1] + a[i];
    for ( int q = 0; q < m; q++ )
    {
        int k;
        scanf("%d", &k);
        long long kk = k;
        if ( ans[k] != -1 )
        {
            printf("%I64d ", ans[k]);
            //cout << ans[k] << " ";
            continue;
        }
        ans[k] = 0;
        long long rr = n - 1; long long ll = rr - k + 1;
        while ( true )
        {
            if ( rr < 1 ) break;
            if ( ll < 1 ) ll = 1;
            ans[k] += pref[ rr ];
            long long nn = (rr - ll + 1);
            nn *= kk;
            rr = ll - 1;
            ll = rr - nn + 1;
        }
        printf("%I64d ", ans[k]);
        //cout << ans[k] << " ";
    }
    return 0;
}