//
//  main.cpp
//  room leader
//
//  Created by Sokol Kostya's MacBook on 28.04.11.
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

vector< pair<int, string> > pp;
string st;
int n, a, b, c, d, e, pl, mn;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> st >> pl >> mn >> a >> b >> c >> d >> e;
        pp.pb( mp( pl * 100 - mn * 50 + a + b + c + d + e, st ) );
    }
    sort( pp.begin(), pp.end() );
    cout << pp.back().second;
    return 0;
}