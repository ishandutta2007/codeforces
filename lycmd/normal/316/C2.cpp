#include<bits/stdc++.h>
#define ord(i,j) ((i-1)*m+j)
using namespace std;
int const N=85,INF=0x3f3f3f3fll;
int n,m,a[N][N];
struct costflow{
	static int const N=100010;
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
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,g.s=0,g.t=ord(n,m)+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],(i+j)&1?g.add_edge(g.s,ord(i,j),1,0):g.add_edge(ord(i,j),g.t,1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((i+j)&1){
				if(i>1)g.add_edge(ord(i,j),ord(i-1,j),1,a[i][j]!=a[i-1][j]);
				if(j>1)g.add_edge(ord(i,j),ord(i,j-1),1,a[i][j]!=a[i][j-1]);
				if(i<n)g.add_edge(ord(i,j),ord(i+1,j),1,a[i][j]!=a[i+1][j]);
				if(j<m)g.add_edge(ord(i,j),ord(i,j+1),1,a[i][j]!=a[i][j+1]);
			}
	cout<<g.mcmf().first<<"\n";
}////