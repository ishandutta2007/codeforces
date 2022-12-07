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
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
  
const int maxn=2055;
using namespace std;
const int M=998244353;
LL dp[maxn][maxn],inv[maxn],nf[maxn],f[maxn],w;
int n,a[maxn][maxn],b[maxn],c[maxn],d[maxn],h[maxn],g[maxn];
LL res,ans,cnt,cc;
bool u[maxn],v[maxn];

int qry(int x)
{
    int ret=0;
    while (x) ret+=g[x],x-=x&(-x);
    return ret;
}

void add(int x,int y)
{
    while (x<maxn) g[x]+=y,x+=x&(-x);
}

int qry2(int x)
{
    int ret=0;
    while (x) ret+=h[x],x-=x&(-x);
    return ret;
}

void add2(int x,int y)
{
    while (x<maxn) h[x]+=y,x+=x&(-x);
}

int main(){
    dp[0][0]=1;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    for (int j=0;j<=i;j++)
    {
        (dp[i+1][j]+=dp[i][j])%=M;
        if (i==j) continue;
        (dp[i+1][j+1]+=2LL*(i-j)*dp[i][j])%=M;
        (dp[i+1][j+2]+=(LL)(i-j)*(i-j)*dp[i][j])%=M;
    }
    inv[1]=1; for (int i=2;i<=n;i++) inv[i]=M-(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<=n;i++) f[i]=f[i-1]*i%M,nf[i]=nf[i-1]*inv[i]%M;

    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++)
            dp[i][j]=dp[i][j]*nf[i]%M*f[j]%M*f[i-j]%M*f[i-j]%M;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    w=1;
    for (int i=n-1;i>=1;i--)
    {
        for (int j=1;j<=n;j++) b[j]=0,c[j]=a[i][j],d[j]=a[i+1][j],g[j]=h[j]=u[j]=v[j]=0;
        for (int j=1;j<=n;j++)
        {
            if (v[c[j]]) cc++;
            int o=d[j]-1,x=qry(o),y=qry2(o);
            (res+=(o-x-y)*dp[n-j][n-j*2+cc]+x*dp[n-j][n-j*2+cc+1])%=M;
            if (c[j]<d[j]&&!v[c[j]]) (res+=M-dp[n-j][n-j*2+cc])%=M;
            if (u[d[j]]) cc++;
            u[c[j]]=1;
            if (u[c[j]]&&!v[c[j]]) add(c[j],1);
            v[d[j]]=1;
            if (u[d[j]]&&v[d[j]]) add(d[j],-1);
            add2(d[j],1);
        }
        (ans+=res*w)%=M;
        w=w*dp[n][n]%M; res=cnt=cc=0;
    }
    memset(g,0,sizeof(g));
    for (int i=1;i<=n;i++)
    {
        int o=a[1][i]-1;
        (res+=(o-qry(o))*f[n-i])%=M;
        add(a[1][i],1);
    }
    (ans+=res*w)%=M;
    printf("%lld\n",(ans+M)%M);
    return 0;
}