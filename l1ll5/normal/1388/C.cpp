#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n,m;
struct zgz
{
    int next,to;
}edge[N<<1];
int cnt=1,head[N];
void add(int from,int to)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
int p[N];
int h[N];
int sz[N];
int fa[N];
void dfs(int x,int f){
    sz[x]=p[x];
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==f) continue ;
        fa[to]=x;
        dfs(to,x);
        sz[x]+=sz[to];
    }
}
int good[N];
int bad[N];
bool ok=1;
void check(int x){
    int tg=sz[x]+h[x];
    if(tg<0) ok=0;
    if(tg%2==1) ok=0;

    good[x]=tg/2;
    bad[x]=sz[x]-good[x];

    if(good[x]<0) ok=0;
    if(bad[x]<0) ok=0;

    if(!ok) return ;

    int sumgood=0;
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa[x]) continue ;
        check(to);
        sumgood+=good[to];
    }
    if(sumgood>good[x]) ok=0;
}
void clear(){
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<=n;i++) fa[i]=p[i]=sz[i]=h[i]=good[i]=bad[i]=0;
    cnt=1;
}
 main()
{
    T=read();
    while(T--){
        ok=1;
        n=read(),m=read();
        for(int i=1;i<=n;i++) p[i]=read();
        for(int i=1;i<=n;i++) h[i]=read();
        for(int i=1;i<=n-1;i++){
            int x=read(),y=read();
            add(x,y),add(y,x);
        }
        dfs(1,0);
        check(1);

        if(!ok)puts("NO");
        else puts("YES");
        clear();
    }
}