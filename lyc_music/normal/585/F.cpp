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
#define mod 1000000007
#define int ll
#define N 100005 
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[100005][27];
int n;
int cnt;
// string st[N];
int fail[100005];
string S,sx,sy;
queue<int>q;
int pos[N],siz[100005];
poly G[100005];
int len;
int ed[100005];
int ans;
int dp[N][55][2];
int dp1[55][2];
void ad(int x,int y)
{
    G[x].push_back(y);
}
void add(int &x,int y)
{
    x=(x+y)%mod;
}
void dfs(int k)
{
    for (auto u:G[k])
    {
        dfs(u);
        siz[k]+=siz[u];
    }
}
void BellaKira()
{
    cin>>S;
    cin>>sx>>sy;
    len=sx.size();
    int p=len;
    while (sx[p-1]=='0') p--;
    sx[p-1]--;
    for (int i=p;i<len;i++) sx[i]='9';
    // cout<<sx<<" "<<sy<<endl;
    n=S.size();
    for (int i=0;i<10;++i) tr[0][i]=1;
    cnt=1;
    for (int i=0;i+len/2-1<n;i++)
    {
        int now=1;
        for (int j=i;j<=i+len/2-1;j++)
        {
            char u=S[j];
            if (!tr[now][u-'0'])
            {
                tr[now][u-'0']=++cnt;
            }
            now=tr[now][u-'0'];
            if (j-i+1==len/2) ed[now]=1;
            // cout<<now<<"!"<<endl;
        }
    }
    q.push(1);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<10;i++)
        {
            if (tr[u][i])
            {
                fail[tr[u][i]]=tr[fail[u]][i];
                q.push(tr[u][i]);
            } else tr[u][i]=tr[fail[u]][i];
        }
    }
    
    memset(dp,0,sizeof(dp));
    memset(dp1,0,sizeof(dp1));
    dp1[len+1][0]=dp1[len+1][1]=1;
    for (int i=len;i>=1;i--)
        dp1[i][0]=dp1[i+1][0]*10%mod,dp1[i][1]=(dp1[i+1][0]*(sx[i-1]-'0')%mod+dp1[i+1][1])%mod;
    dp[1][0][1]=1;
    for (int j=1;j<=len;j++)
        for (int i=1;i<=cnt;i++)
            if (!ed[i])
            for (int k=0;k<=1;k++)
            {
                if (k==0)
                {
                    for (int p=0;p<10;p++)
                        add(dp[tr[i][p]][j][0],dp[i][j-1][k]);
                } else
                {
                    for (int p=0;p<sx[j-1]-'0';p++)
                        add(dp[tr[i][p]][j][0],dp[i][j-1][k]);
                    for (int p=sx[j-1]-'0';p<=sx[j-1]-'0';p++)
                        add(dp[tr[i][p]][j][1],dp[i][j-1][k]);
                }
            }
    for (int i=1;i<=cnt;i++)
        if (ed[i])
        for (int j=1;j<=len;j++)
            for (int k=0;k<=1;k++)
            {
                // if (dp[i][j][k])
                    // cout<<"! "<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<" "<<dp1[j+1][k]<<endl;
                add(ans,mod-(dp[i][j][k]*dp1[j+1][k]%mod));
            }

    swap(sx,sy);
    memset(dp,0,sizeof(dp));
    memset(dp1,0,sizeof(dp1));
    dp1[len+1][0]=dp1[len+1][1]=1;
    for (int i=len;i>=1;i--)
        dp1[i][0]=dp1[i+1][0]*10%mod,dp1[i][1]=(dp1[i+1][0]*(sx[i-1]-'0')%mod+dp1[i+1][1])%mod;
    dp[1][0][1]=1;
    // writeln(mod-ans);
    // ans=0;
    for (int j=1;j<=len;j++)
        for (int i=1;i<=cnt;i++)
            if (!ed[i])
            for (int k=0;k<=1;k++)
            {
                if (k==0)
                {
                    for (int p=0;p<10;p++)
                        add(dp[tr[i][p]][j][0],dp[i][j-1][k]);
                } else
                {
                    for (int p=0;p<sx[j-1]-'0';p++)
                        add(dp[tr[i][p]][j][0],dp[i][j-1][k]);
                    for (int p=sx[j-1]-'0';p<=sx[j-1]-'0';p++)
                        add(dp[tr[i][p]][j][1],dp[i][j-1][k]);
                }
            }
    for (int i=1;i<=cnt;i++)
        if (ed[i])
        for (int j=1;j<=len;j++)
            for (int k=0;k<=1;k++)
            {
                // if (dp[i][j][k])
                //     cout<<"?"<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
                add(ans,(dp[i][j][k]*dp1[j+1][k]%mod));
            }
    writeln(ans);
}
signed main()
{
    IOS;
    int T=1;
    BellaKira();
}
/*

*/