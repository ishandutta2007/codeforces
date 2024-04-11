#include<bits/stdc++.h>
#define rg register
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int inf=1e9;
const int N=1.1e4+5;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return f*x;
}
struct node{
    int to,next,v,w;
}a[2000001];
int head[N],cnt=1,n,m,s,t,x,y,z,tot,minx,maxx,dis[N],f[N],pre[10001],fa[10001];
void add(int x,int y,int c,int v){
    a[++cnt].to=y,a[cnt].next=head[x],a[cnt].v=c,a[cnt].w=v,head[x]=cnt;
    a[++cnt].to=x,a[cnt].next=head[y],a[cnt].v=0,a[cnt].w=-v,head[y]=cnt;
}
queue<int>q;
int spfa(){
    q.push(s);
    memset(dis,127,sizeof(dis));
    memset(f,0,sizeof(f));
    f[s]=1,dis[s]=0;
    int inf=dis[s+1];
    while(!q.empty()){
        int now=q.front();
        q.pop();
        f[now]=0;
        for(int i=head[now];i;i=a[i].next){
            int v=a[i].to;
            if(dis[v]>dis[now]+a[i].w&&a[i].v){
                dis[v]=dis[now]+a[i].w,pre[v]=i,fa[v]=now;
                if(!f[v])
                    f[v]=1,q.push(v);
            }
        }
    }
    if(dis[t]!=inf)
        return 1;
    return 0;
}
int ans1,ans;
void answer(){
    while(spfa()){
        int minx=2147483647;
        for(int i=t;i!=s;i=fa[i])
            minx=min(minx,a[pre[i]].v);
        ans+=minx,ans1+=dis[t]*minx;
        for(int i=t;i!=s;i=fa[i])
            a[pre[i]].v-=minx,a[pre[i]^1].v+=minx;
    }
}
int M[1001][1001],vis[1001][1001];
int main(){
    n=read();
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		M[i][j]=(i==j)?0:2;
    	}
    }
    s=0,tot=n;
    m=read();
    for (int i=0;i<m;i++) {
    	int u=read(),v=read();
    	M[u][v]=1; M[v][u]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++){
            tot++,add(s,tot,1,0);
            if(M[i][j]!=1) add(tot,i,1,0),vis[j][i]=cnt-1;
            if(M[i][j]!=0) add(tot,j,1,0),vis[i][j]=cnt-1;
        }
    t=tot+n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++)
            add(i,t,1,j);
    answer();
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++){
            if(M[i][j]<2) cout<<M[i][j];
            else printf("%d",!vis[i][j]||a[vis[i][j]].v?0:1);
        }
}