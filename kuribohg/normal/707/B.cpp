#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,m,k,ans=1000000010;
int x[MAXN],y[MAXN],w[MAXN];
int c[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&x[i],&y[i],&w[i]);
    for(int i=1,xx;i<=k;i++) scanf("%d",&xx),c[xx]=1;
    for(int i=1;i<=m;i++) if(c[x[i]]+c[y[i]]==1) ans=min(ans,w[i]);
    if(ans==1000000010) ans=-1;
    printf("%d\n",ans);
    return 0;
}