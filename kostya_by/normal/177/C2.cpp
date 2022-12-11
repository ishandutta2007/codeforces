//
//  main.cpp
//  task3
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

vector< int > ff[2222];
bool ee[2222][2222];
int n, m, k, a, b, sum = 0;
int color = 1, c1[2222]; 
int num[2222];
bool used[2222];

void dfs(int v)
{
    if (c1[v] != 0) return;
    ++sum;
    c1[v] = color;
    for (int i = 0; i < ff[v].size(); i++) dfs( ff[v][i] );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        --a; --b;
        ff[a].pb( b );
        ff[b].pb( a );
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        --a; --b;
        ee[a][b] = ee[b][a] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if ( c1[i] == 0 ) 
        {
            sum = 0;
            dfs( i );
            num[ color ] = sum;
            color++;
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (ee[i][j] == false) continue;
            if (c1[i] != c1[j]) continue;
            used[ c1[i] ] = true;
        }
    
    for (int i = 0; i < 2222; i++) if (used[i] == false) ans = max(ans, num[i]);
    cout << ans;
    
    return 0;
}