#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000010
using namespace std; 
int ans,n,vis[N],f[N],a[N];
int main(){
//  freopen("test.in","r",stdin);
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),vis[a[i]]=i;
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
        for (int j=2*a[i];j<=a[n];j+=a[i]) if (vis[j]) f[vis[j]]=max(f[vis[j]],f[i]+1);
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans+1;
    return 0;
}