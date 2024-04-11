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













const int N=111111;

pii mypii(int a, int b)
{
    return pii(min(a,b),max(a,b));
}

struct dsu
{
    vector<int> p, r;
    int cnt;
    
    void init(int n)
    {
        p.resize(n);
        for (int i=0;i<n;++i)
            p[i]=i;
        r.assign(n,0);
        cnt=n;
    }
    int get(int v)
    {
        return v==p[v]?v:p[v]=get(p[v]);
    }
    void unite(int a, int b)
    {
        a=get(a);
        b=get(b);
        if(a==b) return;
        --cnt;
       p[a]=b;
    }
};





int tin[N], tup[N];
set<int> u;
int timer=0;
set<pii> br;
vector<int> g[N];




void dfs(int v, int p)
{   
    u.insert(v);
    tin[v]=timer++;
    tup[v]=tin[v];
    
    for (int i=0;i<g[v].size();++i)
    {
        int to=g[v][i];
        if(!u.count(to))
        {
            dfs(to,v);
            tup[v]=min(tup[v],tup[to]);
            if(tup[to]>tin[v])
                br.insert(mypii(v,to));
        }
        else
        {
            if(to!=p)
                tup[v]=min(tup[v],tin[to]);
        }
    }
}




struct edge
{
    int f, to, w, id;
    edge() {}
    edge(int _f, int _to, int _w, int _id): f(_f), to(_to), w(_w), id(_id) {}
};

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

vector<vector<edge> > lawyer;
vector<edge> e;
string ans[N];
map<pii,int> curE;
set<int> any;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
    
    
    
    dsu DSU;
    DSU.init(n);
    

    
    for (int i=0;i<m;++i)
    {
        int f,t,w;
        
        cin>>f>>t>>w;
        
        --f;
        --t;
        
        e.push_back(edge(f,t,w,i));
    }
    
    sort(e.begin(),e.end(),cmp);
    
    vector<edge> t;
    
    for (int i=0;i<m;++i)
    {
        t.push_back(e[i]);
        if(i==m-1||e[i].w!=e[i+1].w)
        {
            lawyer.push_back(t);
            t.clear();
        }
    }
    
    
    
    for (int i=0;i<lawyer.size();++i)
    {
        br.clear();
        u.clear();
        timer=0;
        curE.clear();
        
        vector<edge> t=lawyer[i];
        set<int> now;
        
        for(int j=0;j<t.size();++j)
        {
            int ff=DSU.get(t[j].f), tt=DSU.get(t[j].to);
            now.insert(ff);
            now.insert(tt);
        }
        
        for(set<int>::iterator j=now.begin();j!=now.end();++j)
            g[*j].clear();

        for(int j=0;j<t.size();++j)
        {
            int ff=DSU.get(t[j].f), tt=DSU.get(t[j].to);

            if(ff==tt)
            {
                ans[t[j].id]="none";
                continue;
            }
            
            if(curE.count(mypii(ff,tt)))
                ++curE[mypii(ff,tt)];
            else
                curE.insert(MP(mypii(ff,tt),1));
                
            g[ff].push_back(tt);
            g[tt].push_back(ff);
            any.insert(ff);
            any.insert(tt);
        }
        
        for(set<int>::iterator j=now.begin();j!=now.end();++j)
            if(!u.count(*j))
                dfs(*j,*j);
            
        for(int j=0;j<t.size();++j)
        {
             int ff=DSU.get(t[j].f), tt=DSU.get(t[j].to);
             
             if(ff==tt)
                continue;
                
            if(br.count(mypii(ff,tt))&&curE[mypii(ff,tt)]==1)
                ans[t[j].id]="any";
            else
                ans[t[j].id]="at least one";
        }
        
        for(int j=0;j<t.size();++j)
             DSU.unite(t[j].f,t[j].to);
    }
    
    
    
    for (int i=0;i<m;++i)
        cout<<ans[i]<<endl;
    
    
    
    return 0;
        
}