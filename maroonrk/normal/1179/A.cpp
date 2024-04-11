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

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,q;cin>>n>>q;
	deque<int> d;
	int mx=0;
	rep(i,n){
		int a;cin>>a;
		chmax(mx,a);
		d.pb(a);
	}
	vc<pi> ans;
	while(d[0]<mx){
		int a=d[0],b=d[1];
		rep(_,2)d.pop_front();
		ans.eb(a,b);
		if(a<b)swap(a,b);
		d.push_front(a);
		d.push_back(b);
	}
	rep(_,q){
		int m;cin>>m;
		m--;
		pi res;
		if(m<int(ans.size())){
			res=ans[m];
		}else{
			m-=ans.size();
			res=pi(mx,d[1+m%(n-1)]);
		}
		cout<<res.a<<" "<<res.b<<"\n";
	}
	
}