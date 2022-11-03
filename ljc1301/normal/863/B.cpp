#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=105;
int n,m,a[maxn],f[maxn][maxn];
int main()
{
    int i,j,k;
    scanf("%d",&n); m=n-1; n*=2;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    memset(f[0],0,sizeof(f[0]));
    for(i=1;i<=m;i++)
        for(j=2,f[i][0]=f[i][1]=1000000000;j<=n;j++)
        {
            f[i][j]=f[i][j-1];
            for(k=1;k<j;k++)
                f[i][j]=min(f[i][j],f[i-1][k-1]+a[j]-a[k]);
        }
    printf("%d\n",f[m][n]);
    return 0;
}