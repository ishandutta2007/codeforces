#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=23333,INF=0x3f3f3f3f3f3f3f3fll;
int n,sum,x[N],y[N],w[N],op[N];
struct flow{
	int s,t,tot=1,hd[N],val[N],nxt[N],to[N],cur[N],dep[N],l,r,q[N];
	void init(){
		memset(hd,-1,sizeof hd);
		tot=1;
	}
	void add(int x,int y,int v){
		to[++tot]=y;
		val[tot]=v;
		nxt[tot]=hd[x];
		hd[x]=tot;
	}
	void add_edge(int x,int y,int v){
		add(x,y,v);add(y,x,0);
	}
	int bfs(){
		memset(dep,0x3f,sizeof dep);
		q[l=r=0]=s;
		dep[s]=0;
		cur[s]=hd[s];
		while(l<=r){
			int x=q[l++];
			for(int i=hd[x];i;i=nxt[i]){
				int y=to[i];
				if(val[i]>0&&dep[y]==INF){
					cur[y]=hd[y];
					dep[y]=dep[x]+1;
					if(y==t)return 1;
					q[++r]=y;
				}
			}
		}
		return 0;
	}
	int dfs(int x,int sum){
		if(x==t)return sum;
		int res=0;
		for(int i=cur[x];i&&sum;i=nxt[i]){
			cur[x]=i;
			int y=to[i];
			if(val[i]>0&&dep[y]==dep[x]+1){
				int rem=dfs(y,min(sum,val[i]));
				if(!rem)dep[y]=INF; 
				else val[i]-=rem,val[i^1]+=rem,res+=rem,sum-=rem;
			}
		}
		return res;
	}
	int dinic(){
		int ans=0;
		while(bfs())ans+=dfs(s,INF);
		return ans;
	}
}g;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,g.t=2*n+1;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i]>>w[i];
	for(int i=1;i<=n;i++){
		g.add_edge(i,i+n,w[i]),sum+=w[i];
		int k=(x[i]&1)<<1|(y[i]&1);
		op[i]=k>2?0:k>1?3:k?1:2;
	}
	for(int i=1;i<=n;i++){
		if(!op[i])g.add_edge(g.s,i,INF);
		if(op[i]==3)g.add_edge(i+n,g.t,INF);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(op[i]+1==op[j]&&abs(x[i]-x[j])+abs(y[i]-y[j])==1)
				g.add_edge(i+n,j,INF);
	cout<<sum-g.dinic()<<"\n";
}