//
//  main.cpp
//  mapOFroads
//
//  Created by Sokol Kostya's MacBook on 22.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 5 * 10000 + 100;

vector<int> edge[maxn];

int ans[maxn];
bool used[maxn];

void dfs(int v, int prev);

void dfs(int v, int prev)
{
    used[v] = true;
    ans[v] = prev;
    for (int i = 0; i < edge[v].size(); i++)
    {
        if (not used[edge[v][i]]) dfs(edge[v][i], v);
    }
}

int main (int argc, const char * argv[])
{
    int n, r1, r2;
    scanf("%d%d%d",&n,&r1,&r2);
    for (int i = 0; i < n; i++)
    {
        if (i == r1 - 1) continue;
        int v1 = i, v2;
        scanf("%d",&v2);
        --v2;
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
    dfs(r2 - 1,-1);
    for (int i = 0; i < n; i++)
        if (i != r2 - 1) printf("%d ",ans[i] + 1);
    return 0;
}