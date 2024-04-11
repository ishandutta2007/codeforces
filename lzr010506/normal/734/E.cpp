#include <bits/stdc++.h>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

int color[200000];
int par[200000];
vector<int> e[200000];
bool used[200000];

int find(int x) 
{
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    par[x] = y;
}

pair<int,int> dfs(int v) 
{
    pair<int,int> ret {v,0};
    used[v] = true;
    for (auto x: e[v]) 
    {
        x = find(x);
        if (!used[x])
        {
            auto p = dfs(x);
            if (ret.second < p.second) ret = p;
        }
    }
    ret.second++;
    return ret;
}

int main() 
{
    int i, n;
    scanf("%d",&n);
    REP (i,n) scanf("%d",&color[i]);
    REP (i,n) par[i] = i;
    REP (i,n-1)
    {
        int u, v;
        scanf("%d%d",&u,&v);
        u--; v--;
        u = find(u);
        v = find(v);
        if (u == v) continue;
        if (color[u] == color[v]) unite(u,v);
        else 
        {
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    REP (i,n) 
        if (find(i) != i) 
        {
            int x = find(i);
            for (auto y: e[i]) e[x].push_back(y);
        }
    auto p = dfs(find(0));
    REP (i,n) used[i] = false;
    p = dfs(p.first);
    printf("%d\n",p.second/2);
    return 0;
}