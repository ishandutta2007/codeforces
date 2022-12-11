//
//  main.cpp
//  task4
//
//  Created by Sokol Kostya's MacBook on 11.03.11.
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
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

vector<int> graf[55555];
int n, a, b, gg[50005][505], ff[50005][505], k;
long long ans = 0, now;

void dfs(int v, int prev)
{
    gg[v][0] = 1;
    for (int i = 0; i < graf[v].size(); i++)
    {
        int next = graf[v][i];
        if (next == prev) continue;
        dfs(next, v);
        for (int j = 1; j <= k; j++) gg[v][j] += gg[next][j - 1];
    }
};

void rec(int v, int prev)
{
    now = ff[v][k] + gg[v][k];
    ans += now;
    for (int i = 0; i < graf[v].size(); i++)
    {
        int next = graf[v][i];
        if (next == prev) continue;
        for (int j = 2; j <= k; j++) ff[next][j] = ff[v][j - 1] + gg[v][j - 1] - gg[next][j - 2];
        ff[next][1] = 1;
        rec( next, v );
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &a, &b);
        --a; --b;
        graf[a].pb( b );
        graf[b].pb( a );
    }
    dfs(0, -1);
    rec(0, -1);
   /* for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= k; j++) cout << ff[i][j] << " ";
        cout << endl;
    }*/
    cout << ans / 2;
    return 0;
}