#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=1e5+5,M=34005,inf=1e17;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,Q,x,y,z,op,dis[maxn],f[maxn],cnt=0,vis[maxn];
int head[maxn],to[maxn],nex[maxn],w[maxn];
priority_queue<pi>q;vector<int>a[maxn];
void add(int x,int y,int z){to[++cnt]=y,w[cnt]=z;nex[cnt]=head[x];head[x]=cnt;}
void dij(){
	q.push(mp(0,1));memset(dis,0x3f,sizeof dis);dis[1]=0;
	while(!q.empty()){
		int x=q.top().se;q.pop();if(vis[x])continue;vis[x]=1;
		for(int i=head[x];i;i=nex[i])
			if(dis[to[i]]>dis[x]+w[i])dis[to[i]]=dis[x]+w[i],q.push(mp(-dis[to[i]],to[i]));
	}
}
void solve(int x){
	for(int i=1;i<=x;i++)w[read()]++;int c=min(x,n-1);
	memset(f,0x3f,sizeof f);f[1]=0;a[0].pb(1);
	int mx=0;
	for(int i=0;i<=mx;i++)
		while(a[i].size()){
			int u=a[i].back();a[i].pop_back();
			if(f[u]<i)continue;
			for(int j=head[u];j;j=nex[j]){
				int v=to[j];
				int p=dis[u]+w[j]-dis[v];
				if(f[v]>f[u]+p){
					f[v]=f[u]+p;
					if(f[v]<=c){mx=max(mx,f[v]);a[f[v]].pb(v);}
				}
			}
		}
	for(int i=1;i<=n;i++)dis[i]=min(inf,dis[i]+f[i]);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();Q=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),z=read(),add(x,y,z);
	dij();
	for(int i=1;i<=Q;i++){
		op=read();x=read();
		if(op==1)printf("%lld\n",dis[x]<inf?dis[x]:-1);
		else solve(x);
	}
 	return 0;
}