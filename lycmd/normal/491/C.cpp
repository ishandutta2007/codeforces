#include<bits/stdc++.h>
using namespace std;
int const N=55;
int n,k,cnt[N][N],ans[N],vis[N];
int ord(char c){return c-(c<96?38:96);}
string s,t;
struct costflow{
private:
	void add(int x,int y,int v,int w){
		from[++tot]=x,to[tot]=y,val[tot]=v,nxt[tot]=head[x],cst[tot]=w;
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
	int s,t,tot=1,head[N],val[N],nxt[N],from[N],to[N],cst[N],vis[N],dis[N],flw[N],
		pre[N],pe[N];
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
	cin>>n>>k>>s>>t,g.init(0,k*2+1);
	for(int i=0;i<n;i++)
		cnt[ord(s[i])][ord(t[i])]--;
	for(int i=1;i<=k;i++)
		g.add_edge(g.s,i,1,0);
	for(int i=1;i<=k;i++)
		g.add_edge(i+k,g.t,1,0);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			if(cnt[i][j])
				g.add_edge(i,j+k,1,cnt[i][j]);
	cout<<-g.mcmf().first<<"\n";
	for(int i=2;i<=g.tot;i+=2)
		if(g.from[i]<=k&&g.to[i]>k&&g.from[i]!=g.s&&g.to[i]!=g.t&&!g.val[i])
			vis[ans[g.from[i]]=g.to[i]-k]=1;
	for(int i=1,p2=1;i<=k;i++)
		if(!ans[i]){
			while(vis[p2])p2++;
			ans[i]=p2++;
		}
	for(int i=1;i<=k;i++)
		cout<<(char)(ans[i]+(ans[i]<=26?96:38));
	cout<<"\n";
}