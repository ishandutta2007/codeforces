#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

struct mf_graph{
	static const int inf=2e9;
	struct edge{
		int to,nx,w;
	};vector<edge> e;
	#define fore(k) for(int i=hd[k];i;i=e[i].nx)
	#define fory(k) for(int&i=hy[k];i;i=e[i].nx)
	#define _to e[i].to
	vector<int> hd,dep,hy;int S,n;
	mf_graph(int sz){
		S=1,n=sz+1;
		hd.resize(n);dep.resize(n);
		e.push_back({0,0,0});
		e.push_back({0,0,0});
	}
	void add_edge(int fr,int to,int w){
		e.push_back({to,hd[fr],w}),hd[fr]=++S;
		e.push_back({fr,hd[to],0}),hd[to]=++S;
	}
	bool bfs(int s,int t){
		fill(dep.begin(),dep.end(),-1);
		dep[s]=0;hy=hd;
		queue<int> q;q.push(s);
		while(q.size()){
			int nw=q.front();q.pop();
			fore(nw)if(e[i].w&&!~dep[_to]){
				dep[_to]=dep[nw]+1;
				q.push(_to);
			}
		}
		return ~dep[t];
	}
	int dfs(int k,int fl,int t){
		if(k==t)return fl;
		int rst=fl,f=0;
		fory(k)if(dep[_to]==dep[k]+1&&e[i].w){
			int nw=dfs(_to,min(e[i].w,rst),t);
			if(!nw)dep[_to]=0;
			rst-=nw,f+=nw,e[i].w-=nw,e[i^1].w+=nw;
			if(!rst)break ;
		}
		return f;
	}
	int flow(int s,int t){
		int ans=0;
		while(bfs(s,t))
			ans+=dfs(s,inf,t);
		return ans;
	}
};

int n,m;
int a[N];
int A[N],B[N],sza,szb;
int vis[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]*3<=m)B[++szb]=a[i];
		else A[++sza]=a[i];
	}
	mf_graph e(n+5);
	int s=0,t=n+1; 
	for(int i=1;i<=sza;i++)
		e.add_edge(s,i,1);
	for(int i=1;i<=szb;i++)
		e.add_edge(i+sza,t,1);
	for(int i=1;i<=sza;i++)
		for(int j=1;j<=szb;j++){
			if(A[i]%B[j])continue;
			if(A[i]+B[j]+A[i]>m)continue;
			e.add_edge(i,j+sza,1);
		}
	int fl=e.flow(s,t);
	if(fl!=sza){
		cout<<-1<<endl;
		exit(0);
	}
	vector<pair<int,int>> res;
	for(int i=1;i<=sza;i++){
		for(int j=e.hd[i];j;j=e.e[j].nx)
			if(e.e[j^1].w){
				int v=e.e[j].to;
				res.push_back({A[i]+B[v-sza]+A[i],A[i]+B[v-sza]});
				vis[v-sza]=1;
			}
	}
	for(int i=1;i<=szb;i++)
		if(!vis[i])
			res.push_back({B[i]*2,B[i]*3});
	cout<<res.size()<<endl;
	for(auto x:res)cout<<x.first<<' '<<x.second<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}