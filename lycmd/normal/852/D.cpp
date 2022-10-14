#include<bits/stdc++.h>
using namespace std;
int const N=605,INF=0x3f3f3f3f;
int v,e,n,k,f[N][N],st[N];
struct flow{
	static int const N=2333333;
	int s,t,tot=1,head[N],val[N],nxt[N],to[N],cur[N],dep[N],l,r,q[N];
	void init(int x,int y){
		s=x,t=y,tot=1,memset(head,0,sizeof head);
	}
	void add(int x,int y,int v){
		to[++tot]=y,val[tot]=v,nxt[tot]=head[x];
		head[x]=tot;
	}
	void add_edge(int x,int y,int v){
		add(x,y,v),add(y,x,0);
	}
	int bfs(){
		memset(dep,0x3f,sizeof dep);
		q[l=r=0]=s;
		dep[s]=0,cur[s]=head[s];
		while(l<=r){
			int x=q[l++];
			for(int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if(val[i]>0&&dep[y]==INF){
					cur[y]=head[y];
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
int check(int x){
	g.init(0,n+v+1);
	for(int i=1;i<=n;i++)
		g.add_edge(g.s,i,1);
	for(int i=1;i<=v;i++)
		g.add_edge(i+n,g.t,1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=v;j++)
			if(f[st[i]][j]<=x)
				g.add_edge(i,j+n,1);
	return g.dinic()>=k;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>v>>e>>n>>k;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)
		cin>>st[i];
	for(int i=1;i<=v;i++)
		f[i][i]=0;
	while(e--){
		int x,y,k;cin>>x>>y>>k;
		f[x][y]=f[y][x]=min(f[x][y],k);
	}
	for(int k=1;k<=v;k++)
		for(int i=1;i<=v;i++)
			for(int j=1;j<=v;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int l=-1,r=1e9;
	if(!check(r))
		cout<<"-1\n",exit(0);
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<r<<"\n";
}//