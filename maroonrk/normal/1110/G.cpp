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

bool slv(){
	int n;cin>>n;
	vvc<int> g(n);
	rep(i,n-1){
		int a,b;cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vi d(n);
	rep(i,n)d[i]=g[i].size();
	
	string s;cin>>s;
	int w=count(all(s),'W');
	
	if(n==2)return 0;
	if(n==3)return w==2;
	
	rep(i,n)if(d[i]>=4)return 1;
	rep(i,n)if(d[i]==3){
		int a=0;
		for(auto j:g[i])if(d[j]>=2)
			a++;
		if(a>=2)return 1;
	}
	rep(i,n)if(d[i]>=2&&s[i]=='W')
		return 1;
	rep(i,n)if(d[i]==1&&s[i]=='W')
		if(d[g[i][0]]==3)return 1;
	
	int t=count(all(d),3);
	if(t==0){
		return w==2&&n%2==1;
	}else if(t==1){
		return w==1&&n%2==0;
	}else if(t==2){
		return n%2==1;
	}else
		assert(false);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)
		cout<<(slv()?"White":"Draw")<<endl;
}