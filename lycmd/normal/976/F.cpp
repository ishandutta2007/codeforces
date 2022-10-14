#include<bits/stdc++.h>
using namespace std;
int const N=4010,INF=0x3f3f3f3f;
int n,m,e,d[N];
vector<int>ans[N];
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
				if(val[i]&&dep[y]==INF){
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
	static int const N=100010;
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
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>e,g.init(0,n+m+1);
	for(int i=1,x,y;i<=e;i++)
		cin>>x>>y,d[x]++,d[y+n]++,g.add_edge(x,y+n,1);
	int mn=e;
	for(int i=1;i<=n+m;i++)
		mn=min(mn,d[i]);
	for(int i=1;i<=n;i++)
		g.add_edge(g.s,i,d[i]-mn);
	for(int i=n+1;i<=n+m;i++)
		g.add_edge(i,g.t,d[i]-mn);
	for(int i=mn;i>=0;i--){
		g.dinic();
		for(int j=1;j<=e;j++)
			if(g.val[j*2])
				ans[i].push_back(j);
		for(int j=g.head[0];j;j=g.nxt[j])
			g.val[j]++;
		for(int j=g.head[n+m+1];j;j=g.nxt[j])
			g.val[j^1]++;
	}
	for(int i=0;i<=mn;i++,cout<<"\n"){
		cout<<ans[i].size();
		for(int j:ans[i])
			cout<<" "<<j;
	}
}