#include <bits/stdc++.h>

using namespace std;

const int INF = 1000*1000*1000;
const int N=100*1001;
vector<int> g[N];
int cnt[N],h[N],tin[N],tout[N],u[26][N],timer=0,num[N];
vector<bool> vis;


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
    vector<int> inp;
    int n;

    void _upd(int i, int l, int r, int tl, int tr, int a)
    {
        if(l==tl&&r==tr)
        {
            add[i]=min(add[i],a);
            return;
        }

        int ll=2*i+1,rr=2*i+2,m=(tl+tr)/2;

        if(l<=m)
            _upd(ll,l,min(r,m),tl,m,a);
        if(r>m)
            _upd(rr,max(l,m+1),r,m+1,tr,a);
        t[i]=max(_getMax(2*i+1,tl,m,tl,m,INF), _getMax(2*i+2,m+1,tr,m+1,tr,INF));
    }
    int _getMax(int i, int l, int r, int tl, int tr, int a)
    {
        a=min(a,add[i]);

        if(l==tl&&r==tr)
            return max(t[i], 2*inp[r] - a);

        int ll=2*i+1,rr=2*i+2,m=(tl+tr)/2,ml=0,mr=0;

        if(l<=m)
            ml=_getMax(ll,l,min(r,m),tl,m,a);
        if(r>m)
            mr=_getMax(rr,max(l,m+1),r,m+1,tr,a);

        return max(ml,mr);
    }
    void build(int i, int l, int r)
    {
        if(l==r)
            t[i]=-INF;
        else
        {
            int m=(l+r)/2;
            build(2*i+1,l,m);
            build(2*i+2,m+1,r);
            t[i]=max(t[2*i+1], t[2*i+2]);
        }
    }
    public:
        void init(int _n, vector<int> f)
        {
            inp=f;
            n=_n;
            t.assign(4*n+1,0);
            add.assign(4*n+1,INF);
            build(0,0,n-1);
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

            return _getMax(0,l,r,0,n-1,INF);
        }
        void upd(int l, int r, int val)
        {
            _upd(0,l,r,0,n-1,val);
        }
};

struct path
{
    vector<int> p;
    vector<int> f;
    segm_tree tree;

    void add(int v)
    {
        p.push_back(v);
        f.push_back(h[v]);
    }
    void build()
    {
        tree.init(p.size(), f);
    }
    int getMax(int hl, int hr)
    {
        int l=hl-h[p[0]];
        int r=hr-h[p[0]];
        return tree.getMax(l,r);
    }
    void upd(int hl, int val)
    {
        int l=hl-h[p[0]];
        tree.upd(0, l, val);
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
        //cerr << to << endl;
        if(vis[to])
            continue;
        if(mx==-1||cnt[to]>cnt[mx])
            mx=to;
    }
    //cerr << v << " " << mx << endl;
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


int getAns(int hi)
{
    int lo=0;
    int cur=hi;
    int best=0;
    for(;;)
    {
        best=max(best,way[num[cur]].getMax(h[lo],h[cur]));
        if(num[cur]==num[lo])
            break;
        cur=way[num[cur]].p[0];
        cur=u[0][cur];
    }
    return -best + h[hi];
}

void upd(int v)
{
    int hh = h[v];
    for (;;)
    {
        way[num[v]].upd(h[v], hh);
        v = way[num[v]].p[0];
        if (v == 0)
            break;
        v = u[0][v];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n, 0);
    dfs1(0, 0, 0);
    vis.assign(n, 0);
    dfs2(0, -1);
    for (int i = 0; i < sz; i++)
        way[i].build();
    upd(0);
    for (int i = 0; i < m; i++)
    {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1)
            upd(v);
        else
            cout << getAns(v) << "\n";
    }



    return 0;
}