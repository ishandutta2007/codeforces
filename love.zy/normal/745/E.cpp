#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
int a[70005][3][300];
struct info
{
    int red,blue;
    int xx;
}b[20],d[20];
vector<int> g[20];
int i,j,k,l,m,n,r,tot,ans;
int sum[3];
char c;
int xl,xr;

int main()
{
    l=0;
    scanf("%d\n",&n);m=n*n;
    for(i=1;i<=n;i++)
    {
        scanf("%c %d %d\n",&c,&b[i].red,&b[i].blue);
        if(c=='R')b[i].xx=1;else b[i].xx=2;
        if(b[i].red>=n || b[i].blue>=n)
        {
            xl+=max(0,b[i].red-n);
            xr+=max(0,b[i].blue-n);
            b[i].red=min(n,b[i].red);
            b[i].blue=min(n,b[i].blue);
        }
    }
    for(i=0;i<(1<<n);i++)
    {
        j=i;k=0;
        while(j>0)
        {
            if(j&1)k++;
            j>>=1;
        }
        g[k].push_back(i);
    }
    for(i=0;i<(1<<n);i++)
        for(j=0;j<=n*n;j++)
            a[i][1][j]=a[i][2][j]=1e9;
    //if(xl>xr)a[0][2][xl-xr]=0;else a[0][1][xr-xl]=0;
    if(xl>xr)a[0][1][min(xl-xr,n*n)]=0;else a[0][2][min(xr-xl,n*n)]=0;
    if(xl==xr)a[0][1][0]=a[0][2][0]=0;
    for(int w=1;w<=n;w++)
    {
        for(i=0;i<g[w].size();i++)
        {
            int now=g[w][i];
            sum[1]=sum[2]=0;
            for(j=0;j<n;j++)if((now & (1<<j)))sum[b[j+1].xx]++;
            for(j=0;j<n;j++)
            {
                if((now & (1<<j))==0)continue;
                l=sum[1];r=sum[2];
                if(b[j+1].xx==1)l--;else r--;
                int la=now^(1<<j);
                //printf("%d %d\n",now,la);
                for(k=0;k<=n*n;k++)
                {
                    if(a[la][1][k]<1e9)
                    {
                        int nl=0,nr=k;
                        int nred=max(0,b[j+1].red-l-nl);
                        int nblue=max(0,b[j+1].blue-r-nr);
                        tot=max(nred,nblue);
                        int re=tot+nl-max(0,b[j+1].red-l);
                        int bl=tot+nr-max(0,b[j+1].blue-r);
                        if(re==0)a[now][1][min(bl,n*n)]=min(a[now][1][min(bl,n*n)],a[la][1][k]+tot);
                        if(bl==0)a[now][2][min(re,n*n)]=min(a[now][2][min(re,n*n)],a[la][1][k]+tot);
                    }
                    if(a[la][2][k]<1e9)
                    {
                        int nl=k,nr=0;
                        int nred=max(0,b[j+1].red-l-nl);
                        int nblue=max(0,b[j+1].blue-r-nr);
                        tot=max(nred,nblue);
                        int re=tot+nl-max(0,b[j+1].red-l);
                        int bl=tot+nr-max(0,b[j+1].blue-r);
                        if(re==0)a[now][1][min(bl,n*n)]=min(a[now][1][min(bl,n*n)],a[la][2][k]+tot);
                        if(bl==0)a[now][2][min(re,n*n)]=min(a[now][2][min(re,n*n)],a[la][2][k]+tot);
                    }
                }
            }
        }
    }
    l=r=0;k=(1<<n)-1;
    ans=1e9;
    for(i=0;i<=n*n;i++)
    {
        ans=min(ans,a[k][1][i]);
        ans=min(ans,a[k][2][i]);
    }
    //for(i=0;i<=n*n;i++)printf("%d %d %d\n",i,a[k][1][i],a[k][2][i]);
    printf("%d",ans+n+max(xl,xr));
    return 0;
}