//
//  main.cpp
//  discounts
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

vector< pair<int, int> > pen, tab;
vector< int > carts[1111];
bool dd[1111];
int n, k, c[1111], t[1111], ii = -1;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> t[i];
        c[i] *= 2;
        if (t[i] == 1) tab.pb( mp( c[i], i ) ); else pen.pb( mp( c[i], i ) );
    }
    sort( tab.begin(), tab.end(), greater< pair<int, int> >() );
    for (int i = 0; i < tab.size(); i++)
    {
        ii = i;
        dd[i] = true;
        if (i == k - 1)
        {
            for (int j = i; j < tab.size(); j++) carts[ i ].pb( tab[j].second );
            break;
        }
        carts[ i ].pb( tab[i].second );
    }
    if (ii == k - 1)
    {
        for (int i = 0; i < pen.size(); i++) carts[ ii ].pb( pen[i].second );
    } else 
    {
        ++ii;
        for (int i = 0; i < pen.size(); i++)
        {
            if (ii == k - 1)
            {
                for (int j = i; j < pen.size(); j++) carts[ ii ].pb( pen[j].second );
                break;
            }
            carts[ ii ].pb( pen[i].second );
            ++ii;
        }
    }
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (dd[i] == true)
        {
            int mn = 2000000000;
            for (int j = 0; j < carts[i].size(); j++) if ( c[ carts[i][j] ] < mn ) mn = c[ carts[i][j] ];
            mn /= 2;
            ans -= mn;
        }
        for (int j = 0; j < carts[i].size(); j++) ans += 1ll * c[ carts[i][j] ];
    }
    cout << ans / 2 << ".";
    if (ans % 2 == 1) cout << 5; else cout << 0; cout << endl;
    for (int i = 0; i < k; i++)
    {
        cout << carts[i].size() << " "; 
        for (int j = 0; j < carts[i].size(); j++) cout << carts[i][j] + 1 << " ";
        cout << endl;
    }
    return 0;
}