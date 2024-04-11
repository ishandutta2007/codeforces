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

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll read(){ll i;cin>>i;return i;}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	
	int n=read(),a=read(),b=read();
	vc<double> x(n),y(n);
	rep(i,n){cin>>x[i];x[i]=1-x[i];}
	rep(i,n){cin>>y[i];y[i]=1-y[i];}
	
	const auto waf=[&](double mid){
		vc<pair<double,int>> w;
		rep(i,n)
			w.eb(min(x[i]*y[i]+mid,y[i])-min(x[i]+mid,1.0),i);
		sort(all(w));
		vc<bool> u(n);
		rep(i,b)u[w[i].b]=1;
		double val=0;
		int cnt=0;
		rep(i,n)
			if(u[i]){
				if(x[i]*y[i]+mid<y[i])
					cnt++;
				val+=min(x[i]*y[i]+mid,y[i]);
			}else{
				if(x[i]+mid<1.0)
					cnt++;
				val+=min(x[i]+mid,1.0);
			}
		return make_pair(val,cnt);
	};
	
	double lw=0,up=1;
	rep(_,60){
		double mid=(lw+up)/2;
		if(waf(mid).b<=a)
			up=mid;
		else
			lw=mid;
	}
	
	cout<<n-(waf(up).a-up*a)<<endl;
}