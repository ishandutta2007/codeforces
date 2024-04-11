#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
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

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
int mask(int i){
	return (int(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

int getmax(const set<int>&s){
	auto itr=s.rbegin();
	if(itr==s.rend())return -1;
	return *itr;
}

struct segtree{
	struct Node{
		set<int> x[2];
		int val,mn;
		Node():val(-1),mn(-1){}
		void upd(int v,int z){
			int a=getmax(x[0]);
			if(a<z)a=-1;
			chmax(a,v);
			int b=getmax(x[1]);
			if(a<b)val=-1;
			else val=a;
			mn=max(z,b);
		}
		void add(int k,int v){
			x[k].insert(v);
		}
		void rem(int k,int v){
			auto itr=x[k].find(v);
			assert(itr!=x[k].ed);
			x[k].erase(itr);
		}
	};
	vc<Node> buf;
	int s;
	void upd(int i){
		int v=-1,z=inf;
		if(i<s){
			chmax(v,buf[i*2].val);
			chmax(v,buf[i*2+1].val);
			chmin(z,buf[i*2].mn);
			chmin(z,buf[i*2+1].mn);
		}else
			z=-1;
		buf[i].upd(v,z);
	}
	segtree(int n){
		s=1;
		while(s<n)s*=2;
		buf.resize(s*2);
	}
	void ch(int b,int e,int k,int v,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			if(k==0){
				//add to 0
				buf[i].add(0,v);
			}else if(k==1){
				//add to 1
				buf[i].rem(0,v);
				buf[i].add(1,v);
			}else if(k==2){
				//rem from 0
				buf[i].rem(0,v);
			}else if(k==3){
				//rem from 1
				buf[i].rem(1,v);
			}else assert(false);
			upd(i);
			return;
		}
		ch(b,e,k,v,l,(l+r)/2,i*2);
		ch(b,e,k,v,(l+r)/2,r,i*2+1);
		upd(i);
	}
	void ch(int b,int e,int k,int v){
		ch(b,e,k,v,0,s,1);
	}
	int gettop(){
		return buf[1].val;
	}
};

struct query{
	int x,l,r,i;
	bool operator<(const query&rhs)const{return x<rhs.x;}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi ys;
	vc<query> qs;
	rep(i,n){
		int a,b,c,d;cin>>a>>b>>c>>d;
		ys.pb(b);
		ys.pb(d);
		qs.pb({a,b,d,i});
		qs.pb({c,b,d,i});
	}
	vi st(n,-1);
	sort(all(qs));
	mkuni(ys);
	segtree seg(si(ys));
	vc<pi> lr(n);
	rep(idx,n*2){
		int l=lwb(ys,qs[idx].l);
		int r=lwb(ys,qs[idx].r);
		int i=qs[idx].i;
		lr[i]=pi(l,r);
		if(st[i]==-1){
			seg.ch(l,r,0,i);
			st[i]=0;
		}else{
			seg.ch(l,r,2+st[i],i);
		}
		if(idx==n*2-1||qs[idx].x<qs[idx+1].x){
			while(1){
				int j=seg.gettop();
				if(j==-1)break;
				assert(st[j]==0);
				st[j]=1;
				seg.ch(lr[j].a,lr[j].b,1,j);
			}
		}
	}
	dmp(st);
	int ans=accumulate(all(st),1);
	print(ans);
}