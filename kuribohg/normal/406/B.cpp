#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,s=1000000,x[MAXN],ans[MAXN],tot,cnt;
bool used[MAXN],P[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]),used[x[i]]=true;
    for(int i=1;i<=n;i++)
        if(!used[s+1-x[i]]) ans[++tot]=s+1-x[i],P[min(x[i],s+1-x[i])]=true;
        else cnt++,P[min(x[i],s+1-x[i])]=true;
    cnt/=2;
    for(int i=1;i<=500000;i++)
        if(cnt&&!P[i]) cnt--,ans[++tot]=i,ans[++tot]=s+1-i;
    sort(ans+1,ans+tot+1);
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}