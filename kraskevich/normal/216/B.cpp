#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;

int e[100][100];
int cnt;
vector<bool> u;
bool cycle=false;
int n;

void dfs(int v, int par)
{
    cnt++;
    u[v]=true;
    for(int i=0;i<n;++i)
    {
        if(e[v][i]&&u[i]&&i!=par)
            cycle=true;
        if(!u[i]&&e[v][i])
            dfs(i, v);
    }
}
    

int main()
{
    ios_base::sync_with_stdio(0);
    
    int m;
    cin>>n>>m;
    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            e[i][j]=false;
    
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        e[a][b]=e[b][a]=1;
    }
    
    u.assign(n, false);
    int all=0,l=0,r=0;
    
    for(int i=0;i<n;++i)
    {
        if(u[i])
            continue;
        cnt=0;
        cycle=false;
        dfs(i, -1);
        if(!cycle)
            all+=cnt;
        else
            l+=cnt/2, r+=cnt/2;
    }
    
    if(l<r)
        l+=all/2+all%2, r+=all/2;
    else
        l+=all/2,r+=all/2+all%2;
    
    cout << n-min(l,r)*2;
    
    return 0;
}