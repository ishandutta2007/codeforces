#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct zgz
{
    int next,to,val;
}edge[N<<1];
int cnt=1,head[N];
void add(int from,int to)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
int n;
int deg[N];
int dfn[N],tag;
int dep[N];
vector<int> v;
int anc[N][17];
int ol[N];
void dfs(int x,int f)
{
    dfn[x]=++tag;
    int son=0;
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==f) continue ;
        anc[to][0]=x;
        dep[to]=dep[x]+1;
        dfs(to,x);
        son++;
    }
    if(son==0)v.push_back(x),ol[f]++;


}

int get_lca(int x,int y)
{
    if(dep[y]>dep[x])swap(x,y);
    for(int i=16;i>=0;i--)
    if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
    if(x==y)return x;
    for(int i=16;i>=0;i--)
    if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}
int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {
        int a=read(),b=read();
        add(a,b),add(b,a);
        deg[a]++,deg[b]++;
    }

    int root=0;
    for(int i=1;i<=n;i++)
    if(deg[i]!=1) {
        root=i; break ;
    }

    dep[root]=1;
    anc[root][0]=root;

    dfs(root,0);

    for(int j=1;j<=16;j++)
    for(int i=1;i<=n;i++)anc[i][j]=anc[anc[i][j-1]][j-1];

    int ans=0;
    bool flag=1;

    //cerr<<v[0]<<' '<<v[1]<<' '<<v[2]<<endl;

    int tmp=get_lca(v[0],v[1]);
    ans+=dep[v[0]]-dep[tmp];

    //cerr<<v[0]<<' '<<v[1]<<' '<<v[2]<<endl;

    //cerr<<ans<<endl;

    int lst=ans;

    for(int i=1;i<v.size();i++)
    {
        int lca=get_lca(v[i],v[i-1]);

        int dis=dep[v[i]]+dep[v[i-1]]-2*dep[lca];

    //    cerr<<v[i]<<' '<<v[i-1]<<' '<<lca<<endl;


        if(dis%2==0) {

        }
        else {
            flag=0;
        }

    //    cerr<<dep[v[i]]-dep[lca]<<' '<<v[i]<<' '<<lca<<endl;

        if(lst==1 && dis==2)
        {

        }
        else {
            ans+=dis-lst;
        }

        lst=dis-lst;
    }

    int ans1=0;
    if(flag) ans1=1;
    else ans1=3;


    ans=n-1;
    for(int i=1;i<=n;i++)
    {
        if(ol[i]>1)
        ans-=(ol[i]-1);
    }

    printf("%d %d\n",ans1,ans);
}