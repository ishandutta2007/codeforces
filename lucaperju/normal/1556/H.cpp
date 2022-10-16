#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
struct DSU
{
    vector<int> t;
    DSU(int n) : t(n, -1) {}
    bool sameSet (int a, int b) { return root(a)==root(b);}
    int root (int a) { return t[a] < 0 ? a : t[a] = root(t[a]);}
    bool join (int a, int b) {
        a = root(a); b = root(b);
        if(a == b) return false;
        t[a] = b; return true;
    }
};

struct Gmat /// graphic matroid
{
    int n;
    vector<int>a;
    vector<int>b;
    Gmat(int n, vector<int> a, vector<int> b) : n(n), a(a), b(b) {}
    vector<int> canAdd (vector<bool> inS)
    {
        DSU g(n);
        for(int i=0;i<inS.size();++i)
            if(inS[i])
                assert(g.join(a[i],b[i]));
        vector<int>ans;
        for(int i=0;i<inS.size();++i)
            if(!inS[i] && !g.sameSet(a[i],b[i]))
                ans.push_back(i);
        return ans;
    }
};

struct Cmat /// colorful matroid
{
    int k;
    vector<int>lim;
    vector<int>col;
    Cmat(int k, vector<int> lim, vector<int> col) : k(k), lim(lim), col(col) {}
    vector<int> canAdd (vector<bool> inS)
    {
        for(int i=0;i<inS.size();++i)
            if(inS[i])
                assert(0<=(--lim[col[i]]));
        vector<int>ans;
        for(int i=0;i<inS.size();++i)
            if(!inS[i] && 0<lim[col[i]])
                ans.push_back(i);
        for(int i=0;i<inS.size();++i)
            if(inS[i])
                ++lim[col[i]];
        return ans;
    }
};

template <class M1, class M2>
pair<int, int> matroidIntersect (M1 m1, M2 m2, vector<int> cost)
{
    int i,j,n=(int)cost.size();
    vector<bool> inS(n,false);
    while(1)
    {
        /// build exchange graph:
        vector<int>graph[n];
        for(i=0;i<n;++i)
        {
            if(!inS[i])
                continue;
            inS[i]=0;
            vector<int>canAdd = m1.canAdd(inS);
            for(j=0;j<canAdd.size();++j)
            {
                if(canAdd[j]==i)
                    continue;
                graph[i].push_back(canAdd[j]);
            }
            canAdd = m2.canAdd(inS);
            for(j=0;j<canAdd.size();++j)
            {
                if(canAdd[j]==i)
                    continue;
                graph[canAdd[j]].push_back(i);
            }
            inS[i]=1;
        }
        /// run Bellman from nodes that can be added to m1 to nodes that can be added to m2
        /// minimize pair (total weight, number of edges)
        vector<int>t(n,-1);
        vector<bool>inq(n,false);
        vector<bool>viz(n,false);
        vector<long long>cst(n,0);
        queue<int>q;
        vector<int>canAdd = m1.canAdd(inS);
        for(i=0;i<canAdd.size();++i)
        {
            cst[canAdd[i]]=cost[canAdd[i]]*1LL*INF;
            viz[canAdd[i]]=true;
            q.push(canAdd[i]);
            inq[canAdd[i]]=true;
        }
        while(!q.empty())
        {
            int nod=q.front();
            q.pop();
            inq[nod]=0;
            for(i=0;i<graph[nod].size();++i)
            {
                int nn=graph[nod][i];
                long long ncst=cst[nod]+1;
                if(inS[nn])
                    ncst=ncst-INF*1LL*cost[nn];
                else
                    ncst=ncst+INF*1LL*cost[nn];
                if(!viz[nn] || ncst<cst[nn])
                {
                    viz[nn]=true;
                    cst[nn]=ncst;
                    t[nn]=nod;
                    if(!inq[nn])
                        inq[nn]=1,q.push(nn);
                }
            }
        }
        int bst=-1;
        canAdd = m2.canAdd(inS);
        for(i=0;i<canAdd.size();++i)
        {
            if(!viz[canAdd[i]])
                continue;
            if(bst==-1 || cst[canAdd[i]]<cst[bst])
                bst=canAdd[i];
        }
        if(bst==-1)
            break;
        /// augment the path
        while(t[bst]!=-1)
            inS[bst]=1-inS[bst],bst=t[bst];
        inS[bst]=1-inS[bst];
    }
    int cnt=0,s=0;
    for(i=0;i<n;++i)
        if(inS[i])
            ++cnt,s+=cost[i];
    return make_pair(cnt,s);
}
int initcst[55][55];
int initlim[10];
vector<int>curlim;
struct edge
{
    int a,b,c;
};
vector<edge>edges;
bool cmp (edge a, edge b)
{
    return a.c<b.c;
}
vector<int>a;
vector<int>b;
vector<int>cst;
vector<int>col;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,k,n;
    cin>>n>>k;
    for(i=0;i<k;++i)
        cin>>initlim[i];
    initlim[k]=n;
    for(i=0;i<n;++i)
        for(j=i+1;j<n;++j)
            cin>>initcst[i][j];
    for(i=k;i<n;++i)
        for(j=i+1;j<n;++j)
            edges.push_back({i,j,initcst[i][j]});
    sort(edges.begin(),edges.end(),cmp);
    DSU dsu(n);

    for(i=0;i<edges.size();++i)
    {
        if(dsu.join(edges[i].a,edges[i].b))
        {
            a.push_back(edges[i].a);
            b.push_back(edges[i].b);
            cst.push_back(edges[i].c);
            col.push_back(k);
        }
    }
    for(i=0;i<k;++i)
        for(j=k;j<n;++j)
        {
            a.push_back(i);
            b.push_back(j);
            cst.push_back(initcst[i][j]);
            col.push_back(i);
        }
    vector<pair<int,int>>ed;
    for(i=0;i<k;++i)
        for(j=i+1;j<k;++j)
            ed.push_back(make_pair(i,j));
    vector<int>cstc(k*k,0);
    for(i=0;i<=k;++i)
        curlim.push_back(initlim[i]);
    long long ans=INF;
    for(int msk=0;msk<(1<<(ed.size()));++msk)
    {
        for(i=0;i<=k;++i)
            curlim[i]=initlim[i];
        long long s=0;
        DSU dsuc(n);
        bool ok=true;
        for(i=0;i<ed.size();++i)
        {
            if(msk&(1<<i))
            {
                cstc[i]=-INF;
                s+=INF+initcst[ed[i].first][ed[i].second];
                if(!dsuc.join(ed[i].first,ed[i].second))
                    ok=false;
                if((--curlim[ed[i].first])<0)
                    ok=false;
                if((--curlim[ed[i].second])<0)
                    ok=false;
            }
            else
                cstc[i]=initcst[ed[i].first][ed[i].second];
        }
        if(ok==false)
            continue;
        for(i=0;i<ed.size();++i)
        {
            if(msk&(1<<i))
                ++curlim[ed[i].first];
        }
        for(i=0;i<ed.size();++i)
        {
            if(msk&(1<<i))
            {
                a.push_back(ed[i].first);
                b.push_back(ed[i].second);
                cst.push_back(cstc[i]);
                col.push_back(ed[i].first);
            }
        }
        Gmat m1(n,a,b);
        Cmat m2(k+1,curlim,col);
        pair<int,int> ansc = matroidIntersect(m1,m2,cst);
        if(ansc.first==n-1)
            ans=min(ans,ansc.second+s);
        for(i=0;i<ed.size();++i)
        {
            if(msk&(1<<i))
            {
                a.pop_back();
                b.pop_back();
                cst.pop_back();
                col.pop_back();
            }
        }
    }
    cout<<ans;
    return 0;
}