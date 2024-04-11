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
vector<bool> matroidIntersect (M1 m1, M2 m2, vector<int> cost)
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
    return inS;
}
int v[30][30];
int val[30][30];
vector<int>a;
vector<int>b;
vector<int>cst;
vector<int>col;
vector<int>lim;
int viz[500];
bool eok[500];
bool em[505][505];
vector<int>ed[500];
void dfs (int pz, int val)
{
    viz[pz]=val;
    for(int i=0;i<ed[pz].size();++i)
        if(!viz[ed[pz][i]])
            dfs(ed[pz][i],val);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,k,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        a.clear();
        b.clear();
        cst.clear();
        col.clear();
        lim.clear();
        int vlc=-1;
        int cnt1=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                char c;
                cin>>c;
                val[i][j]=++vlc;
                if(c=='O')
                    v[i][j]=0,eok[vlc]=true;
                else
                    v[i][j]=1,eok[vlc]=false;
                if(!v[i][j]&&!((i+j)&1)&&i+j!=2)
                    ++cnt1;
            }
        for(i=0;i<=vlc;++i)
            for(j=0;j<=vlc;++j)
                em[i][j]=false;
        for(i=1;i<n;++i)
            for(j=1;j<=m;++j)
            {
                if(v[i][j]+v[i+1][j] || i==1 && j==1)
                    continue;
                a.push_back(val[i][j]);
                b.push_back(val[i+1][j]);
                cst.push_back(1);
                if((i+j)&1)
                    col.push_back(val[i+1][j]);
                else
                    col.push_back(val[i][j]);
            }
        for(i=1;i<=n;++i)
            for(j=1;j<m;++j)
            {
                if(v[i][j]+v[i][j+1] || i==1 && j==1)
                    continue;
                a.push_back(val[i][j]);
                b.push_back(val[i][j+1]);
                cst.push_back(1);
                if((i+j)&1)
                    col.push_back(val[i][j+1]);
                else
                    col.push_back(val[i][j]);
            }
        lim.resize(n*m,2);
        Gmat m1(n*m,a,b);
        Cmat m2(n*m,lim,col);
        vector<int>cst(a.size(),0);
        vector<bool>ans=matroidIntersect(m1,m2,cst);
        int cnt=0;
        for(i=0;i<ans.size();++i)
        {
            if(ans[i])
                ++cnt,em[a[i]][b[i]]=true;
            else
                em[a[i]][b[i]]=false;
        }
        if(cnt<cnt1*2)
        {
            cout<<"NO\n";
            continue;
        }
        ++vlc;
        for(i=0;i<vlc;++i)
        {
            viz[i]=0;
            ed[i].clear();
        }
        for(i=0;i<ans.size();++i)
            if(ans[i])
                ed[a[i]].push_back(b[i]),ed[b[i]].push_back(a[i]);
        int k=0;
        for(i=0;i<vlc;++i)
            if(eok[i] && !viz[i])
                dfs(i,++k);
        DSU d(k+1);
        if(!v[1][2])
        {
            a.push_back(0);
            b.push_back(1);
        }
        if(!v[2][1])
        {
            a.push_back(0);
            b.push_back(val[2][1]);
        }
        for(i=0;i<a.size();++i)
        {
            if(!d.sameSet(viz[a[i]],viz[b[i]]))
            {
                ++cnt;
                em[a[i]][b[i]]=true;
                d.join(viz[a[i]],viz[b[i]]);
            }
        }
        cout<<"YES\n";
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                if(v[i][j])
                    cout<<'X';
                else
                    cout<<'O';
                if(j<m)
                {
                    if(em[val[i][j]][val[i][j+1]])
                        cout<<'O';
                    else
                        cout<<' ';
                }
            }
            cout<<'\n';
            if(i<n)
            {
                for(j=1;j<=m;++j)
                {
                    if(em[val[i][j]][val[i+1][j]])
                        cout<<'O';
                    else
                        cout<<' ';
                    if(j<m)
                        cout<<' ';
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}