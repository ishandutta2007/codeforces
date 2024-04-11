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
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
multiset<int>gbs;
multiset<int>S[N];
set<int>P;
int s[5][N];
int ans;
int a[5][N];
int n,q;
vector<pa>I[N],E[N];
int f[N];
void Ers(int x)
{
    if (S[x].empty()) return;
    gbs.erase(gbs.find(f[x]-*S[x].begin()));
}
void Ins(int x)
{
    if (S[x].empty()) return;
    gbs.insert(f[x]-*S[x].begin());
}
void BellaKira()
{
    ans=-inf;
    n=read(),q=read();
    for (int i=1;i<=3;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=read(),s[i][j]=s[i][j-1]+a[i][j];
    for (int i=1;i<=q;i++)
    {
        int x=read(),y=read(),w=read();
        I[x].push_back(mp(x-1,w));
        E[y+1].push_back(mp(x-1,w));
    }
    f[0]=-inf;
    for (int i=1;i<=n;i++)
    {
        if (s[1][i]-s[2][i-1]>f[i-1]) f[i-1]=s[1][i]-s[2][i-1];
        while (P.size())
        {
            int x=(*P.rbegin());
            if (f[x]>=f[i-1]) break;
            Ers(x);
            if (S[x].size()>S[i-1].size()) S[x].swap(S[i-1]);
            for (auto u:S[x]) S[i-1].insert(u);
            S[x].clear();
            P.erase(--P.end());
        }
        P.insert(i-1);
        Ins(i-1);
        f[i]=-inf;
        for (auto u:E[i])
        {
            int x=u.fi,y=u.se;
            auto it=P.lower_bound(x);
            int p=(*it);
            Ers(p);
            S[p].erase(S[p].find(y));
            Ins(p);
        }
        for (auto u:I[i])
        {
            int x=u.fi,y=u.se;
            auto it=P.lower_bound(x);
            int p=(*it);
            Ers(p);
            S[p].insert(y);
            Ins(p);
        }
        if (gbs.size()) f[i]=(*gbs.rbegin()),ans=max(ans,f[i]+s[3][n]-s[3][i-1]+s[2][i]);
        // cout<<"?"<<i<<" "<<f[i]<<endl;
    }
    writeln(ans);

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

*/