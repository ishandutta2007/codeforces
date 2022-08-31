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

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	const int inf=INT_MAX;
	
	int n;cin>>n;
	n=4*n+1;
	
	vc<pi> xy;
	rep(i,n){
		int x,y;cin>>x>>y;
		xy.eb(x,y);
	}
	rep(i,n){
		int xmn=inf,xmx=-inf,ymn=inf,ymx=-inf;
		rep(j,n)if(j!=i){
			int x,y;tie(x,y)=xy[j];
			chmin(xmn,x);
			chmin(ymn,y);
			chmax(xmx,x);
			chmax(ymx,y);
		}
		bool ok=true;
		int a=0,b=0,c=0,d=0;
		rep(j,n)if(j!=i){
			int x,y;tie(x,y)=xy[j];
			bool has=false;
			if(x==xmn){a++;has=true;}
			if(x==xmx){b++;has=true;}
			if(y==ymn){c++;has=true;}
			if(y==ymx){d++;has=true;}
			if(!has)ok=false;
		}
		if(ymx-ymn==xmx-xmn&&ok&&min({a,b,c,d})>=n/4){
			cout<<xy[i].a<<" "<<xy[i].b<<endl;
		}
	}
}