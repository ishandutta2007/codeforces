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
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,nxt[N],du[N],totr,lun,mx;
int vis[N],a[N];
int f[N];
poly G[N];
set<int>S;
int ans[N];
int p[N];
int g[N];
poly F[N];
void BellaKira()
{
    n=read();
    for (int i=1;i<=n;i++) p[i]=read(),du[p[i]]++,nxt[i]=p[i];
    for (int i=1;i<=n;i++)
        if (!du[i]) totr++;
    for (int i=1;i<=n;i++) 
    {
        a[i]=read(),mx=max(mx,a[i]),f[i]=i;
        if (a[i]<=n) vis[a[i]]=1;
    }
    lun=(mx-n)/totr;
    // cout<<"?"<<lun<<endl;
    for (int j=0;j<=62;j++)
    {
        for (int i=1;i<=n;i++)
            {
                if ((lun>>j)&1)
                {
                    f[i]=nxt[f[i]];
                }
            }
        for (int i=1;i<=n;i++)
                g[i]=nxt[nxt[i]];
        for (int i=1;i<=n;i++)
            nxt[i]=g[i];
    }
    for (int i=1;i<=n;i++)
        G[f[i]].push_back(i);
    for (int i=1;i<=n;i++)
    {
        if (G[i].empty()||a[i]>n) continue;
        int nowx=a[i];
        sort(G[i].begin(),G[i].end());
        // cout<<"?"<<i<<endl;
        // for (auto u:G[i]) cout<<u<<" ";
        // cout<<endl;
        for (auto u:G[i])
        {
            if (u==G[i][0])
            {
                ans[u]=nowx;
                continue;
            }
            // cout<<"??"<<nowx<<" "<<u<<endl;
            F[nowx].push_back(u);
        }
    }

    for (int i=1;i<=n;i++)
    {
        for (auto u:F[i]) S.insert(u);
        if (!vis[i]) 
        {
            ans[(*S.begin())]=i;
            S.erase(S.begin());
        }
    }
    for (int i=1;i<=n;i++) writesp(ans[i]);


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
10
5 1 5 6 2 4 4 6 2 9
3 1 690232843 2 8 4 690232844 690232845 690232842 690232846
*/