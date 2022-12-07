#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100010],f[100010][3];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) f[i][0]=f[i][1]=f[i][2]=1000000000;
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1) f[i][1]=min(f[i][1],f[i-1][0]),f[i][1]=min(f[i][1],f[i-1][2]);
        if(a[i]&2) f[i][2]=min(f[i][2],f[i-1][0]),f[i][2]=min(f[i][2],f[i-1][1]);
        f[i][0]=min(f[i][0],f[i-1][0]+1);
        f[i][0]=min(f[i][0],f[i-1][1]+1);
        f[i][0]=min(f[i][0],f[i-1][2]+1);
    }
    printf("%d\n",min(f[n][0],min(f[n][1],f[n][2])));
    return 0;
}