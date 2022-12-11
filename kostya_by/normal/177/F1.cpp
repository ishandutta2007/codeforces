//
//  main.cpp
//  task6
//
//  Created by Sokol Kostya's MacBook on 21.04.11.
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

int n, k, t, cur = 0;
int a1[100], a2[100], a3[100];
bool used1[5], used2[5];
vector<int> res;

void rec(int pos)
{
    if (pos == k)
    {
        res.pb( cur );
    }
    if (pos < k)
    {
        rec(pos + 1);
        if ( used1[ a1[pos] ] == false && used2[ a2[pos] ] == false )
        {
            used1[ a1[pos] ] = used2[ a2[pos] ] = true;
            cur += a3[pos];
            rec(pos + 1);
            cur -= a3[pos];
            used1[ a1[pos] ] = used2[ a2[pos] ] = false;
        }
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k >> t;
    for (int i = 0; i < k; i++)
    {
        cin >> a1[i] >> a2[i] >> a3[i];
        --a1[i]; --a2[i];
    }
    rec(0);
    sort( res.begin(), res.end() );
    cout << res[ t - 1 ];
    return 0;
}