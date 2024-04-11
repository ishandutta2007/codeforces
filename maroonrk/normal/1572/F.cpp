#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

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

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
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
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
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
ll mask(int i){
	return (ll(1)<<i)-1;
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
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}

//atcoder-library 

//N() 

//merge  inactive 
//lazy 

//get 
// min  0  1 

//VERIFY:
//https://atcoder.jp/contests/practice2/tasks/practice2_k
template<class N>
struct seglazy{
	vc<N> x;
	int L,s;
	seglazy(){}
	template<class T>
	seglazy(const vc<T>& a){
		int n=a.size();
		L=0;
		while((1<<L)<n)L++;
		s=1<<L;
		x.resize(s*2);
		rep(i,n)x[s+i]=N(a[i]);
		gnr(i,1,s)upd(i);
	}
	void upd(int i){
		x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	N composite(int l,int r){
		assert(0<=l&&l<=r&&r<=s);
		if(l==r)return N();
		
		l+=s;
		r+=s;
		
		for (int i = L; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}
		
		N sml,smr;
		while (l < r) {
			if (l & 1) sml = N::merge(sml, x[l++]);
			if (r & 1) smr = N::merge(x[--r], smr);
			l >>= 1;
			r >>= 1;
		}

		return N::merge(sml, smr);
	}
	template<class F,class... Args>
	void ch(int l, int r, F f,Args&&... args) {
		assert(0<=l&&l<=r&&r<=s);
		if (l == r) return;

		l+=s;
		r+=s;

		for (int i = L; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}
		
		static int buf[2][30];
		int cnt[2]{};
		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1){
					//(x[l++].*f)(forward<Args>(args)...);
					buf[0][cnt[0]++]=l++;
				}
				if (r & 1){
					//(x[--r].*f)(forward<Args>(args)...);
					buf[1][cnt[1]++]=--r;
				}
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}
		rep(i,cnt[0])(x[buf[0][i]].*f)(forward<Args>(args)...);
		per(i,cnt[1])(x[buf[1][i]].*f)(forward<Args>(args)...);

		for (int i = 1; i <= L; i++) {
			if (((l >> i) << i) != l) upd(l >> i);
			if (((r >> i) << i) != r) upd((r - 1) >> i);
		}
	}
	N getall(){return x[1];}
	template <class F,class... Args> 
	pair<int,N> max_right(int l,F f,Args&&... args){
		assert(0<=l&&l<=s);
		if(l==s)return mp(s,N());
		l+=s;
		
		for (int i = L; i >= 1; i--) push(l >> i);
		N sm;
		assert((sm.*f)(forward<Args>(args)...));
		do {
			while (l % 2 == 0) l >>= 1;
			if (!(N::merge(sm,x[l]).*f)(forward<Args>(args)...)){
				while (l < s) {
					push(l);
					l = (2 * l);
					N tmp=N::merge(sm,x[l]);
					if ((tmp.*f)(forward<Args>(args)...)) {
						sm = tmp;
						l++;
					}
				}
				return mp(l - s,sm);
			}
			sm = N::merge(sm, x[l]);
			l++;
		} while ((l & -l) != l);
		return mp(s,sm);
	}
	//XXI Opencup Krakow M
	template <class F,class... Args> 
	pair<int,N> min_left(int r,F f,Args&&... args){
		assert(0<=r&&r<=s);
        if(r==0)return mp(0,N());
        r+=s;
        for (int i = L; i >= 1; i--) push((r - 1) >> i);
        N sm;
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!(N::merge(x[r],sm).*f)(forward<Args>(args)...)) {
                while (r < s) {
                    push(r);
                    r = (2 * r + 1);
                    N tmp=N::merge(x[r],sm);
                    if ((tmp.*f)(forward<Args>(args)...)) {
                        sm = tmp;
                        r--;
                    }
                }
                return mp(r + 1 - s,sm);
            }
            sm = N::merge(x[r], sm);
        } while ((r & -r) != r);
        return mp(0,sm);
    }
	template<class F,class...Args>
	void point_change(int p,F f,Args&&...args){
		assert(0 <= p && p < s);
		p += s;
		for (int i = L; i >= 1; i--) push(p >> i);
		(x[p].*f)(forward<Args>(args)...);
		for (int i = 1; i <= L; i++) upd(p >> i);
	}
	N point_get(int p){
		assert(0 <= p && p < s);
		p += s;
		for (int i = L; i >= 1; i--) push(p >> i);
		return x[p];
	}
	void point_set(int p,N val){
		assert(0 <= p && p < s);
		p += s;
		for (int i = L; i >= 1; i--) push(p >> i);
		x[p]=val;
		for (int i = 1; i <= L; i++) upd(p >> i);
	}
	void enumerater(int l,int r,int i,int b,int e,vc<N>&dst){
		if(e<=l||r<=b)
			return;
		if(l+1==r){
			dst.pb(x[i]);
			return;
		}
		push(i);
		int m=(l+r)/2;
		enumerater(l,m,i*2,b,e,dst);
		enumerater(m,r,i*2+1,b,e,dst);
	}
	void enumerate(int b,int e,vc<N>&dst){
		assert(b<=e);
		return enumerater(0,s,1,b,e,dst);
	}
};

//merge  inactive 
//lazy 

//get 
// min  0  1 

//VERIFY: yosupo
//KUPC2017I
//HDU 5306 Gorgeous Sequence
//findmin/max CF458E
template<class N>
struct segbeats{
	vc<N> x;
	int s;
	segbeats(){}
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
	void chr(int l,int r,int i,int b,int e,F f,Args&&... args){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e&&(x[i].*f)(forward<Args>(args)...))
			return;
		push(i);
		int m=(l+r)/2;
		chr(l,m,i*2,b,e,f,forward<Args>(args)...);
		chr(m,r,i*2+1,b,e,f,forward<Args>(args)...);
		upd(i);
	}
	template<class F,class... Args>
	void ch(int b,int e,F f,Args&&... args){
		assert(b<=e);
		chr(0,s,1,b,e,f,forward<Args>(args)...);
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
		assert(b<=e);
		return getr(0,s,1,b,e,f,g,h);
	}
	auto compositer(int l,int r,int i,int b,int e){
		if(e<=l||r<=b)assert(0);
		if(b<=l&&r<=e)
			return x[i];
		push(i);
		int m=(l+r)/2;
		if(e<=m)return compositer(l,m,i*2,b,e);
		if(m<=b)return compositer(m,r,i*2+1,b,e);
		return N::merge(compositer(l,m,i*2,b,e),compositer(m,r,i*2+1,b,e));
	}
	//work without identity node
	auto composite(int b,int e){
		assert(b<e);
		return compositer(0,s,1,b,e);
	}
	N getall(){return x[1];}
	//return minimum index
	template<class F,class...Args>
	pair<int,N> findminr(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {e,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(forward<Args>(args)...))return {e,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findminr(i*2,l,m,b,e,f,forward<Args>(args)...);
		if(a.a<e)return a;
		return findminr(i*2+1,m,r,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> findmin(int b,int e,F f,Args&&...args){
		assert(b<=e);
		return findminr(1,0,s,b,e,f,forward<Args>(args)...);
	}
	//return maximum index
	template<class F,class...Args>
	pair<int,N> findmaxr(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {b-1,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(forward<Args>(args)...))return {b-1,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findmaxr(i*2+1,m,r,b,e,f,forward<Args>(args)...);
		if(a.a>=b)return a;
		return findmaxr(i*2,l,m,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> findmax(int b,int e,F f,Args&&...args){
		assert(b<=e);
		return findmaxr(1,0,s,b,e,f,forward<Args>(args)...);
	}
	void enumerater(int l,int r,int i,int b,int e,vc<N>&dst){
		if(e<=l||r<=b)
			return;
		if(l+1==r){
			dst.pb(x[i]);
			return;
		}
		push(i);
		int m=(l+r)/2;
		enumerater(l,m,i*2,b,e,dst);
		enumerater(m,r,i*2+1,b,e,dst);
	}
	void enumerate(int b,int e,vc<N>&dst){
		assert(b<=e);
		return enumerater(0,s,1,b,e,dst);
	}
	
	//KUPC 2020 G
	template<class F,class...Args>
	void enumerate_by_findr(int l,int r,int i,int b,int e,vc<pair<int,N>>&dst,F f,Args&&...args){
		if(e<=l||r<=b||!(x[i].*f)(forward<Args>(args)...))
			return;
		if(l+1==r){
			dst.eb(l,x[i]);
			return;
		}
		push(i);
		int m=(l+r)/2;
		enumerate_by_findr(l,m,i*2,b,e,dst,f,forward<Args>(args)...);
		enumerate_by_findr(m,r,i*2+1,b,e,dst,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	void enumerate_by_find(int b,int e,vc<pair<int,N>>&dst,F f,Args&&...args){
		assert(b<=e);
		enumerate_by_findr(0,s,1,b,e,dst,f,forward<Args>(args)...);
	}
	void prepare(int i){
		if(i/=2){
			prepare(i);
			push(i);
		}
	}
	//point_update  lazy 
	void point_set(int i,N w){
		i+=s;
		prepare(i);
		x[i]=w;
		while(i/=2)
			upd(i);
	}
	template<class F,class...Args>
	void point_change(int i,F f,Args&&...args){
		i+=s;
		prepare(i);
		(x[i].*f)(forward<Args>(args)...);
		while(i/=2)
			upd(i);
	}
	//not verified
	N point_get(int i){
		i+=s;
		prepare(i);
		return x[i];
	}
};

vc<pi> work;

struct N{
	int mx,cnt,sec,lz;
	N(int v=-1):mx(v),cnt(1),sec(-1),lz(inf){}
	bool setlim(int v,bool add=false){
		if(mx<=v){
			chmin(lz,v);
			return true;
		}
		if(sec<v){
			chmin(lz,v);
			if(add)work.eb(mx,cnt);
			mx=v;
			return true;
		}
		return false;
	}
	void push(N&x,N&y){
		bool tmp=x.setlim(lz);
		assert(tmp);
		tmp=y.setlim(lz);
		assert(tmp);
		lz=inf;
	}
	static N merge(N x,N y){
		N res;
		res.mx=max(x.mx,y.mx);
		res.sec=max(x.sec,y.sec);
		res.cnt=0;
		if(res.mx==x.mx)res.cnt+=x.cnt;
		else chmax(res.sec,x.mx);
		if(res.mx==y.mx)res.cnt+=y.cnt;
		else chmax(res.sec,y.mx);
		return res;
	}
};

//Range add,sum
struct AS{
	ll len,sum,lz;
	AS(pair<ll,ll> z=mp(0,0)):len(z.a),sum(z.b),lz(0){}
	void add(int v){
		sum+=v*len;
		lz+=v;
		return;
	}
	void push(AS&x,AS&y){
		x.add(lz);
		y.add(lz);
		lz=0;
	}
	static AS merge(AS x,AS y){
		return AS(mp(x.len+y.len,x.sum+y.sum));
	}
};

bool dbg=false;

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,q;
	cin>>n;
	if(n<0){
		dbg=true;
		n=-n;
		q=n;
	}else{
		cin>>q;
	}
	
	vi rw(n);iota(all(rw),1);
	segbeats<N> seg(rw);
	seglazy<AS> as(vc<pair<ll,ll>>(n,mp(1,1)));
	
	rep(_,q){
		int p;
		if(dbg){
			p=1;
		}else{
			cin>>p;
		}
		if(p==1){
			int i,g;
			if(dbg){
				i=rand_int(0,n-1);
				g=rand_int(i+1,n);
			}else{
				cin>>i>>g;
				i--;
			}
			
			seg.ch(0,i+1,&N::setlim,i,true);
			seg.point_set(i,g);
			as.ch(i,g,&AS::add,1);
			
			dmp(work);
			for(auto [r,cnt]:work){
				as.ch(i,r,&AS::add,-cnt);
			}
			
			work.clear();
		}else{
			int l,r;
			if(dbg){
				l=rand_int(0,n-1);
				r=rand_int(l+1,n);
			}else{
				cin>>l>>r;
				l--;
			}
			print(as.composite(l,r).sum);
		}
	}
}