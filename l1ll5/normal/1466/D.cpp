#include <bits/stdc++.h>
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
int T;
int n,w[N];
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
int deg[N];
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
priority_queue<pr> q;/*
void dfs(int x,int fa){
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue ;
        dfs(to,x);
        deg[x]++;
    }
    cerr<<x<<' '<<deg[x]<<endl;
    q.push(mp(w[x],deg[x]));
}*/
int main()
{
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++) w[i]=read();
        for(int i=1;i<=n-1;i++) {
            int u=read(),v=read();
        //    add(u,v),add(v,u);
            deg[u]++,deg[v]++;
        }
        //dfs(1,0);
        long long ans=0;
        for(int i=1;i<=n;i++) ans+=w[i];
        for(int i=1;i<=n;i++) {
            if(deg[i]>1) q.push(make_pair(w[i],deg[i]));
        }
        for(int i=1;i<=n-1;i++) {
            printf("%lld ",ans);
            if(i==n-1) break ;
            pr x=q.top(); q.pop();
            x.se--;
            ans+=x.fi;
            if(x.se!=1) q.push(x);
        }
        puts("");

        for(int i=1;i<=n;i++) head[i]=deg[i]=0; cnt=1;
        while(!q.empty()) q.pop();
    }
}