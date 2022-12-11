//
//  main.cpp
//  series of crimes
//
//  Created by Sokol Kostya's MacBook on 13.05.11.
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

int n, m;
vector< pair<int, int> > pp;
char st[111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m; gets( st );
    for (int i = 1; i <= n; i++)
    {
        gets( st );
        for (int j = 1; j <= m; j++) if (st[j - 1] == '*') pp.pb( mp( i, j ) );
    }
    cout << (pp[0].first ^ pp[1].first ^ pp[2].first) << " " << (pp[0].second ^ pp[1].second ^ pp[2].second) << endl;
    return 0;
}