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
template<class t,class u> void chmin(t&a,u b){if(a>b)a=b;}

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

const int inf=LLONG_MAX/3;

int fdiv(int a,int b){
	return a/b-((a^b)<0&&a%b);
}

struct CHT{
	struct ln{
		int a,b;
		int eval(int x){return a*x+b;}
	};
	int pos(ln x,ln y){
		return fdiv(x.b-y.b,y.a-x.a);
	}
	vc<ln> ls;
	//a nonincreasing
	void add(int a,int b){
		if(ls.size()&&ls.back().a==a){
			chmin(b,ls.back().b);
			ls.pop_back();
		}
		int s;
		while((s=ls.size())>=2){
			int x=pos(ls[s-2],ls[s-1]);
			int y=pos(ls[s-1],ln{a,b});
			if(x<y)break;
			ls.pop_back();
		}
		ls.pb(ln{a,b});
	}
	//x nonincreasing
	int query(int x){
		if(ls.empty())return inf;
		int s;
		while((s=ls.size())>=2)
			if(ls[s-2].eval(x)>ls[s-1].eval(x))
				break;
			else
				ls.pop_back();
		return ls.back().eval(x);
	}
};

int sub(vc<pi> x){
	int res=inf;
	sort(all(x),greater<pi>());
	CHT cht;
	for(auto p:x){
		chmin(res,cht.query(p.a)+p.b);
		cht.add(p.a,p.b);
	}
	dmp(x);
	dmp(res);
	return res;
}

const int Nmax=500010;
vi tr[Nmax];
int n,ans=inf;

pi dfs(int v,int p){
	vc<pi> x;
	for(auto c:tr[v])if(c!=p)
		x.pb(dfs(c,v));
	if(x.empty())
		return pi(1,0);
	vc<pi> y;
	for(auto w:x)
		y.eb(w.a,-w.a*(n-w.a)-w.a*(w.a-1)/2+w.b);
	chmin(ans,n*(n-1)/2+sub(y));
	int s=1;
	for(auto w:x)
		s+=w.a;
	int mn=inf;
	for(auto w:x)
		chmin(mn,w.b+(s-w.a)*(s-w.a-1)/2);
	dmp(v);
	dmp(s);
	dmp(mn);
	return pi(s,mn);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	cin>>n;
	if(n==2){
		cout<<2<<endl;
		return 0;
	}
	rep(_,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		tr[a].pb(b);
		tr[b].pb(a);
	}
	int r=-1;
	rep(i,n)if(tr[i].size()>1)
		r=i;
	
	dmp(r);
	dfs(r,-1);
	
	cout<<n*(n-1)-ans<<endl;
}