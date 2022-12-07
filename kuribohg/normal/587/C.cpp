#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=200010;
int n,m,Q,c[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int Log[MAXN],anc[MAXN][20],dep[MAXN];
vector<int> v[MAXN],a[MAXN][20];
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
vector<int> Merge(const vector<int> &p,const vector<int> &q)
{
    vector<int> res;
    res.clear();
    int x=0,y=0;
    while((int)res.size()<=10)
    {
        if(x==(int)p.size()&&y==(int)q.size()) break;
        if(x==(int)p.size()||y!=(int)q.size()&&q[y]<p[x]) res.push_back(q[y]),y++;
        else res.push_back(p[x]),x++;
    }
    return res;
}
void DFS(int x)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=anc[x][0])
        {
            dep[to[i]]=dep[x]+1;
            anc[to[i]][0]=x;
            DFS(to[i]);
        }
}
int LCA(int p,int q)
{
    if(dep[p]<dep[q]) swap(p,q);
    int d=dep[p]-dep[q];
    for(int i=Log[d];i>=0;i--)
        if(d&(1<<i)) p=anc[p][i];
    for(int i=Log[n];i>=0;i--)
        if(anc[p][i]!=anc[q][i]) p=anc[p][i],q=anc[q][i];
    if(p!=q) return anc[p][0];
    else return p;
}
vector<int> Query(int p,int q)
{
    vector<int> res;
    res.clear();
    int d=dep[p]-dep[q];
    for(int i=Log[d];i>=0;i--)
        if(d&(1<<i)) res=Merge(res,a[p][i]),p=anc[p][i];
    return res;
}
void Print(const vector<int> &p,int a)
{
    int x=min((int)p.size(),a);
    printf("%d ",x);
    for(int i=0;i<x;i++) printf("%d ",p[i]);
    puts("");
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&c[i]);
        if((int)a[c[i]][0].size()<10) a[c[i]][0].push_back(i);
    }
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    DFS(1);
    for(int i=1;i<=Log[n];i++)
        for(int j=1;j<=n;j++)
        {
            anc[j][i]=anc[anc[j][i-1]][i-1];
            a[j][i]=Merge(a[j][i-1],a[anc[j][i-1]][i-1]);
        }
    while(Q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int lca=LCA(x,y);
        vector<int> res;
        res.clear();
        res=Merge(Query(x,lca),Query(y,lca));
        res=Merge(res,a[lca][0]);
        Print(res,z);
    }
    return 0;
}