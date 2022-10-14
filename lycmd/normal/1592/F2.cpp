#include<bits/stdc++.h>
using namespace std;
int const N=505,INF=0x3f3f3f3f;
int n,m,ans,b[N][N],s[N][N];
char a[N][N];
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
	static int const N=233333;
	int s,t,tot,head[N],val[N],nxt[N],to[N],cur[N],dep[N],l,r,q[N];
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
}g;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],b[i][j]=a[i][j]==66;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=s[i][j]=b[i][j]^b[i+1][j]^b[i][j+1]^b[i+1][j+1];
	g.init(0,n+m);
	for(int i=1;i<n;i++)
		g.add_edge(g.s,i,1);
	for(int j=1;j<m;j++)
		g.add_edge(j+n,g.t,1);
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(s[i][j]&&s[i][m]&&s[n][j])
				g.add_edge(i,j+n,1);
	int cnt=g.dinic();
	cout<<ans-cnt-s[n][m]+(s[n][m]^(cnt&1))<<"\n";
}