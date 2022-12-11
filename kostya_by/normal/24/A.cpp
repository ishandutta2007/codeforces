//
//  main.cpp
//  vlad_kolco
//
//  Created by Sokol Kostya's MacBook on 10.07.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>



using namespace std;

vector<int> g[1000];
vector<int> g1[1000];
int len[1000][1000];
int used[1000];
int p[1000];
int cost=0;
bool flag=false;

void dfs(int v)
{
    used[v]=1;
    for(int i=0;i<g1[v].size();i++)
    {
        if(used[g1[v][i]]==0)
        {
            cost+=len[v][g1[v][i]];
           // cout << v << " -> " << g1[v][i] << " " << len[v][g1[v][i]] << endl;
            p[ g1[v][i] ]=v;
            dfs(g1[v][i]);
            continue;
            
        }
        if ( p[v] == -1 ) continue;
        if(used[g1[v][i]]==1 && p[v]!=g1[v][i])
        {
            cost+=len[v][g1[v][i]];
           // cout << v << " -> " << g1[v][i] << " " << len[v][g1[v][i]] << endl;        
        }
        
    }
    
    
    
}

int main()
{
    int n,a,b,c;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        g1[a-1].push_back(b-1);
        g1[b-1].push_back(a-1);
        len[a-1][b-1]=c;
        sum+=c;
    }
    for(int i=0;i<1000;i++)
        p[i]=-1;
    
    dfs(0);
    if(sum-cost<cost)
        cost=sum-cost;
    
    cout<<cost;
    return 0;
}