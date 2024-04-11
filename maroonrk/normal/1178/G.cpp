#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

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

#define mp make_pair
#define mt make_tuple

using uint=unsigned;
using ull=unsigned long long;

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

void print(ll x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<endl;
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
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
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
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
    //static random_device rd;
    static mt19937 gen(2434);
    return uniform_int_distribution<ll>(l, r)(gen);
}

const int Nmax=200010;
vi g[Nmax];
int in[Nmax],out[Nmax],as[Nmax],bs[Nmax],ei;
void dfs(int v){
	in[v]=ei++;
	for(auto to:g[v]){
		as[to]+=as[v];
		bs[to]+=bs[v];
		dfs(to);
	}
	out[v]=ei;
}

ll fdiv(ll a,ll b){
	return a/b-((a^b)<0&&a%b);
}
struct ln{
	ll a,b;
	ll eval(int x){return a*x+b;}
};
ll pos(ln x,ln y){
	return fdiv(x.b-y.b,y.a-x.a);
}

ln buf[Nmax*2];

struct CHT{
	int l,r;
	void init(int x){
		l=r=x;
	}
	void add(ln a){
		if(l<r&&buf[r-1].a==a.a){
			chmax(a.b,buf[r-1].b);
			r--;
		}
		while(r-l>=2){
			ll x=pos(buf[r-2],buf[r-1]);
			ll y=pos(buf[r-1],a);
			if(x<y)break;
			r--;
		}
		buf[r++]=a;
	}
	ll query(int x){
		while(r-l>=2){
			if(buf[l].eval(x)>buf[l+1].eval(x))
				break;
			l++;
		}
		return buf[l].eval(x);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	bool dbg=false;
	if(n==-1){
		n=200000;
		dbg=true;
	}
	int q;
	if(dbg)q=100000;
	else cin>>q;
	rng(i,1,n){
		int p;
		if(dbg)p=i-1;
		else cin>>p;
		g[p-1].pb(i);
	}
	if(dbg){
		rep(i,n)
			as[i]=rand_int(-5000,5000);
		rep(i,n)
			bs[i]=rand_int(-5000,5000);
	}else{
		rep(i,n)
			cin>>as[i];
		rep(i,n)
			cin>>bs[i];
	}
	dfs(0);
	
	vc<ll> val(2*n);
	vc<pi> bi;
	rep(i,n){
		val[in[i]*2]=ll(as[i])*bs[i];
		bi.eb(bs[i],in[i]*2);
		val[in[i]*2+1]=ll(as[i])*(-bs[i]);
		bi.eb(-bs[i],in[i]*2+1);
	}
	sort(all(bi));
	
	vc<pi> qs;
	rep(i,q){
		int t,v;
		if(dbg){
			t=rand_int(1,2);
			v=rand_int(0,n-1);
		}else{
			cin>>t>>v;v--;
		}
		if(t==1){
			int x;
			if(dbg)
				x=rand_int(1,5000);
			else
				cin>>x;
			qs.eb(v,x);
		}else{
			qs.eb(v,-1);
		}
	}
	dmp(qs);
	
	const int B=2000;
	
	vi cur(n*2);
	vc<ll> ans;
	for(int i=0;i<q;i+=B){
		vi pos;
		rng(j,i,min(i+B,q)){
			pos.pb(in[qs[j].a]*2);
			pos.pb(out[qs[j].a]*2);
		}
		mkuni(pos);
		int s=pos.size()-1;
		vc<CHT> cs(s);
		fill(all(cur),-1);
		rep(j,s){
			cs[j].init(pos[j]);
			rng(k,pos[j],pos[j+1])
				cur[k]=j;
		}
		for(auto w:bi){
			int j=cur[w.b];
			if(j==-1)continue;
			cs[j].add(ln{w.a,val[w.b]});
		}
		vi xs(s);
		rng(j,i,min(i+B,q)){
			int l=lower_bound(all(pos),in[qs[j].a]*2)-pos.bg;
			int r=lower_bound(all(pos),out[qs[j].a]*2)-pos.bg;
			if(qs[j].b==-1){
				ll mx=0;
				rng(k,l,r)
					chmax(mx,cs[k].query(xs[k]));
				ans.pb(mx);
			}else{
				rng(k,l,r)
					xs[k]+=qs[j].b;
			}
		}
		for(auto w:bi){
			int j=cur[w.b];
			if(j==-1)continue;
			val[w.b]+=ll(w.a)*xs[j];
		}
	}
	
	for(auto v:ans)
		cout<<v<<"\n";
}