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

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second


const int N = 3 * 100 * 1000 + 10;
vector<int> g[N];
vector<int> comp[N];
int add[N];
int col[N];
int cnt[N];
int sum[N];
bool u[N];
int h[N];
int dd[N];
vector<int> t;
int sz = 0;
int n;

void dfs1(int v, int hh)
{
    u[v] = true;
    h[v] = hh;
    t.push_back(v);
    col[v] = sz;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!u[to])
            dfs1(to, hh + 1);
    }
}

void dfs2(int v, int curr, int hh)
{
    u[v] = true;
    curr += add[v];
    curr += dd[hh];
    sum[v] = curr;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!u[to])
            dfs2(to, curr, hh + 1);
    }
}

int v[N];
int x[N];
int d[N];
int type[N];

void calc(int l, int r)
{
    fill(u,u+n,false);
    for(int i=l;i<=r;++i)
    {
        if(type[i]==1)
            continue;
        if(v[i]==0)
        {
            dd[0]+=x[i];
            dd[d[i]+1]-=x[i];
        }
        else
        {
            int hi=h[v[i]]+d[i];
            if(hi<comp[col[v[i]]].size())
                add[comp[col[v[i]]][hi]]-=x[i];
            int lo=d[i]-h[v[i]];
            if(lo<0)
            {
                add[comp[col[v[i]]][h[v[i]]-d[i]-1]]+=x[i];
            }
            else
            {
                dd[0]+=x[i];
                dd[lo+1]-=x[i];
                if(lo<comp[col[v[i]]].size())
                    add[comp[col[v[i]]][lo]]+=x[i];
            }
        }
    }
    dfs2(0,0,0);
}

int getDist(int a, int b)
{
    //cerr<<a<<" "<<b<<endl;
    if(a==0)
        return h[b];
    if(b==0)
        return h[a];
    if(col[a]==col[b])
        return max(h[a],h[b])-min(h[a],h[b]);
    return h[a]+h[b];
}

void solve()
{
    fill(add, add + N, 0);
    fill(dd,dd+N,0);
    fill(u, u + N, false);

    scanf("%d", &n);
    int q;
    scanf("%d", &q);

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    u[0] = true;
    h[0]=0;
    for (int i = 0; i < g[0].size(); ++i)
    {
        int to = g[0][i];
        t.clear();
        dfs1(to, 1);
        comp[sz]=t;
        ++sz;
    }


    int blsz = 500;

    for (int i=0;i<q;++i)
    {
        scanf("%d%d",&type[i],&v[i]);
        if (type[i]==0)
            scanf("%d%d",&x[i],&d[i]);
        --v[i];
        int low=i-i%blsz;
        if(type[i]==1)
        {
            int res=sum[v[i]];
            for(int j=low;j<i;++j)
                if(type[j]==0&&getDist(v[i],v[j])<=d[j])
                    res+=x[j];
            printf("%d\n",res);
        }
        if(i%blsz==blsz-1)
            calc(low,i);
    }
}

int main()
{
    solve();

    return 0;
}