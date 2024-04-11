#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MAXN=30010;
int f[30010][1510];
int n,d,a[MAXN],x,ans;
int main()
{
    scanf("%d%d",&n,&d);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++) scanf("%d",&x),a[x]++;
    f[d][1000+d-d]=a[d],ans=a[d];
    for(int i=d;i<=30000;i++)
    {
        for(int j=1;j<=1500;j++)
        {
            int len=j+d-1000,D=f[i][j];
            if(f[i][j]==-1) continue;
            if(i+len<=30000) f[i+len][1000+len-d]=max(f[i+len][1000+len-d],D+a[i+len]),ans=max(ans,f[i+len][1000+len-d]);
            if(i+len+1<=30000) f[i+len+1][1000+len+1-d]=max(f[i+len+1][1000+len+1-d],D+a[i+len+1]),ans=max(ans,f[i+len+1][1000+len+1-d]);
            if(len!=1&&i+len-1<=30000)
                f[i+len-1][1000+len-1-d]=max(f[i+len-1][1000+len-1-d],D+a[i+len-1]),ans=max(ans,f[i+len-1][1000+len-1-d]);
        }
    }
    printf("%d\n",ans);
    return 0;
}