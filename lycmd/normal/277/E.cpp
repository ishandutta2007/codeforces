#include<bits/stdc++.h>
using namespace std;
int const N=405;
int n,x[N],y[N];
struct costflow{
private:
	void add(int x,int y,int v,double w){
		to[++tot]=y,val[tot]=v,nxt[tot]=head[x],cst[tot]=w;
		head[x]=tot;
	}
	int spfa(){
		memset(vis,0,sizeof vis);
		memset(dis,0x43,sizeof dis);
		memset(flw,0x3f,sizeof flw);
		q=queue<int>();
		q.push(s),vis[s]=1,dis[s]=0,pre[t]=-1;
		while(!q.empty()){
			int x=q.front();q.pop();
			vis[x]=0;
			for(int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if(val[i]>0&&dis[y]>dis[x]+cst[i]){
					dis[y]=dis[x]+cst[i],pre[y]=x,pe[y]=i;
					flw[y]=min(flw[x],val[i]);
					if(!vis[y])
						vis[y]=1,q.push(y);
				}
			}
		}
		return ~pre[t];
	}
public: 
	static int const N=233333;
	int s,t,tot=1,head[N],val[N],nxt[N],to[N],vis[N],flw[N],pre[N],pe[N];
	double cst[N],dis[N];
	queue<int>q;
	void init(int x,int y){
		s=x,t=y,tot=1;
		memset(head,0,sizeof head);
	}
	void add_edge(int x,int y,int v,double w){
		add(x,y,v,w),add(y,x,0,-w);
	}
	pair<double,int>mcmf(){
		double ansc=0;
		int ansf=0;
		while(spfa()){
			int p=t,cur=flw[t];
			ansc+=cur*dis[t],ansf+=cur;
			while(p!=s)
				val[pe[p]]-=cur,val[pe[p]^1]+=cur,p=pre[p];
		}
		return {ansc,ansf};
	}
};
costflow g;
int main(){
	ios::sync_with_stdio(0);
	cin>>n,g.init(0,n+n+1);
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i],g.add_edge(g.s,i,2,0),g.add_edge(i+n,g.t,1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(y[i]>y[j])
				g.add_edge(i,j+n,1,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
	auto t=g.mcmf();
	if(t.second<n-1)
		cout<<"-1\n";
	else
		cout<<fixed<<setprecision(8)<<t.first<<"\n";
}