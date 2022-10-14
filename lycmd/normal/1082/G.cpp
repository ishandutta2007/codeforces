#include<bits/stdc++.h>
#define int long long
using namespace std; 
int const N=233333,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,ans,p[N],b[N];
vector<int>e[N];
queue<int>q;
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
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,g.s=n+m+1,g.t=g.s+1;
	for(int i=1;i<=n;i++)
		cin>>b[i],b[i]=-b[i];
	for(int i=n+1;i<=n+m;i++){
		int x,y;
		cin>>x>>y>>b[i];
		e[i].push_back(x);
		e[i].push_back(y);
	}
	for(int x=1;x<=n+m;x++){
		if(b[x]<0)
			g.add_edge(x,g.t,-b[x]);
		else
			g.add_edge(g.s,x,b[x]),ans+=b[x];
		for(int y:e[x])
			g.add_edge(x,y,INF);
	}
	cout<<ans-g.dinic()<<"\n";
}//