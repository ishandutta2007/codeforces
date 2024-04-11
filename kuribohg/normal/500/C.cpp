#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100010;
int n,m,w[MAXN],op[MAXN],p[MAXN],tot,ans,sub;
bool used[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=m;i++) scanf("%d",&op[i]);
    for(int i=1;i<=m;i++)
        if(!used[op[i]]) used[op[i]]=true,p[++tot]=op[i];
    for(int i=1;i<=n;i++) if(!used[i]) p[++tot]=i;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++) if(p[j]==op[i]) sub=j;
        for(int j=1;j<sub;j++) ans+=w[p[j]];
        for(int j=sub;j>=2;j--) p[j]=p[j-1];
        p[1]=op[i];
    }
    printf("%d\n",ans);
    return 0;
}