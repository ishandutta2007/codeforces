#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

void yes(){
	cout<<"YES"<<endl;
	//exit(0);
}

void no(){
	cout<<"NO"<<endl;
	exit(0);
}

const int Nmax=1010;
vc<pi> g[Nmax];

pi dfs(int v,int p){
	vc<pi> res;
	for(auto e:g[v])if(e.a!=p)
		res.pb(dfs(e.a,v));
	if(res.empty())return pi(v,v);
	return pi(res.front().a,res.back().b);
}

vc<tuple<int,int,int>> ans;
void wrt(int a,int b,int c){
	if(a!=b)
		ans.eb(a+1,b+1,c);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	
	rep(i,n-1){
		int a,b,v;cin>>a>>b>>v;
		a--;b--;
		g[a].eb(b,v);
		g[b].eb(a,v);
	}
	rep(i,n)if(g[i].size()==2){
		int a=g[i][0].a,b=g[i][1].a,c=g[i][0].b,d=g[i][1].b;
		if(c!=d)no();
		g[a].erase(find(all(g[a]),pi(i,c)));
		g[b].erase(find(all(g[b]),pi(i,c)));
		g[a].eb(b,c);
		g[b].eb(a,c);
	}
	yes();
	rep(i,n)if(g[i].size()!=2)
		for(auto e:g[i]){
			if(i<e.a){
				pi x=dfs(i,e.a);
				pi y=dfs(e.a,i);
				dmp(i);
				dmp(e.a);
				dmp(x);
				dmp(y);
				wrt(x.a,y.a,e.b/2);
				wrt(x.b,y.b,e.b/2);
				wrt(x.a,x.b,-e.b/2);
				wrt(y.a,y.b,-e.b/2);
			}
		}
	
	cout<<ans.size()<<endl;
	for(auto x:ans){
		int a,b,c;tie(a,b,c)=x;
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
}