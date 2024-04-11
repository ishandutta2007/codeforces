#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

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

vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}


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
	seglazy(int n){
		L=0;
		while((1<<L)<n)L++;
		s=1<<L;
		x.assign(s*2,N());
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

//N() 
//VERIFY: yosupo
//CF407E
template<class N>
struct segtree{
	vc<N> x;
	int s;
	segtree(){}
	template<class t>
	segtree(vc<t> a){
		int n=a.size();
		s=1;
		while(s<n){s*=2;}
		x.resize(s*2);
		rep(i,n)
			x[s+i]=N(a[i]);
		gnr(i,1,s)
			x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	//NOT Verified
	segtree(int n){
		resize(n);
	}
	void resize(int n){
		s=1;
		while(s<n){s*=2;}
		x.assign(s*2,N());
		gnr(i,1,s)
			x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	void set(int i,const N&t){
		i+=s;
		x[i]=t;
		while(i>>=1)x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	void point_merge(int i,const N&t){
		i+=s;
		x[i]=N::merge(x[i],t);
		while(i>>=1)x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	N composite(int b,int e){
		assert(b<=e);
		N lf,rt;
		for(int l=b+s,r=e+s;l<r;l>>=1,r>>=1){
			if (l&1){
				lf=N::merge(lf,x[l]);
				l++;
			}
			if (r&1){
				r--;
				rt=N::merge(x[r],rt);
			}
		}
		return N::merge(lf,rt);
	}
	N getall(){
		return x[1];
	}
	//UTPC2020E
	//n 
	template <class F,class... Args> 
	pair<int,N> max_right(int l,F f,Args&&... args){
		assert(0<=l&&l<=s);
		if(l==s)return mp(s,N());
		l+=s;
		
		N sm;
		assert((sm.*f)(forward<Args>(args)...));
		do {
			while (l % 2 == 0) l >>= 1;
			if (!(N::merge(sm,x[l]).*f)(forward<Args>(args)...)){
				while (l < s) {
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
	//UTPC2020E
	template <class F,class... Args> 
	pair<int,N> min_left(int r,F f,Args&&... args){
		assert((N().*f)(forward<Args>(args)...));
		assert(0<=r&&r<=s);
        if(r==0)return mp(0,N());
        r+=s;
        N sm;
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!(N::merge(x[r],sm).*f)(forward<Args>(args)...)) {
                while (r < s) {
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
    //
    //CF Goodbye 2016 E
	template<class F,class T>
	T accumulate(int l, int r,F f,T t) {
		assert(0<=l&&l<=r&&r<=s);
		if (l == r) return t;

		l+=s;
		r+=s;

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
		rep(i,cnt[0])t=(x[buf[0][i]].*f)(t);
		per(i,cnt[1])t=(x[buf[1][i]].*f)(t);

		return t;
	}
};

//Range add,min
struct N{
	int lz,mn;
	N(int v=inf):lz(0),mn(v){}
	void add(int v){
		mn+=v;
		lz+=v;
	}
	void push(N&x,N&y){
		x.add(lz);
		y.add(lz);
		lz=0;
	}
	static N merge(N x,N y){
		return N(min(x.getm(),y.getm()));
	}
	int getm(){return mn;}
	bool ok(int v){
		return mn>v;
	}
};

struct M{
	int l,r;
	bool inv;
	M(int v=-1):l(v==-1?inf:v),r(v==-1?-inf:v),inv(false){}
	static M merge(const M&x,const M&y){
		M res;
		res.inv=x.inv|y.inv;
		res.l=min(x.l,y.l);
		res.r=max(x.r,y.r);
		if(x.r>y.l)res.inv=true;
		return res;
	}
};

//strictly increasing sequence
int getlis(vi x){
	int n=si(x),ans=0;
	vi buf(n,inf);
	for(auto v:x){
		int i=lwb(buf,v);
		chmax(ans,i+1);
		buf[i]=v;
	}
	return ans;
}

void slv(){
	int n,qs;cin>>n>>qs;
	int s=2*n+1;
	vi p=readvi(s,-1);
	vi q(s);
	rep(i,s)q[p[i]]=i;
	
	seglazy<N> seg(vi(s,0));
	segtree<M> lw(s),up(s);
	
	auto weight=[&](int v)->int{
		if(v<n)return -1;
		else if(v>n)return 1;
		else return 0;
	};
	
	auto upd=[&](int i){
		if(p[i]<n){
			lw.set(i,p[i]);
			up.set(i,-1);
		}else if(p[i]>n){
			lw.set(i,-1);
			up.set(i,p[i]);
		}else{
			lw.set(i,-1);
			up.set(i,-1);
		}
	};
	
	rep(i,s){
		seg.ch(i+1,s,&N::add,weight(p[i]));
		upd(i);
	}
	
	rep(_,qs){
		int i,j;cin>>i>>j;
		i--;j--;if(i>j)swap(i,j);
		
		int dif=weight(p[j])-weight(p[i]);
		seg.ch(i+1,j+1,&N::add,dif);
		
		swap(p[i],p[j]);
		swap(q[p[i]],q[p[j]]);
		
		upd(i);
		upd(j);
		
		int mn=seg.getall().mn;
		int ans=-1;
		if(seg.point_get(q[n]).mn==mn){
			if(ans==-1){
				auto lf=lw.composite(0,q[n]);
				auto rt=lw.composite(q[n]+1,s);
				auto z=M::merge(rt,lf);
				if(z.inv){
					ans=(q[n]+1)%s;
					//print(q[n]+1);
					//continue;
				}
			}
			if(ans==-1){
				auto lf=up.composite(0,q[n]);
				auto rt=up.composite(q[n]+1,s);
				auto z=M::merge(rt,lf);
				if(z.inv){
					ans=q[n];
					//print(q[n]);
					//continue;
				}
			}
		}else{
			int k=seg.max_right(0,&N::ok,mn).a;
			//print(k);
			ans=k;
		}
		
		if(0){
			if(ans!=-1){
				vi w=p;
				rotate(w.bg,w.bg+ans,w.ed);
				
			}
		}
		
		print(ans);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}