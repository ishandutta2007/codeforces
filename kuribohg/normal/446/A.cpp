#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,a[100010],f[100010][2][2],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) f[i][0][0]=f[i][1][1]=1,f[i][1][0]=2;
    f[1][1][0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            f[i][0][0]=max(f[i][0][0],f[i-1][0][0]+1);
            f[i][1][0]=max(f[i][1][0],f[i-1][1][0]+1);
            f[i][1][1]=max(f[i][1][1],f[i-1][0][0]+1);
        }
        else f[i][1][1]=max(f[i][1][1],f[i-1][0][0]+1);
        if(i!=1&&a[i]>a[i-2]+1) f[i][1][0]=max(f[i][1][0],f[i-1][1][1]+1);
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[i][0][0]);
        ans=max(ans,f[i][1][0]);
        ans=max(ans,f[i][1][1]);
    }
    printf("%d\n",ans);
    return 0;
}