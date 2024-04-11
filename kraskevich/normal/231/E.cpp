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

const int N = 1000 * 100 + 1;
vector<int> g[N];
int comp[N];
vector<int> ver;
int tin[N], tmin[N];
vector<bool> u(N, false);
int timer = 0;
int cnt = 0;
int val[N];
vector<int> szsz(N, 0);
set<pii> edge;

void dfs(int v, int p)
{
    u[v] = true;
    tmin[v] = tin[v] = timer++;
    ver.push_back(v);
    
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        
        if (u[to])
        {
            if (to != p)
                tmin[v] = min(tmin[v], tin[to]);
            continue;
        }
        
        dfs(to, v);
        tmin[v] = min(tmin[v], tmin[to]);
        
        if (tmin[to] > tin[v])
        {
            while (ver.back() != to)
            {
                comp[ver.back()] = cnt;
                ver.pop_back();
            }
            ver.pop_back();
            comp[to] = cnt++;
        }
    }
    
    if (v == 0)
    {
        while (ver.size())
        {
            comp[ver.back()] = cnt;
            ver.pop_back();
        }
        ++cnt;
    }
}


vector<int> ng[N];

namespace heavylight
{
    const int N=100*1001;
    vector<int> g[N];
    int cnt[N],h[N],tin[N],tout[N],u[26][N],timer=0,num[N];
    vector<bool> vis(N, false);
    
    
    #pragma comment(linker, "/STACK:16000000")
        
    void dfs1(int v, int hh, int p)
    {
        vis[v]=true;
        h[v]=hh;
        tin[v]=timer++;
        cnt[v]=1;
        
        u[0][v]=p;
        for(int i=1;i<26;++i)
            u[i][v]=u[i-1][u[i-1][v]];
        
        for(int i=0;i<g[v].size();++i)
        {
            int to=g[v][i];
            if(!vis[to])
                dfs1(to,hh+1,v);
            if(to!=p)
                cnt[v]+=cnt[to];
        }
        tout[v]=timer++;
    }
    
    bool anc(int a, int b)
    {
        return tin[a]<=tin[b]&&tout[a]>=tout[b];
    }
    
    int lca(int a, int b)
    {
        if(anc(a,b))
            return a;
        if(anc(b,a))
            return b;
        
        for(int i=25;i>=0;--i)
            if(!anc(u[i][a],b))
                a=u[i][a];
        return u[0][a];
    }
    
    class segm_tree
    {
        vector<int> t,add;
        int n;
        
        void _upd(int i, int l, int r, int tl, int tr, int a)
        {
            if(l==tl&&r==tr)
            {
                add[i]+=a;
                return;
            }
            
            int ll=2*i+1,rr=2*i+2,m=(tl+tr)/2;
            
            if(l<=m)
                _upd(ll,l,min(r,m),tl,m,a);
            if(r>m)
                _upd(rr,max(l,m+1),r,m+1,tr,a);
            t[i]=t[ll]+add[ll]+t[rr]+add[rr];
        }
        int _getMax(int i, int l, int r, int tl, int tr, int a)
        {
            a+=add[i];
            
            if(l==tl&&r==tr)
                return t[i]+a*(r - l + 1);
                
            int ll=2*i+1,rr=2*i+2,m=(tl+tr)/2,ml=0,mr=0;
            
            if(l<=m)
                ml=_getMax(ll,l,min(r,m),tl,m,a);
            if(r>m)
                mr=_getMax(rr,max(l,m+1),r,m+1,tr,a);
                
            return ml + mr;
        }
        public:
            void init(int _n)
            {
                n=_n;
                t.assign(4*n+1,0);
                add.assign(4*n+1,0);
            }
            int getMax(int l, int r)
            {
                if(l>=n)
                    return 0;
                if(r<0)
                    return 0;
                if(l>r)
                    return 0;
                    
                l=max(l,0);
                r=min(r,n-1);
                
                //cout<<l<<" "<<r<<" "<<n<<endl;
                
                return _getMax(0,l,r,0,n-1,0);
            }
            void upd(int i, int val)
            {
                _upd(0,i,i,0,n-1,val);
            }
    };
    
    struct path
    {
        vector<int> p;
        segm_tree tree;
        
        void add(int v)
        {
            p.push_back(v);
        }
        void build()
        {
            tree.init(p.size());
        }
        int getMax(int hl, int hr)
        {
            int l=hl-h[p[0]];
            int r=hr-h[p[0]];
            //cout<<l<<" "<<r<<endl;
            return tree.getMax(l,r);
        }
        void upd(int hl, int val)
        {
            int l=hl-h[p[0]];
            tree.upd(l,val);
        }
            
    };
    
    path way[N];
    int sz=0;
    
    void dfs2(int v, int j)
    {
        vis[v]=true;
        
        if(j==-1)
            j=sz++;
        way[j].add(v);
        num[v]=j;
        
        int mx=-1;
        for(int i=0;i<g[v].size();++i)
        {
            int to=g[v][i];
            if(vis[to])
                continue;
            if(mx==-1||cnt[to]>cnt[mx])
                mx=to;
        }
        
        for(int i=0;i<g[v].size();++i)
        {
            int to=g[v][i];
            if(vis[to]||to==mx)
                continue;
            dfs2(to,-1);
        }
        
        if(mx>=0)
            dfs2(mx,j);
    }
    
    int getAns(int lo, int hi);
    
    int solve(int a, int b)
    {
       
        int c=lca(a,b);
        
        int res = getAns(c,a) + getAns(c,b);
        
        if (szsz[c] > 1)
            --res;
        return res;
    }
    
    int getAns(int lo, int hi)
    { 
        //cout << lo << " " << hi << endl;
        int cur=hi;
        int best=0;
        for(;;)
        {
            best+=way[num[cur]].getMax(h[lo],h[cur]);
            if(num[cur]==num[lo])
                break;
            cur=way[num[cur]].p[0];
            cur=u[0][cur];
        }
        
        return best;
    }
};





const i64 mod = 1000 * 1000 * 1000 + 7;

i64 pw(i64 a, i64 n)
{
    i64 res = 1;
    while(n)
    {
        if (n % 2)
            res *= a, res %= mod;
        a *= a;
        a %= mod;
        n /= 2;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int f, t;
        cin >> f >> t;
        
        --f;
        --t;
        
        g[f].push_back(t);
        g[t].push_back(f);
        
        
    }
    
    dfs(0, 0);
    
   
    for (int v = 0; v < n; ++v)
        for (int i = 0; i < g[v].size(); ++i)
            if (comp[v] != comp[g[v][i]])
            {
                int a = comp[v];
                int b = comp[g[v][i]];
                ng[a].push_back(b);
                ng[b].push_back(a);
            }
    
    for (int i = 0; i < n; ++i)
        szsz[comp[i]]++;
    
    for (int i = 0; i < cnt; ++i)
        heavylight::g[i] = ng[i];
    
    heavylight::vis.assign(cnt,0);
    heavylight::dfs1(0,0,0);
    heavylight::vis.assign(cnt,0);
    heavylight::dfs2(0,-1);
    
    /*for (int i = 0; i < n; ++i)
        cout << comp[i] << " ";
    cout << endl;
    for (int i = 0; i < cnt; ++i)
        cout << szsz[i] << " ";
    cout << endl;*/
    
    for(int i=0;i<heavylight::sz;++i)
        heavylight::way[i].build();
    
    for (int i = 0; i < cnt; ++i)
        if (szsz[i] > 1)
        {
            //cout << i << endl;
            heavylight::way[heavylight::num[i]].upd(heavylight::h[i], 1);
        }
    
    int k;
    cin >> k;
    
    for (int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        --a;
        --b;
        
        int t = heavylight::solve(comp[a], comp[b]);
        
        //cout << t << endl;
        cout << pw(2ll, t) << "\n";
    }
    
   
    //cin >> n;
    
    return 0;
}