#include<bits/stdc++.h>
using namespace std;
int const N=10010,INF=0x3f3f3f3f;
int n,m,x[N],y[N],o[N];
struct flow{
private:
	void add(int x,int y,int v){
		to[++tot]=y,val[tot]=v,nxt[tot]=head[x];
		head[x]=tot;
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
public:
	static int const N=233333;
	int s,t,tot=1,head[N],val[N],nxt[N],to[N],cur[N],dep[N],l,r,q[N];
	void init(int x,int y){
		s=x,t=y,tot=1,memset(head,0,sizeof head);
	}
	void add_edge(int x,int y,int v){
		add(x,y,v),add(y,x,0);
	}
	int dinic(){
		int ans=0;
		while(bfs())ans+=dfs(s,INF);
		return ans;
	}
};
flow g;
int check(int k){
	g.init(0,n+m+1);
	for(int i=1;i<=n;i++)
		g.add_edge(g.s,i,k);
	for(int i=1;i<=m;i++)
		o[i]=g.tot+1,g.add_edge(y[i],i+n,1),g.add_edge(x[i],i+n,1),
		g.add_edge(i+n,g.t,1);
	return g.dinic()==m;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>x[i]>>y[i];
	int l=-1,r=m;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<r<<"\n",check(r);
	for(int i=1;i<=m;i++)
		if(!g.val[o[i]])
			swap(x[i],y[i]);
	for(int i=1;i<=m;i++)
		cout<<x[i]<<" "<<y[i]<<"\n";
}