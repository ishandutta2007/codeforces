#include<bits/stdc++.h>
#define ord(i,j) ((j)*n+(i))
using namespace std;
int const N=55,INF=0x3f3f3f3f;
int n,h,m;
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
	static int const N=2333333;
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
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>h>>m,g.init(0,ord(n,h+1)+m+1);
	for(int i=1;i<=n;i++)
		g.add_edge(g.s,ord(i,0),INF),g.add_edge(ord(i,h+1),g.t,INF);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=h;j++)
			g.add_edge(ord(i,j),ord(i,j+1),h*h-j*j);
	for(int i=1,t=ord(n,h+1);i<=m;i++){
		int l,r,x,k;cin>>l>>r>>x>>k;
		if(x==h)continue;
		g.add_edge(++t,g.t,k);
		for(int j=l;j<=r;j++)
			g.add_edge(ord(j,x+1),t,INF);
	}
	cout<<n*h*h-g.dinic()<<"\n";
}