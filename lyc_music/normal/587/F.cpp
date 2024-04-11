//~~
#define setI(x) freopen(x,"r",stdin)
#define setO(x) freopen(x,"w",stdout)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 100005
#define B 316
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N][26];
int fail[N];
int cnt;
int opt[N];
int n,m;
string st[N];
int DFN;
int dfn[N];
int rdfn[N];
int s[N];
poly G[N];
vector<pair<int,pa>>Q[N];
vector<pa>Lq[N],Rq[N];
int ed[N];
int ans[N];
poly L[N],R[N];
void ad(int x,int y)
{
    G[x].push_back(y);
}
void dfs(int k)
{
    for (auto u:G[k])
    {
        dfs(u);
        s[k]+=s[u];
    }
}
void dfs1(int k)
{
    dfn[k]=++DFN;
    for (auto u:G[k])
    {
        dfs1(u);
    }
    rdfn[k]=DFN;
}
#define From(x) ((x-1)/B+1)
namespace FK
{
    int val[N],tag[N];
    void update(int l,int r)
    {
        if (From(l)==From(r))
        {
            for (int i=l;i<=r;i++) val[i]++;
        } else
        {
            for (int i=l;i<=From(l)*B;i++) 
                val[i]++;
            for (int i=From(l)+1;i<From(r);i++)
                tag[i]++;
            for (int i=(From(r)-1)*B+1;i<=r;i++) val[i]++;
        }
    }
}
void BellaKira()
{
    for (int i=0;i<26;i++) tr[0][i]=1;
    cnt=1;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>st[i];
        int now=1;
        for (auto u:st[i])
        {
            if (!tr[now][u-'a']) tr[now][u-'a']=++cnt;
            now=tr[now][u-'a'];
        }
        ed[i]=now;
    }
    queue<int>q;
    q.push(1);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<26;i++)
        {
            if (tr[u][i])
            {
                fail[tr[u][i]]=tr[fail[u]][i];
                q.push(tr[u][i]);
            } else tr[u][i]=tr[fail[u]][i];
        }
    }
    for (int i=2;i<=cnt;i++) ad(fail[i],i);
    for (int i=1;i<=m;i++)
    {
        int l=read(),r=read(),k=read();
        if (st[k].size()>B)
        {
            Q[k].push_back(mp(i,mp(l,r)));
            opt[i]=1;
        } else
        {
            Lq[l-1].push_back(mp(k,i));
            Rq[r].push_back(mp(k,i));
        }
    }
    for (int i=1;i<=n;i++)
        if (st[i].size()>B)
        {
            for (int j=1;j<=cnt;j++) s[j]=0;
            int now=1;
            for (auto u:st[i])
            {
                now=tr[now][u-'a'];
                s[now]=1;
            }
            dfs(1);
            for (auto u:Q[i])
            {
                L[u.se.fi-1].push_back(u.fi);
                R[u.se.se].push_back(u.fi);
            }
            int sm=0;
            for (int j=1;j<=n;j++)
            {
                sm+=s[ed[j]];
                for (auto u:L[j])
                {
                    ans[u]-=sm;
                }
                for (auto u:R[j])
                {
                    ans[u]+=sm;
                }
            }
            for (int j=0;j<=n;j++)
            {
                vector<int>().swap(L[j]);
                vector<int>().swap(R[j]);
            }
        }
    dfs1(1);
    for (int i=1;i<=n;i++)
    {
        FK::update(dfn[ed[i]],rdfn[ed[i]]);
        for (auto U:Lq[i])
        {
            int x=U.fi,y=U.se;
            int now=1;
            for (auto u:st[x])
            {
                now=tr[now][u-'a'];
                ans[y]-=FK::val[dfn[now]]+FK::tag[From(dfn[now])];
            }
        }
        for (auto U:Rq[i])
        {
            int x=U.fi,y=U.se;
            int now=1;
            for (auto u:st[x])
            {
                now=tr[now][u-'a'];
                ans[y]+=FK::val[dfn[now]]+FK::tag[From(dfn[now])];
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        writeln(ans[i]);
    }
}
signed main()
{
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*
16 13
t
h
dvawooggk
ztqlqgvhzikkynxgbohjcptimzuothen
r
ucqy
rieye
eyklxwlvea
tf
h
chhvhhqro
uhymlqtrxpagbmn
j
hmo
hlzqe
k
4 15 10
6 14 4
16 16 9
10 14 2
16 16 14
15 16 13
9 12 1
8 15 13
4 15 11
4 6 7
12 15 8
10 10 2
8 8 12


1
4
0
1
0
0
0
1
6
1
0
1
0
*/