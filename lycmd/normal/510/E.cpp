#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;
int const N=233,INF=0x3f3f3f3f;
int n,cnt,e[N][N],vis[N];
node a[N];
vector<int>cur;
vector<vector<int> >ans;
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
int isp(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
void dfs(int x){
	vis[x]=1;
	cur.push_back(x);
	for(int y=1;y<=n;y++)
		if(e[x][y]&&!vis[y]&&!g.val[e[x][y]])
			dfs(y);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].first,cnt+=a[i].first&1,a[i].second=i;
	if(cnt*2!=n)
		cout<<"Impossible\n",exit(0);
	g.init(0,n+1);
	for(int i=1;i<=n;i++)
		if(a[i].first&1)
			g.add_edge(i,g.t,2);
		else
			g.add_edge(g.s,i,2);
	sort(a+1,a+1+n,[](node x,node y){
		return x.first%2<y.first%2;
	});
	for(int i=1;i<=n/2;i++)
		for(int j=n/2+1;j<=n;j++)
			if(isp(a[i].first+a[j].first)){
				int x=a[i].second,y=a[j].second;
				g.add_edge(x,y,1),e[x][y]=e[y][x]=g.tot-1;
			}
	int t=g.dinic();
	if(t!=n)
		cout<<"Impossible\n",exit(0);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			cur.clear(),dfs(i),ans.push_back(cur);
	cout<<ans.size()<<"\n";
	for(auto i:ans){
		cout<<i.size();
		for(int j:i)
			cout<<" "<<j;
		cout<<"\n";
	}
}