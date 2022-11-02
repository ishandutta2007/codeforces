#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int N=400*1000;
vector<int> g[N];
int col[N], deg[N];

void solve()
{
    fill(col,col+N,0);
    fill(deg,deg+N,0);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[--a].push_back(--b);
        g[b].push_back(a);
        ++deg[a];
        ++deg[b];
    }
    set<int> bad0,bad1;
    for(int i=0;i<n;++i)
        if(deg[i]>=2)
            bad0.insert(i);
    while(bad0.size()||bad1.size())
    {
        if(bad0.size())
        {
            int v=*bad0.begin();
            bad0.erase(v);
            col[v]=1;
            deg[v]=0;
            for(int i=0;i<g[v].size();++i)
            {
                int to=g[v][i];
                if(col[to]==0)
                    --deg[to];
                else
                    ++deg[to], ++deg[v];
            }
            if(deg[v]>=2)
                bad1.insert(v);
            for(int i=0;i<g[v].size();++i)
            {
                int to=g[v][i];
                if(deg[to]<=1)
                    bad0.erase(to),bad1.erase(to);
                else
                {
                    if(col[to]==0)
                        bad0.insert(to);
                    else
                        bad1.insert(to);
                }
            }
        }
        else
        {
            int v=*bad1.begin();
            bad1.erase(v);
            col[v]=0;
            deg[v]=0;
            for(int i=0;i<g[v].size();++i)
            {
                int to=g[v][i];
                if(col[to]==1)
                    --deg[to];
                else
                    ++deg[to], ++deg[v];
            }
            if(deg[v]>=2)
                bad0.insert(v);
            for(int i=0;i<g[v].size();++i)
            {
                int to=g[v][i];
                if(deg[to]<=1)
                    bad0.erase(to),bad1.erase(to);
                else
                {
                    if(col[to]==0)
                        bad0.insert(to);
                    else
                        bad1.insert(to);
                }
            }
        }
    }
    for (int i=0;i<n;++i)
        printf("%d",col[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();


    return 0;

}