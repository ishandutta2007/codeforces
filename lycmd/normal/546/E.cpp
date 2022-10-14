#include<bits/stdc++.h>
using namespace std; 
int const N=233,INF=0x3f3f3f3f;
int n,m,sa,sb,a[N],b[N],ans[N][N];
vector<int>e[N];
struct flow{
	static int const N=233333;
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
	cin>>n>>m,g.s=0,g.t=2*n+1;
	for(int i=1;i<=n;i++)
		cin>>a[i],sa+=a[i],g.add_edge(g.s,i,a[i]);
	for(int i=1;i<=n;i++)
		cin>>b[i],sb+=b[i],g.add_edge(i+n,g.t,b[i]);
	for(int i=1;i<=n;i++)
		g.add_edge(i,i+n,INF);
	if(sa^sb)
		cout<<"NO\n",exit(0);
	while(m--){
		int x,y;cin>>x>>y;
		g.add_edge(x,y+n,INF);
		g.add_edge(y,x+n,INF);
	}
	int s=g.dinic();
	if(s^sa)
		cout<<"NO\n",exit(0);
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
		for(int j=g.head[i];j;j=g.nxt[j])
			ans[i][g.to[j]-n]=g.val[j^1];
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=n;j++)
			cout<<ans[i][j]<<" "; 
}//