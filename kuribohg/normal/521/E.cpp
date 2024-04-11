#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
using namespace std;
const int MAXN=1000010;
int n,m;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int fa[MAXN],dep[MAXN],dfn[MAXN],dfs_clock;
bool ok;
pair<int,int> Cir[MAXN];
vector<int> v1,v2,v3;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void Print(int p1,int q1,int p2,int q2,int x)
{
    if(ok) return;
    ok=true;
    if(dep[q1]>dep[q2]) swap(p1,p2),swap(q1,q2);
    int p=x;
    while(p!=q2) v1.push_back(p),p=fa[p];
    v1.push_back(p);
    p=p2;
    while(p!=x) v2.push_back(p),p=fa[p];
    v2.push_back(p);
    reverse(v2.begin(),v2.end());
    v2.push_back(q2);
    p=q2;
    while(p!=q1) v3.push_back(p),p=fa[p];
    v3.push_back(p);
    p=p1;
    while(p!=x) v3.push_back(p),p=fa[p];
    v3.push_back(p);
    reverse(v3.begin(),v3.end());
    puts("YES");
    printf("%d ",v1.size());
    for(int i=0;i<v1.size();i++) printf("%d ",v1[i]);
    puts("");
    printf("%d ",v2.size());
    for(int i=0;i<v2.size();i++) printf("%d ",v2[i]);
    puts("");
    printf("%d ",v3.size());
    for(int i=0;i<v3.size();i++) printf("%d ",v3[i]);
    puts("");
    exit(0);
}
void DFS(int x,int father)
{
    dfn[x]=++dfs_clock;
    for(int i=head[x];i;i=next[i])
        if((i^father)!=1)
        {
            if(!dfn[to[i]]) dep[to[i]]=dep[x]+1,fa[to[i]]=x,DFS(to[i],i);
            else if(dfn[to[i]]<=dfn[x])
            {
                int p=x;
                while(p!=to[i])
                {
                    if(Cir[p].first) Print(Cir[p].first,Cir[p].second,x,to[i],p);
                    Cir[p]=make_pair(x,to[i]),p=fa[p];
                }
            }
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y);
    for(int i=1;i<=n;i++)
        if(!dfn[i]) DFS(i,0);
    if(!ok) puts("NO");
    return 0;
}