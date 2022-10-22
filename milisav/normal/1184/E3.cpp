#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=1e5+5,L=18,M=1e6+5;
vector<int> par(N);
int find(int tr)
{
    if(par[tr]==tr)
        return tr;
    return par[tr]=find(par[tr]);
}
vector<vector<pair<pair<int,int>,int> > > graf(N);
bool merge(int a,int b,int c,int i)
{
    int aa=find(a),bb=find(b);
    if(aa==bb)
        return false;
    graf[a].pb({{b,c},i});
    graf[b].pb({{a,c},i});
    par[aa]=bb;
    return true;
}
vector<int> depth(N);
int up[N][L];
int maxx[N][L];
int minn[N][L];
int indeks[N];
void dfs(int tr,int par)
{
    for(auto p:graf[tr])
    {
        if(p.f.f==par)
            continue;
        depth[p.f.f]=depth[tr]+1;
        up[p.f.f][0]=tr;
        maxx[p.f.f][0]=p.f.s;
        indeks[p.f.f]=p.s;
        dfs(p.f.f,tr);
    }
}
vector<int> ans(M);
void calc(int a,int b,int w,int i)
{
    if(depth[a]<depth[b])
        swap(a,b);
    int sol=0;
    for(int j=L-1;j>=0;j--)
        if(depth[a]-depth[b]>=(1<<j))
            sol=max(sol,maxx[a][j]),minn[a][j]=min(minn[a][j],w),a=up[a][j];
    if(a==b)
    {
        ans[i]=sol;
        return;
    }
    for(int j=L-1;j>=0;j--)
        if(up[a][j]!=up[b][j])
                sol=max(sol,maxx[a][j]),minn[a][j]=min(minn[a][j],w),a=up[a][j],sol=max(sol,maxx[b][j]),minn[b][j]=min(minn[b][j],w),b=up[b][j];
    sol=max(sol,maxx[a][0]);
    minn[a][0]=min(minn[a][0],w);
    sol=max(sol,maxx[b][0]);
    minn[b][0]=min(minn[b][0],w);
    ans[i]=sol;
}
int main()
{
    for(int i=0;i<N;i++)
        par[i]=i;
    for(int i=0;i<N;i++)
        for(int j=0;j<L;j++)
            minn[i][j]=1e9;
    for(int i=0;i<N;i++)
        indeks[i]=M-2;
    //freopen("in.txt","r",stdin);
    int n,m;
    scanf("%i %i",&n,&m);
    vector<pair<pair<int,int>,pair<int,int> > > e(m);
    vector<int> unutra(m);
    for(int i=0;i<m;i++)
        scanf("%i %i %i",&e[i].s.f,&e[i].s.s,&e[i].f.f),e[i].s.f--,e[i].s.s--,e[i].f.s=i;
    sort(all(e));
    for(int i=0;i<m;i++)
        unutra[i]=merge(e[i].s.f,e[i].s.s,e[i].f.f,e[i].f.s);
    int cnt=0;
    for(int i=0;i<m;i++)
        if(!unutra[i])
            cnt++;
    dfs(0,0);
    for(int j=1;j<L;j++)
        for(int i=0;i<N;i++)
            up[i][j]=up[up[i][j-1]][j-1],maxx[i][j]=max(maxx[i][j-1],maxx[up[i][j-1]][j-1]);
    for(int i=0;i<m;i++)
        if(!unutra[i])
            calc(e[i].s.f,e[i].s.s,e[i].f.f,e[i].f.s);
    for(int j=L-1;j>0;j--)
        for(int i=0;i<N;i++)
            minn[i][j-1]=min(minn[i][j-1],minn[i][j]),minn[up[i][j-1]][j-1]=min(minn[up[i][j-1]][j-1],minn[i][j]);
    for(int i=1;i<N;i++)
        ans[indeks[i]]=minn[i][0];
    for(int i=0;i<m;i++)
        printf("%i\n",ans[i]);
}