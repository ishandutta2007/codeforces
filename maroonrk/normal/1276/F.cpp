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

void print(ll x,int suc=1){
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
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<endl;
	#else
	cout<<"Possible"<<endl;
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<endl;
	#else
	cout<<"Impossible"<<endl;
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

//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n):p(n,-1),s(n,1),c(n){}
	int find(int a){
		return p[a]==-1?a:(p[a]=find(p[a]));
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	int sz(int a){
		return s[find(a)];
	}
};

//yosupo
//TKPPC G
struct SA{
	int n;
	vi sa,as,lcp;
	SA(){}
	template<class t> SA(t s):n(s.size()),sa(n),as(n),lcp(n-1){
		rep(i,n)sa[i]=n-1-i;
		stable_sort(all(sa),[&](int a,int b){return s[a]<s[b];});
		vi c(n);
		rep(i,n)c[i]=s[i];
		for(int w=1;w<n;w*=2){
			vi d(c);
			rep(i,n){
				if(i&&sa[i-1]+w<n&&d[sa[i-1]]==d[sa[i]]&&d[sa[i-1]+w/2]==d[sa[i]+w/2])
					c[sa[i]]=c[sa[i-1]];
				else
					c[sa[i]]=i;
			}
			vi e(sa),f(n);
			iota(all(f),0);
			rep(i,n){
				int j=e[i]-w;
				if(j>=0)sa[f[c[j]]++]=j;
			}
		}
		//as
		rep(i,n)as[sa[i]]=i;
		//lcp
		int w=0;
		for(auto i:as){
			if(w)w--;
			if(i<n-1){
				while(max(sa[i],sa[i+1])+w<n&&s[sa[i]+w]==s[sa[i+1]+w])w++;
				lcp[i]=w;
			}
		}
	}
};

//CF530F
//returns the suffix tree
//the i-th (0<=i<=n-1) element corresponds to the lexicographically i-th suffix
struct ste{
	int to,l,r;
	operator int()const{return to;}
};
ostream&operator<<(ostream&os,const ste&a){
	return os<<"ste{"<<a.to<<","<<a.l<<" "<<a.r<<"}";
}
pair<vvc<ste>,int> stree(const SA&sa){
	int n=sa.n,s=n*2-1;
	vi len(s);
	rep(i,n)len[i]=n-sa.sa[i];
	rep(i,n-1)len[i+n]=sa.lcp[i];
	vi idx(n-1);
	iota(all(idx),n);
	stable_sort(all(idx),[&](int a,int b){return len[a]>len[b];});
	unionfind uf(s);
	vi par(s,-1),c(s,-1);
	rep(i,n)c[i]=sa.sa[i];
	for(auto i:idx){
		int a=uf.find(i-n),b=uf.find(i-n+1);
		uf.unite(i,a);
		uf.unite(i,b);
		par[a]=i;
		par[b]=i;
		c[i]=c[a];
	}
	par[n==1?0:idx.back()]=s++;
	len.pb(0);
	uf=unionfind(s);
	rep(i,s-1)if(len[i]==len[par[i]])
		uf.unite(i,par[i]);
	vi vs;
	rep(i,s)if(uf.find(i)==i)vs.pb(i);
	auto z=[&](int i){return lower_bound(all(vs),uf.find(i))-vs.bg;};
	vvc<ste> res(vs.size());
	rep(ii,s-1){
		int i=ii/2+ii%2*n;
		int a=z(i),b=z(par[i]);
		if(a==b)continue;
		res[b].pb(ste{a,c[i]+len[par[i]],c[i]+len[i]});
	}
	return make_pair(res,z(s-1));
}

SA sa;

//AOJGRL5C
template<class t,class u>
struct sparsetable{
	vvc<t> a;
	u f;
	//d must not be empty
	sparsetable(){}
	sparsetable(const vc<t>& d,u ff):f(ff){
		if(d.empty())return;
		int n=d.size(),h=topbit(n);
		a.resize(h+1);
		a[0]=d;
		rng(j,1,h+1){
			a[j].resize(n-(1<<j)+1);
			rep(i,n-(1<<j)+1)
				a[j][i]=f(a[j-1][i],a[j-1][i+(1<<(j-1))]);
		}
	}
	t get(int b,int e){
		assert(b<e);
		int d=topbit(e-b);
		return f(a[d][b],a[d][e-(1<<d)]);
	}
};

auto imin=[&](int x,int y){return min(x,y);};
using ST=sparsetable<int,decltype(imin)>;
ST*st;
int n;

struct solver{
	const vvc<ste>&t;
	vi off_buf;
	struct sub{
		int v;
		int&off;
		sub(int vv,int&o):v(vv),off(o){}
		int getpos()const{
			int i=v+off;
			return i==(int)sa.as.size()?-1:sa.as[i];
		}
		bool operator<(const sub&r)const{
			return getpos()<r.getpos();
		}
	};
	vc<set<sub>> sub_buf;
	int ans;
	struct data{
		set<sub>*s;
		int&off;
		int cnt,cnt_memo;
		vc<decltype(s->bg)> itrs;
		data(set<sub>*p,int&o):s(p),off(o),cnt(0){}
		void save(){
			cnt_memo=cnt;
		}
		void restore(){
			for(auto itr:itrs)
				s->erase(itr);
			itrs.clear();
			cnt=cnt_memo;
		}
		void dif(int a,int b,int c){
			if(a==-1||b==-1)return;
			cnt+=st->get(min(a,b),max(a,b))*c;
		}
		void add(int i,bool do_save=false){
			dmp2(cnt,i);
			cnt+=n-i;
			sub z(i-off,off);
			auto itr=s->insert(z).a;
			if(do_save)itrs.pb(itr);
			int a=-1,b=z.getpos(),c=-1;
			if(itr!=s->bg){
				a=prev(itr)->getpos();
				dif(a,b,-1);
			}
			itr++;
			if(itr!=s->ed){
				c=itr->getpos();
				dif(b,c,-1);
			}
			dif(a,c,1);
		}
		int advance(int k){
			int res=cnt*k+k*(k+1)/2;
			cnt+=k;
			off-=k;
			return res;
		}
	};
	data dfs(int v){
		if(t[v].empty()){
			assert(v<n);
			data res(&sub_buf[v],off_buf[v]);
			res.add(n);
			return res;
		}
		vc<data> w;
		for(auto e:t[v]){
			data c=dfs(e.to);
			ans+=c.advance(e.r-e.l-1);
			dmp2(e.l,e.r);
			dmp(ans);
			w.pb(c);
		}
		int mx=0;
		rep(i,w.size())
			if(w[i].s->size()>w[mx].s->size())
				mx=i;
		dmp(w[mx].s->size());
		dmp(w[mx].itrs.size());
		w[mx].save();
		dmp(w.size());
		rep(i,w.size())
			dmp2(i,w[i].s->size());
		rep(i,w.size())if(i!=mx)
			for(auto suf:*w[i].s){
				dmp2(w[i].off,suf.off);
				w[mx].add(suf.v+suf.off,true);
			}
		ans+=w[mx].cnt+1;
		dmp(w[mx].cnt+1);
		w[mx].restore();
		rep(i,w.size())
			w[i].advance(1);
		rep(i,w.size())if(i!=mx)
			for(auto suf:*w[i].s)
				w[mx].add(suf.v+suf.off);
		dmp2(v,w[mx].off);
		dmp(w[mx].s->size());
		return w[mx];
	}
	solver(const vvc<ste>&tt,int root):t(tt),
	off_buf(n),sub_buf(n),ans(0){
		auto w=dfs(root);
		dmp(w.cnt);
		ans+=w.cnt;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	string s;
	bool dbg=false;
	
	if(!dbg){
		cin>>s;
		n=s.size();
	}else{
		n=4;
		s=string(n,'a');
		rep(i,n)
			s[i]=rand_int('a','b');
		dmp(s);
	}
	//dbg=true;
	
	int brute=0;
	if(dbg){
		set<string> ss;
		rep(i,n)rng(j,i+1,n+1)
			ss.insert(s.substr(i,j-i));
		rep(k,n){
			string t=s;
			t[k]='*';
			rep(i,n)rng(j,i+1,n+1)
				ss.insert(t.substr(i,j-i));
		}
		brute=ss.size();
	}
	
	
	sa=SA(s);
	st=new ST(sa.lcp,imin);
	auto tree=stree(sa);
	
	int ans=solver(tree.a,tree.b).ans;
	
	if(dbg){
		dmp2(ans,brute);
		assert(ans==brute);
	}
	
	print(ans+1);
	delete st;
}