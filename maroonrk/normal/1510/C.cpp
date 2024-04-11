#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
#define a first
#define b second

template<class t,class u>bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u>bool chmin(t&a,u b){if(a>b){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>&p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t>
ostream&operator<<(ostream&os,const vector<t>&v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

template<class t>
using vc=vector<t>;

using vi=vc<int>;

using pi=pair<int,int>;

const int nmax=100010;

vi g[nmax];
vc<pi> es;
int stat[nmax],sum[nmax];

void init_graph(int n){
	rep(i,n){
		g[i].clear();
		stat[i]=0;
		sum[i]=0;
	}
	for(auto [a,b]:es){
		g[a].pb(b);
		g[b].pb(a);
	}
}

void dfs1(int v,int p){
	stat[v]=1;
	for(auto to:g[v])if(to!=p){
		if(stat[to]==0){
			dfs1(to,v);
			sum[v]+=sum[to];
		}else if(stat[to]==1){
			sum[v]++;
			sum[to]--;
		}else{
			//do nothing
		}
	}
	if(sum[v]==0&&p!=-1){
		es.eb(v,p);
	}
	stat[v]=2;
}

bool dfs2(int v,int p){
	stat[v]=1;
	bool ok=true;
	for(auto to:g[v])if(to!=p){
		if(stat[to]==0){
			bool w=dfs2(to,v);
			if(ok&&w){
				es.eb(to,v);
				ok=false;
			}
		}
	}
	return ok;
}

int dfs3(int v,int p){
	stat[v]=1;
	int res=-1;
	for(auto to:g[v])if(to!=p){
		if(stat[to]==0){
			int w=dfs3(to,v);
			if(w!=-1){
				if(res==-1){
					res=w;
				}else{
					es.eb(res,w);
					res=-1;
				}
			}
		}
	}
	if(p==-1){
		if(res!=-1)es.eb(res,v);
		return -1;
	}else{
		if(res==-1)res=v;
		return res;
	}
}

void slv(){
	int n,m;cin>>n>>m;
	if(n==0)exit(0);
	es.clear();
	rep(i,m){
		int s;cin>>s;
		vi idx(s);rep(j,s)cin>>idx[j];
		rep(j,s-1)es.eb(idx[j]-1,idx[j+1]-1);
	}
	init_graph(n);
	es.clear();
	dfs1(0,-1);
	
	dmp(es);
	
	vi deg(n);
	for(auto [a,b]:es){
		deg[a]++;
		deg[b]++;
	}
	vc<pi> tmp;
	for(auto [a,b]:es){
		if(deg[a]%2&&deg[b]%2)
			tmp.eb(a,b);
	}
	tmp.swap(es);
	
	dmp(es);
	init_graph(n);
	es.clear();
	rep(i,n)if(stat[i]==0)dfs2(i,-1);
	
	for(auto&[a,b]:es){
		if(a>b)swap(a,b);
	}
	sort(all(es));
	dmp(es);
	vc<pi> god;
	for(auto&[a,b]:tmp){
		if(a>b)swap(a,b);
		if(binary_search(all(es),pi(a,b))){
			//skip
		}else{
			god.eb(a,b);
		}
	}
	es=god;
	
	dmp(es);
	init_graph(n);
	es.clear();
	rep(i,n)if(stat[i]==0){
		dfs3(i,-1);
	}
	
	cout<<si(es)<<"\n";
	for(auto [a,b]:es){
		cout<<a+1<<" "<<b+1<<"\n";
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	while(1)slv();
}