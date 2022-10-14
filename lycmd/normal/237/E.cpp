#include<bits/stdc++.h>
using namespace std;
int const N=233;
int n,w[N],cnt[N],c[N][N];
string s,t[N];
struct costflow{
private:
	void add(int x,int y,int v,int w){
		to[++tot]=y,val[tot]=v,nxt[tot]=head[x],cst[tot]=w;
		head[x]=tot;
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
public: 
	static int const N=233333;
	int s,t,tot=1,head[N],val[N],nxt[N],to[N],cst[N],vis[N],dis[N],flw[N],pre[N],pe[N];
	queue<int>q;
	void init(int x,int y){
		s=x,t=y,tot=1;
		memset(head,0,sizeof head);
	}
	void add_edge(int x,int y,int v,int w){
		add(x,y,v,w),add(y,x,0,-w);
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
	cin>>s>>n;
	for(char i:s)cnt[i-96]++;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>w[i];
		for(char j:t[i])c[i][j-96]++;
	}
	g.init(0,n+27);
	for(int i=1;i<=26;i++){
		if(!cnt[i])
			continue;
		g.add_edge(g.s,i,cnt[i],0);
		for(int j=1;j<=n;j++)
			if(c[j][i])
				g.add_edge(i,j+26,c[j][i],j);
	}
	for(int i=1;i<=n;i++)
		g.add_edge(i+26,g.t,w[i],0);
	auto ans=g.mcmf();
	cout<<(ans.second<s.size()?-1:ans.first)<<"\n";
}