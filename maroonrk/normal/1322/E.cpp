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

// bit op
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

struct FastSet {
    static constexpr uint B = 64;
    int n, lg;
    vvc<ull> seg;
    FastSet(int _n,ull val=0) : n(_n) {
        do {
            seg.push_back(vc<ull>((_n + B - 1) / B,val));
            _n = (_n + B - 1) / B;
        } while (_n > 1);
        lg = seg.size();
    }
    bool operator[](int i) const {
        return (seg[0][i / B] >> (i % B) & 1) != 0;
    }
    void set(int i) {
        for (int h = 0; h < lg; h++) {
            seg[h][i / B] |= 1ULL << (i % B);
            i /= B;
        }
    }
    void reset(int i) {
        for (int h = 0; h < lg; h++) {
            seg[h][i / B] &= ~(1ULL << (i % B));
            if (seg[h][i / B]) break;
            i /= B;
        }
    }
    // x
    int next(int i) {
        for (int h = 0; h < lg; h++) {
            if (i / B == seg[h].size()) break;
            ull d = seg[h][i / B] >> (i % B);
            if (!d) {
                i = i / B + 1;
                continue;
            }
            // find
            i += bsf(d);
            for (int g = h - 1; g >= 0; g--) {
                i *= B;
                i += bsf(seg[g][i / B]);
            }
            return i;
        }
        return n;
    }
    // x
    int prev(int i) {
        i--;
        for (int h = 0; h < lg; h++) {
            if (i == -1) break;
            ull d = seg[h][i / B] << (63 - i % 64);
            if (!d) {
                i = i / B - 1;
                continue;
            }
            // find
            i += bsr(d) - (B - 1);
            for (int g = h - 1; g >= 0; g--) {
                i *= B;
                i += bsr(seg[g][i / B]);
            }
            return i;
        }
        return -1;
    }
};


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi a;
	if(n<0){
		n=-n;
		a.resize(n);
		rep(i,n)a[i]=rand_int(1,ten(9));
	}else{
		a=readvi(n);
	}
	
	vi ans(n,-1);
	ans[0]=a[0];
	ans[n-1]=a[n-1];
	
	auto waf=[&](FastSet&s,int l,int r,int v){
		/*while(itr!=s.ed){
			int i=*itr;
			if(i>=r)break;
			if(ans[i]==-1)ans[i]=v;
			itr=s.erase(itr);
		}*/
		while(1){
			int i=s.next(l);
			if(i>=r)break;
			if(ans[i]==-1)ans[i]=v;
			s.reset(i);
		}
	};
	
	int turns=0;
	
	multiset<int> ts;
	FastSet und(n,-1);
	
	map<int,vi> pos;
	rep(i,n)pos[-a[i]].pb(i);
	
	//set<int> fix;
	//rng(i,-10,n+10)fix.insert(i);
	FastSet fix(n+20,-1);
	
	vi val(n);
	
	auto ysp=[&](int i,int j,int v){
		if(i<0||n<=j)return;
		assert(i<j);
		if(i+1==j){
			if(val[i])waf(und,i,i+1,v);
			if(val[j])waf(und,j,j+1,v);
			return;
		}
		dmp2(i,j);
		if(val[i]==val[j]){
			ts.insert((j-i)/2);
			if(val[i]){
				waf(und,i,j+1,v);
			}
		}else{
			ts.insert((j-1-i)/2);
			int mid=(i+j+1)/2;
			if(val[i]){
				waf(und,i,mid,v);
			}else{
				waf(und,mid,j+1,v);
			}
		}
	};
	
	auto mrt=[&](int i,int j){
		if(i<0||n<=j)return;
		assert(i<j);
		if(i+1==j)return;
		if(val[i]==val[j]){
			ts.erase(ts.find((j-i)/2));
		}else{
			ts.erase(ts.find((j-1-i)/2));
		}
	};
	
	auto updfix=[&](int i){
		if(i<=0||n-1<=i)return;
		if(val[i-1]==val[i]||val[i]==val[i+1])
			fix.set(i+10);
		else
			fix.reset(i+10);
	};
	
	for(auto kv:pos){
		int v=-kv.a;
		dmp(v);
		dmp(kv.b);
		for(auto i:kv.b){
			{
				int z=fix.next(i+1+11);
				vi ps;
				while(1){
					ps.pb(z-10);
					if(z-10<i-1)break;
					z=fix.prev(z);
				}
				reverse(all(ps));
				assert(si(ps)>=2);
				rep(j,si(ps)-1)
					mrt(ps[j],ps[j+1]);
			}
			val[i]=1;
			rng(j,i-1,i+2)updfix(j);
			{
				int z=fix.next(i+1+11);
				vi ps;
				while(1){
					ps.pb(z-10);
					if(z-10<i-1)break;
					z=fix.prev(z);
				}
				reverse(all(ps));
				assert(si(ps)>=2);
				rep(j,si(ps)-1)
					ysp(ps[j],ps[j+1],v);
			}
		}
		if(si(ts)){
			chmax(turns,*ts.rbegin());
		}
	}
	
	print(turns);
	print(ans);
}