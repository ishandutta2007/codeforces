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

const int inf=LLONG_MAX/3;

int p;

struct N{
	vi x;
	int s;
	void init(int a){
		x={-inf,p-a,inf};
		s=a;
	}
	void mrg(const N&a,const N&b){
		int len=a.x.size()+b.x.size()-4;
		x.pb(-inf);
		int c=0,d=0;
		rng(num,1,len+1){
			int cur=x.back();
			while(c+d<num){
				int nx=min(a.x[c+1]-cur,b.x[d+1]-(cur+a.s-c*p));
				cur+=nx;
				if(a.x[c+1]<=cur)c++;
				if(d)d--;
				while(b.x[d+1]<=cur+a.s-c*p)d++;
			}
			x.pb(cur);
		}
		x.pb(inf);
		s=a.s+b.s;
	}
	int get(int v){
		return v+s-(upper_bound(all(x),v)-x.bg-1)*p;
	}
};

struct S{
	vc<N> buf;
	int s;
	S(vi d){
		s=1;
		while(s<int(d.size()))s*=2;
		d.resize(s);
		buf.resize(s*2);
		rep(i,s)
			buf[i+s].init(d[i]);
		gnr(i,1,s)
			buf[i].mrg(buf[i*2],buf[i*2+1]);
	}
	void get(int b,int e,int&v,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			v=buf[i].get(v);
			return;
		}
		int m=(l+r)/2;
		get(b,e,v,l,m,i*2);
		get(b,e,v,m,r,i*2+1);
	}
	int get(int b,int e){
		int v=0;
		get(b,e,v,0,s,1);
		return v;
	}
};

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	
	int n=read(),m=read();
	p=read();
	vi a(n);
	rep(i,n)a[i]=read();
	S slv(a);
	
	rep(_,m){
		int l=read()-1,r=read();
		cout<<slv.get(l,r)<<"\n";
	}
}