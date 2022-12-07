#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,k,a[MAXN];
LL BIT[MAXN][12],f[MAXN][12],ans;
inline void Change(int o,int x,LL tar)
{
    for(int i=x;i<=n+1;i+=(i&(-i)))
        BIT[i][o]+=tar;
}
inline LL Query(int o,int x)
{
    LL con=0;
    for(int i=x;i;i^=(i&(-i)))
        con+=BIT[i][o];
    return con;
}
int main()
{
    scanf("%d%d",&n,&k);
    k++;
    for(int i=2;i<=n+1;i++) scanf("%d",&a[i]);
    f[0][0]=1;
    Change(0,1,1);
    for(int i=2;i<=n+1;i++)
        for(int j=1;j<=k;j++)
        {
            f[i][j]=Query(j-1,a[i]);
            Change(j,a[i]+1,f[i][j]);
        }
    for(int i=2;i<=n+1;i++) ans+=f[i][k];
    printf("%I64d\n",ans);
    return 0;
}