#include<bits/stdc++.h>
using namespace std; 
int const N=3010,INF=0x3f3f3f3f;
int n,m,ans,a[N],b[N],pre[N];
vector<int>e[N];
queue<int>q;
struct flow{
	static int const N=400010;
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
	cin>>n,g.s=n+1,g.t=g.s+1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int x=1;x<=n;x++){
		if(b[x]<0)
			g.add_edge(x,g.t,-b[x]);
		else
			g.add_edge(g.s,x,b[x]),ans+=b[x];
		for(int y=1;y*y<=a[x];y++)
			if(a[x]%y==0){
				if(pre[y])
					g.add_edge(x,pre[y],INF);
				if(pre[a[x]/y])
					g.add_edge(x,pre[a[x]/y],INF);
			}
		pre[a[x]]=x;
	}
	cout<<ans-g.dinic()<<"\n";
}