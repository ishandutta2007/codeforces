#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,K=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3fll;
int n,sum,a[N];
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
		dep[q[l=r=0]=s]=0;
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
	for(int i=1,s,x;i<=n;i++)
		for(cin>>s;s--;)
			cin>>x,g.add_edge(i,x+n,INF);
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i]-K,g.add_edge(g.s,i,K-a[i]),g.add_edge(i+n,g.t,K);
	cout<<sum+g.dinic()<<"\n";
}