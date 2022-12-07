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
const int maxn=200005;
int xs[2][maxn],n,m;

int jc[maxn],ny[maxn];

int mi(int x,int y)
{
    int ret=1;
    while(y>0)
    {
        if(y&1)ret=1ll*ret*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ret;
}

int c(int x,int y)
{return 1ll*(1ll*jc[x]*ny[y]%mod)*ny[x-y]%mod;}

void solve(int t,int p)
{
    xs[t^1][1]=1;
    for(int i=2;i<=p;i++)
        if(!(p&1))
        {
            if(i&1)xs[t^1][i]=(xs[t][i-1]+xs[t][i])%mod;
            else xs[t^1][i]=(xs[t][i-1]-xs[t][i]+mod)%mod;
        }else
        {
            if(i&1)xs[t^1][i]=(xs[t][i]-xs[t][i-1]+mod)%mod;
            else xs[t^1][i]=(xs[t][i-1]+xs[t][i])%mod;
        }
}

int main()
{
    jc[0]=1;for(int i=1;i<=200000;i++)jc[i]=1ll*i*jc[i-1]%mod;
    ny[200000]=mi(jc[200000],mod-2);for(int i=199999;i>=0;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
    scanf("%d",&n);
    m=0;
    while(4*m+1<=n)m++;
    m--;
    int now=0;
    for(int i=1;i<=4*m+1;i++)if(i&1)xs[now][i]=c(2*m,i>>1);else xs[now][i]=0;
    /*printf("%d\n",4*m+1);
    for(int i=1;i<=4*m+1;i++)printf("%d ",xs[now][i]);
    printf("\n");*/
    for(int i=4*m+2;i<=n;i++)
    {
        now^=1;
        solve(now^1,i);
        /*printf("%d\n",i);
        for(int j=1;j<=i;j++)printf("%d ",xs[now][j]);
        printf("\n");*/
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=1ll*xs[now][i]*x%mod;
        sum%=mod;
    }
    printf("%d\n",sum);
    return 0;
}