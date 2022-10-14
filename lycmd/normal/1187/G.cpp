#include<bits/stdc++.h>
#define int long long
#define ord(x,y) ((x)*n+(y))
using namespace std;
int const N=2333333,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,k,c,d,s,t,tot=1,a[N],head[N],val[N],nxt[N],to[N],cst[N],vis[N],dis[N],flw[N],pre[N],pe[N];
queue<int>q; 
void add(int x,int y,int v,int w){
	to[++tot]=y;
	val[tot]=v;
	nxt[tot]=head[x];
	cst[tot]=w;
	head[x]=tot;
}
void add_edge(int x,int y,int v,int w){
	add(x,y,v,w),add(y,x,0,-w);
}
int spfa(){
	memset(vis,0,sizeof vis);
	memset(dis,INF,sizeof dis);
	memset(flw,INF,sizeof flw);
	memset(pre,0,sizeof pre);
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
	return pre[t]!=-1;
}
pair<int,int>mcmf(){
	int ansc=0,ansf=0;
	while(spfa()){
		int p=t,cur=flw[t];
		ansc+=cur*dis[t],ansf+=cur;
		while(p^s)
			val[pe[p]]-=cur,val[pe[p]^1]+=cur,p=pre[p];
	}
	return{ansc,ansf};
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k>>c>>d,s=0,t=ord(n+k-1,1);
	for(int i=1;i<=k;i++)
		cin>>a[i],add_edge(s,a[i],1,0);
	while(m--){
		int x,y;cin>>x>>y;
		for(int i=0;i<n+k;i++)
			for(int j=1;j<=k;j++)
				add_edge(ord(i,x),ord(i+1,y),1,d*(2*j-1)+c),
				add_edge(ord(i,y),ord(i+1,x),1,d*(2*j-1)+c);
	}
	for(int i=0;i<n+k-1;i++)
		for(int j=1;j<=n;j++)
			add_edge(ord(i,j),ord(i+1,j),INF,j>1?c:0);
	cout<<mcmf().first<<"\n";
}//