#include<bits/stdc++.h>
using namespace std;
int const N=233,INF=0x3f3f3f3f;
int n,m,ax[N],ay[N],bx[N],by[N];
vector<int>tx,ty;
struct flow{
	static int const N=2333333;
	int s,t,tot=1,head[N],val[N],nxt[N],to[N],cur[N],dep[N],l,r,q[N];
	void init(int x,int y){
		s=x,t=y,tot=1;memset(head,0,sizeof head);
	}
	void add(int x,int y,int v){
		to[++tot]=y,val[tot]=v,nxt[tot]=head[x];
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
	cin>>n>>m,tx.push_back(n+1),ty.push_back(n+1);
	for(int i=1;i<=m;i++){
		cin>>ax[i]>>ay[i]>>bx[i]>>by[i];
		tx.push_back(ax[i]);
		tx.push_back(++bx[i]);
		ty.push_back(ay[i]);
		ty.push_back(++by[i]);
	}
	sort(tx.begin(),tx.end());
	sort(ty.begin(),ty.end());
	tx.erase(unique(tx.begin(),tx.end()),tx.end());
	ty.erase(unique(ty.begin(),ty.end()),ty.end());
	g.s=0,g.t=tx.size()+ty.size();
	for(int i=1;i<=m;i++){
		ax[i]=lower_bound(tx.begin(),tx.end(),ax[i])-tx.begin()+1;
		ay[i]=lower_bound(ty.begin(),ty.end(),ay[i])-ty.begin()+1;
		bx[i]=lower_bound(tx.begin(),tx.end(),bx[i])-tx.begin()+1;
		by[i]=lower_bound(ty.begin(),ty.end(),by[i])-ty.begin()+1;
		for(int x=ax[i];x<bx[i];x++)
			for(int y=ay[i];y<by[i];y++)
				g.add_edge(x,y+tx.size(),INF);
	}
	for(int i=1;i<tx.size();i++)
		g.add_edge(g.s,i,tx[i]-tx[i-1]);
	for(int i=1;i<ty.size();i++)
		g.add_edge(i+tx.size(),g.t,ty[i]-ty[i-1]);
	cout<<g.dinic()<<"\n";
}