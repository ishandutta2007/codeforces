#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,f[MAXN],t[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+20;
        int o=upper_bound(t+1,t+n+1,t[i]-90)-t;
        f[i]=min(f[i],f[o-1]+50);
        o=upper_bound(t+1,t+n+1,t[i]-1440)-t;
        f[i]=min(f[i],f[o-1]+120);
    }
    for(int i=1;i<=n;i++) printf("%d\n",f[i]-f[i-1]);
    return 0;
}