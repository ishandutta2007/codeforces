#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
vector<int> graph[100010];
int n,m,in1,in2,odd[100010],p,ans[500010],tot,flood[100010];
bool used[100010];
void fill(int x,int c)
{
    flood[x]=c,used[x]=true;
    int len=graph[x].size();
    for(int i=0;i<len;i++)
    {
        int t=graph[x][i];
        if(!used[t]) fill(t,c);
    }
}
void add(int x)
{
    ans[++tot]=x;
    odd[x]^=1;
}
void DFS(int x,int fa)
{
    used[x]=true;add(x);
    int len=graph[x].size();
    for(int i=0;i<len;i++)
    {
        int t=graph[x][i];
        if(!used[t]) {DFS(t,x);add(x);}
    }
    if(odd[x]&&fa!=-1) add(fa),add(x);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&in1,&in2);
        graph[in1].push_back(in2);
        graph[in2].push_back(in1);
    }
    for(int i=1;i<=n;i++) scanf("%d",&odd[i]);
    for(int i=1;i<=n;i++) if(!used[i]) fill(i,++tot);
    for(int i=1;i<=n;i++) used[i]=false;
    tot=0;
    for(int i=1;i<=n;i++)
        if(!used[flood[i]]&&odd[i]) used[flood[i]]=true,tot++,p=i;
    if(tot>=2) {puts("-1");return 0;}
    if(tot==0) {puts("0");return 0;}
    tot=0;
    for(int i=1;i<=n;i++) used[i]=false;
    DFS(p,-1);
    if(odd[p]) printf("%d\n",tot-1);
    else printf("%d\n",tot);
    for(int i=(odd[p]?2:1);i<tot;i++) printf("%d ",ans[i]);
    if(tot>=(odd[p]?2:1)) printf("%d\n",ans[tot]);
    return 0;
}