#include <bits/stdc++.h>
using namespace std;

using uint=unsigned;
using ll=long long;
using ull=unsigned long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define mp make_pair
#define mt make_tuple
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
#define tmp template<class t>

tmp void chmax(t&a,t b){if(a<b)a=b;}
tmp void chmin(t&a,t b){if(a>b)a=b;}

tmp using vc=vector<t>;
tmp using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

tmp ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

tmp void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll read(){ll i;cin>>i;return i;}

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

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

//ayasii
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

//point update
template<class T,class F>
struct SegTree{
	vc<T> buf;
	int s;
	const F f;
	const T g;
	SegTree(const vc<T>& d,F ff,T gg):f(ff),g(gg){
		int n=d.size();
		s=1;
		while(s<n)s*=2;
		buf.resize(s*2,g);
		rep(i,n)
			buf[i+s]=d[i];
		gnr(i,1,s)
			u(i);
	}
	void u(int i){
		buf[i]=f(buf[i*2],buf[i*2+1]);
	}
	void set(int i,T t){
		i+=s;
		buf[i]=t;
		while(i>>=1)u(i);
	}
	T get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return g;
		if(b<=l&&r<=e)return buf[i];
		int m=(l+r)/2;
		return f(get(b,e,l,m,i*2),get(b,e,m,r,i*2+1));
	}
	T get(int b,int e){
		return get(b,e,0,s,1);
	}
};
template<class T,class F>
SegTree<T,F> segtree(const vc<T>& d,F f,T g){
	return SegTree<T,F>(d,f,g);
}

struct W{
	vi x1,x2,y1,y2,as,hs,hxs;
	W():as{0},hs{0},hxs{0}{}
	void push(int a,int b,int c,int d){
		dmp(mt(a,b,c,d));
		x1.pb(a);
		x2.pb(b);
		y1.pb(c);
		y2.pb(d);
		as.pb(as.back()+(d-c)*(b-a));
		hs.pb(hs.back()+(d-c));
		hxs.pb(hxs.back()+(d-c)*b);
	}
	int get(int x,int y){
		int s=upper_bound(all(y2),y)-y2.bg;
		int res=0;
		if(s<int(x1.size()))
			res+=max(y-y1[s],int(0))*max(x2[s]-max(x,x1[s]),int(0));
		int r=min(int(lower_bound(all(x1),x)-x1.bg),s);
		res+=as[s]-as[r];
		int q=min(int(lower_bound(all(x2),x)-x2.bg),s);
		res+=hxs[r]-hxs[q]-x*(hs[r]-hs[q]);
		return res;
	}
};

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	
	int n=read();
	vc<pi> org(n+2);
	rep(i,n+2)org[i]=pi(-1-i,i);
	auto seg=segtree(org,[](pi a,pi b){return min(a,b);},pi(inf,-1));
	vc<W> ws(n+2);
	set<int> vis;
	rep(i,n+2)vis.insert(i);
	struct R{int l,r,t;};
	vc<R> rs(n+2,{-1,-1,-1});
	int ans=0;
	vi raw;
	rep(i,n){
		int a=(read()+ans)%(n+1),l=(read()+ans)%(i+1),r=(read()+ans)%(i+1),k=(read()+ans)%(n+1);
		if(l>r)swap(l,r);
		r++;
		dmp(a);
		dmp(l);
		dmp(r);
		dmp(k);
		raw.pb(a);
		dmp(raw);
		
		const auto cut=[&](int x){
			if(rs[x].l<rs[x].r){
				dmp(x);
				ws[x].push(rs[x].l,rs[x].r,rs[x].t,i);
				rs[x]={-1,-1,-1};
			}
		};
		auto itr=vis.find(a);
		if(itr!=vis.end()){
			cut(a);
			int p=*vis.erase(itr);
			cut(p);
			org[a].a=i;
			seg.set(a,org[a]);
			while(p>a){
				int q=seg.get(0,p).b;
				dmp(pi(p,q));
				vis.insert(q);
				rs[p]={org[p].a+1,org[q].a+1,i};
				p=q;
			}
		}else{
			org[a].a=i;
			seg.set(a,org[a]);
		}
		vis.insert(0);
		cut(0);
		rs[0]={org[0].a+1,i+1,i};
		
		ans=ws[k].get(l,r);
		ans+=max(r-rs[k].t,int(0))*max(rs[k].r-max(rs[k].l,l),int(0));
		print(ans);
	}
}