#include<bits/stdc++.h>
using namespace std; 
int const N=233,INF=0x3f3f3f3f;
int n,m,ans,cntx,cnty,x[N][N],y[N][N];
char a[N][N]; 
struct flow{
	static int const N=2333333;
	int s,t,tot=1,head[N],val[N],nxt[N],to[N],cur[N],dep[N],l,r,q[N];
	void add(int x,int y,int v){
		to[++tot]=y;
		val[tot]=v;
		nxt[tot]=head[x];
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
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],ans+=a[i][j]=a[i][j]=='#';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]&&a[i][j+1])
				x[i][j]=++cntx,ans--;
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n+1;i++)
			if(a[i][j]&&a[i+1][j])
				y[i][j]=++cnty+cntx,ans--;
	g.s=0,g.t=cntx+cnty+1;
	for(int i=1;i<=cntx;i++)
		g.add_edge(g.s,i,1);
	for(int i=cntx+1;i<=cntx+cnty;i++)
		g.add_edge(i,g.t,1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]){
				if(a[i-1][j]&&a[i][j+1])
					g.add_edge(x[i][j],y[i-1][j],1);
				if(a[i][j+1]&&a[i+1][j])
					g.add_edge(x[i][j],y[i][j],1);
				if(a[i+1][j]&&a[i][j-1])
					g.add_edge(x[i][j-1],y[i][j],1);
				if(a[i][j-1]&&a[i-1][j])
					g.add_edge(x[i][j-1],y[i-1][j],1);
			}
	cout<<ans+g.dinic()<<"\n";
}//