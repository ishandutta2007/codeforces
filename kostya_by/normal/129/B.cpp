//
//  main.cpp
//  shoelaces
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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

int n, m, ans = 0;
vector<int> graf[111], cur;
bool used[111]; 

int check(int v)
{
    int res = 0;
    for (int i = 0; i < graf[v].size(); i++) if (used[ graf[v][i] ] == false) ++res;
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    for (;;)
    {
        cur.clear();
        for (int i = 0; i < n; i++)
        {
            if (used[i] == true) continue;
            if (check(i) == 1) cur.pb( i );
        }
        if (cur.size() == 0) break;
        ++ans;
        for (int i = 0; i < cur.size(); i++) used[ cur[i] ] = true;
    }
    cout << ans;
    return 0;
}