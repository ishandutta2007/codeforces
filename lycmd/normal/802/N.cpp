#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333,INF=0x3f3f3f3f3f3f3f3fll;
int n,k,a[N],b[N];
struct costflow{
	static int const N=233333;
	int s,t,tot=1,head[N],val[N],nxt[N],to[N],cst[N],vis[N],dis[N],flw[N],pre[N],pe[N];
	queue<int>q;
	void add(int x,int y,int v,int w){
		to[++tot]=y,val[tot]=v,nxt[tot]=head[x],cst[tot]=w;
		head[x]=tot;
	}
	void add_edge(int x,int y,int v,int w){
		add(x,y,v,w),add(y,x,0,-w);
	}
	int spfa(){
		memset(vis,0,sizeof vis);
		memset(dis,0x3f,sizeof dis);
		memset(flw,0x3f,sizeof flw);
		q=queue<int>();
		q.push(s),vis[s]=1,dis[s]=0,pre[t]=-1;
		while(!q.empty()){
			int x=q.front();q.pop();
			vis[x]=0;
			for(int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if(val[i]>0&&dis[y]>dis[x]+cst[i]){
					dis[y]=dis[x]+cst[i],pre[y]=x,pe[y]=i,flw[y]=min(flw[x],val[i]);
					if(!vis[y])
						vis[y]=1,q.push(y);
				}
			}
		}
		return ~pre[t];
	}
	pair<int,int>mcmf(){
		int ansc=0,ansf=0;
		while(spfa()){
			int p=t,cur=flw[t];
			ansc+=cur*dis[t],ansf+=cur;
			while(p!=s)
				val[pe[p]]-=cur,val[pe[p]^1]+=cur,p=pre[p];
		}
		return {ansc,ansf};
	}
}g;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k,g.s=0,g.t=n+2,g.add_edge(n+1,g.t,k,0);
	for(int i=1;i<n;i++)
		g.add_edge(i,i+1,INF,0);
	for(int i=1;i<=n;i++)
		cin>>a[i],g.add_edge(g.s,i,1,a[i]);
	for(int i=1;i<=n;i++)
		cin>>b[i],g.add_edge(i,n+1,1,b[i]);
	cout<<g.mcmf().first<<"\n";
}//