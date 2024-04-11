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
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dfn[N],rdfn[N];
vector<pa>G[N],E[N];
int cnt;
int fail[N];
int tr1[N];
int DFN;
poly Ge[N];
int pos[N];
string st[N];
int n,qq;
int tr[N][26];
int ans[N*3];
void upd(int x,int y)
{
    // cout<<"upd "<<x<<" "<<y<<endl;
    for (;x<=DFN;x+=x&-x)
    {
        tr1[x]+=y;
    }
}
int query(int x)
{
    int res=0;
    // cout<<"query "<<x<<" ";
    for (;x;x-=x&-x)
    {
        res+=tr1[x];
    }
    // cout<<res<<endl;
    return res;
}
void ad(int x,int y)
{
    Ge[x].push_back(y);
}
void dfs(int k)
{
    dfn[k]=++DFN;
    // cout<<k<<" "<<dfn[k]<<endl;
    for (auto u:Ge[k])
    {
        dfs(u);
    }
    rdfn[k]=DFN;
    // cout<<k<<" "<<dfn[k]<<" "<<rdfn[k]<<endl;
}
void BellaKira()
{
    cin>>n>>qq;
    for (int i=0;i<26;i++) tr[0][i]=1;
    cnt=1;
    for (int i=1;i<=n;i++)
    {
        cin>>st[i];
        int now=1;
        for (auto u:st[i])
        {
            if (!tr[now][u-'a'])
            {
                tr[now][u-'a']=++cnt;
            }
            now=tr[now][u-'a'];
        }
        pos[i]=now;
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
            }
            else tr[u][i]=tr[fail[u]][i];
        }
    }
    for (int i=2;i<=cnt;i++) ad(fail[i],i);
    dfs(1);
    for (int i=1;i<=qq;i++)
    {
        static int l,r,x;
        cin>>l>>r>>x;
        G[l-1].push_back(mp(x,i));
        E[r].push_back(mp(x,i));
    }
    for (int i=1;i<=n;i++)
    {
        int now=1;
        for (auto u:st[i])
        {
            now=tr[now][u-'a'];
            upd(dfn[now],1);
        }
        for (auto U:G[i])
        {
            int x=U.fi,y=U.se;
            ans[y]-=query(rdfn[pos[x]])-query(dfn[pos[x]]-1);
        }
        for (auto U:E[i])
        {
            int x=U.fi,y=U.se;
            ans[y]+=query(rdfn[pos[x]])-query(dfn[pos[x]]-1);
        }
    }
    for (int i=1;i<=qq;i++) cout<<ans[i]<<endl;
}
signed main()
{
    IOS;
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*

*/