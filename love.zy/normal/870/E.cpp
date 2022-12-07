/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int mod=1e9+7;
const int maxn=100005;
int mi[maxn*2],n;
int lsh[maxn<<1],ls[maxn<<1],cc;
vi g[maxn];
vector < pii > s1[maxn<<1],s2[maxn<<1];
int col[maxn],cnt=0,tot[maxn];
vi s[maxn];
int v1[maxn*2],v2[maxn*2];

struct point
{
    int x,y;
    void read(int u)
    {
        scanf("%d%d",&x,&y);
        lsh[2*u-1]=x;
        lsh[2*u]=y;
    }
    void adjust()
    {
        x=lower_bound(ls+1,ls+cc+1,x)-ls;
        y=lower_bound(ls+1,ls+cc+1,y)-ls;
    }
}a[maxn];

void DFS(int u,int c)
{
    col[u]=c;
    s[c].pb(u);
    tot[c]+=(int)g[u].size();
    for(int p : g[u])
        if(!col[p])DFS(p,c);
}

int main()
{
    mi[0]=1;
    scanf("%d",&n);
    for(int i=1;i<=2*n+1;i++)mi[i]=mi[i-1]*2%mod;
    for(int i=1;i<=n;i++)a[i].read(i);
    sort(lsh+1,lsh+2*n+1);
    ls[cc=1]=lsh[1];
    for(int i=2;i<=2*n;i++)
        if(lsh[i]!=lsh[i-1])ls[++cc]=lsh[i];
    for(int i=1;i<=n;i++)
    {
        a[i].adjust();
        s1[a[i].x].pb(mp(a[i].y,i));
        s2[a[i].y].pb(mp(a[i].x,i));
    }
    for(int i=1;i<=cc;i++)
    {
        sort(s1[i].begin(),s1[i].end());
        int l=s1[i].size();
        for(int j=1;j<l;j++)
        {
            g[s1[i][j].se].pb(s1[i][j-1].se);
            g[s1[i][j-1].se].pb(s1[i][j].se);
        }
        sort(s2[i].begin(),s2[i].end());
        l=s2[i].size();
        for(int j=1;j<l;j++)
        {
            g[s2[i][j].se].pb(s2[i][j-1].se);
            g[s2[i][j-1].se].pb(s2[i][j].se);
        }
    }
    for(int i=1;i<=n;i++)
        if(!col[i])DFS(i,++cnt);
    int ans=1;
    for(int i=1;i<=cnt;i++)
    {
        if((int)s[i].size()==1){ans=1ll*ans*3%mod;continue;}
        int sum=0;
        for(int p : s[i])
        {
            if(v1[a[p].x]!=i){v1[a[p].x]=i;sum++;}
            if(v2[a[p].y]!=i){v2[a[p].y]=i;sum++;}
        }
        tot[i]>>=1;
        if(tot[i]>=(int)s[i].size())ans=1ll*ans*mi[sum]%mod;
        else ans=1ll*ans*(mi[sum]-1)%mod;
    }
    printf("%d\n",ans);
    return 0;
}