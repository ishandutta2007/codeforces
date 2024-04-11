//
//  main.cpp
//  perm1
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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

int n, k, a[8][8], ans = 1000000000;
vector<int> pp, cur;
char st[8];

int make(int ii)
{
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res *= 10;
        res += a[ii][ pp[i] ];
    }
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k; gets( st );
    for (int i = 0; i < k; i++) pp.pb( i );
    for (int i = 0; i < n; i++)
    {
        gets( st );
        for (int j = 0; j < k; j++) a[i][j] = st[j] - '0';
    }
    do 
    {
        cur.clear();
        for (int i = 0; i < n; i++) cur.pb( make( i ) );
        sort( cur.begin(), cur.end() );
        ans = min(ans, cur.back() - cur.front());
    } while ( next_permutation(pp.begin(), pp.end()) ); 
    cout << ans;
    return 0;
}