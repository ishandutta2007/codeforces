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

//KUPC2017I
//HDU 5306 Gorgeous Sequence
template<class N>
struct segbeats{
	vc<N> x;
	int s;
	template<class T>
	segbeats(const vc<T>& a){
		int n=a.size();
		s=1;
		while(s<n)s*=2;
		x.resize(s*2);
		rep(i,n)
			x[s+i]=N(a[i]);
		gnr(i,1,s)
			upd(i);
	}
	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	void upd(int i){
		x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	template<class F,class... Args>
	void chr(int l,int r,int i,int b,int e,F f,Args... args){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e&&(x[i].*f)(args...))
			return;
		push(i);
		int m=(l+r)/2;
		chr(l,m,i*2,b,e,f,args...);
		chr(m,r,i*2+1,b,e,f,args...);
		upd(i);
	}
	template<class F,class... Args>
	void ch(int b,int e,F f,Args... args){
		assert(b<e);
		chr(0,s,1,b,e,f,args...);
	}
	//use decltype((declval<N>().*F())()) for old-fashioned judges
	template<class F,class G,class H>
	auto getr(int l,int r,int i,int b,int e,F f,G g,H h){
		if(e<=l||r<=b)
			return h;
		if(b<=l&&r<=e)
			return (x[i].*f)();
		push(i);
		int m=(l+r)/2;
		return g(getr(l,m,i*2,b,e,f,g,h),getr(m,r,i*2+1,b,e,f,g,h));
	}
	template<class F,class G,class H>
	auto get(int b,int e,F f,G g,H h){
		assert(b<e);
		return getr(0,s,1,b,e,f,g,h);
	}
	//return maximum index
	template<class F,class...Args>
	pair<int,N> findr(int i,int l,int r,int b,int e,F f,Args...args){
		if(e<=l||r<=b||!(x[i].*f)(args...))return {b-1,N()};
		if(b<=l&&r<=e&&r-l==1)
			return {l,x[i]};
		push(i);
		int m=(l+r)/2;
		auto a=findr(i*2+1,m,r,b,e,f,args...);
		if(b<=a.a)return a;
		return findr(i*2,l,m,b,e,f,args...);
	}
	template<class F,class...Args>
	pair<int,N> find(int b,int e,F f,Args...args){
		assert(b<e);
		return findr(1,0,s,b,e,f,args...);
	}
};

//usage

//Range add,max
struct N{
	int lz,mx;
	N(int v=0):lz(0),mx(v){}
	bool add(int v){
		lz+=v;
		return true;
	}
	void push(N&x,N&y){
		x.add(lz);
		y.add(lz);
		mx+=lz;
		lz=0;
	}
	static N merge(N x,N y){
		return N(max(x.getm(),y.getm()));
	}
	int getm(){return mx+lz;}
	bool find(int v){
		return getm()>=v;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	const int s=1000010;
	segbeats<N> seg(vi(s,0));
	
	int n,m;
	cin>>n>>m;
	vi a(n);rep(i,n)cin>>a[i];
	vi b(m);rep(i,m)cin>>b[i];
	
	rep(i,n)
		seg.ch(0,a[i]+1,&N::add,1);
	rep(i,m)
		seg.ch(0,b[i]+1,&N::add,-1);
	
	int q;cin>>q;
	rep(_,q){
		int t;cin>>t;
		if(t==1){
			int i,x;cin>>i>>x;
			i--;
			seg.ch(0,a[i]+1,&N::add,-1);
			a[i]=x;
			seg.ch(0,a[i]+1,&N::add,1);
		}else{
			int i,x;cin>>i>>x;
			i--;
			seg.ch(0,b[i]+1,&N::add,1);
			b[i]=x;
			seg.ch(0,b[i]+1,&N::add,-1);
		}
		int pos=seg.find(0,s,&N::find,1).a;
		cout<<pos<<"\n";
	}
}