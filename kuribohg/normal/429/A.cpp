#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
//#define DEBUG
using namespace std;
const int MAXN=100010;
struct Node
{
    int num[2];
}tree[MAXN<<2];
vector<int> graph[MAXN];
queue<int> q;
int n,in1,in2,a[MAXN],b[MAXN],fa[MAXN],dep[MAXN];
int seq[MAXN],tot,l[MAXN],r[MAXN],seqBFS[MAXN],seqPOS[MAXN];
int ans[MAXN];
bool used[MAXN];
void DFS(int x)
{
    int len=graph[x].size();
    seq[++tot]=x;
    l[x]=tot;
    for(int i=0;i<len;i++)
    {
        int t=graph[x][i];
        if(t!=fa[x])
        {
            dep[t]=dep[x]+1;
            fa[t]=x;
            DFS(t);
        }
    }
    r[x]=tot;
}
inline void BFS()
{
    seqBFS[++tot]=1;
    used[1]=true;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front(),len=graph[x].size();
        q.pop();
        for(int i=0;i<len;i++)
        {
            int t=graph[x][i];
            if(!used[t])
            {
                used[t]=true;
                seqBFS[++tot]=t;
                q.push(t);
            }
        }
    }
}
inline void pushdown(int x)
{
    int ls=x<<1,rs=x<<1|1;
    tree[ls].num[1]^=tree[x].num[1];
    tree[ls].num[0]^=tree[x].num[0];
    tree[rs].num[1]^=tree[x].num[1];
    tree[rs].num[0]^=tree[x].num[0];
    tree[x].num[0]=tree[x].num[1]=0;
}
void change(int x,int l,int r,int head,int tail,int tar)
{
    if(l==head&&r==tail)
    {
        tree[x].num[tar]^=1;
        return;
    }
    pushdown(x);
    int m=(l+r)>>1;
    if(tail<=m) change(x<<1,l,m,head,tail,tar);
    else if(head>m) change(x<<1|1,m+1,r,head,tail,tar);
    else
    {
        change(x<<1,l,m,head,m,tar);
        change(x<<1|1,m+1,r,m+1,tail,tar);
    }
}
Node query(int x,int l,int r,int pos)
{
    if(l==r) return tree[x];
    pushdown(x);
    int m=(l+r)>>1;
    if(pos<=m) return query(x<<1,l,m,pos);
    else return query(x<<1|1,m+1,r,pos);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&in1,&in2);
        graph[in1].push_back(in2);
        graph[in2].push_back(in1);
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    dep[1]=1;
    DFS(1);
    tot=0;
    BFS();
    for(int i=1;i<=n;i++) seqPOS[seq[i]]=i;
    tot=0;
#ifdef DEBUG
    for(int i=1;i<n;i++) printf("%d ",seq[i]);
    printf("%d\n",seq[n]);
    for(int i=1;i<n;i++) printf("%d ",seqBFS[i]);
    printf("%d\n",seqBFS[n]);
    for(int i=1;i<n;i++) printf("%d ",seqPOS[i]);
    printf("%d\n",seqPOS[n]);
    for(int i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
#endif
    for(int i=1;i<=n;i++)
    {
        int op=seqPOS[seqBFS[i]],opnum=seqBFS[i];
        Node p=query(1,1,n,op);
        if(a[opnum]^p.num[dep[opnum]&1]!=b[opnum])
        {
            ans[++tot]=opnum;
            change(1,1,n,l[opnum],r[opnum],dep[opnum]&1);
        }
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
        printf("%d\n",ans[i]);
    return 0;
}