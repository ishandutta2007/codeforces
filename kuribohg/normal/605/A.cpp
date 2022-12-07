#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,a[MAXN],pos[MAXN],f[MAXN],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
    for(int i=1;i<=n;i++)
        if(pos[i]>=pos[i-1]) f[i]=f[i-1]+1;
        else f[i]=1;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]);
    printf("%d\n",n-ans);
    return 0;
}