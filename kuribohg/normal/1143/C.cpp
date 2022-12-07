#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=400010;
int n,p[MAXN],c[MAXN];
int ans[MAXN],tot;
bool ok[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&c[i]);
    for(int i=1;i<=n;i++) ok[i]=true;
    for(int i=1;i<=n;i++)
    {
        if(p[i]==-1) ok[i]=false;
        if(c[i]==0) ok[i]=false,ok[p[i]]=false;
    }
    for(int i=1;i<=n;i++)
        if(ok[i]) ans[++tot]=i;
    if(tot==0) puts("-1");
    else
    {
        for(int i=1;i<tot;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[tot]);
    }
    return 0;
}