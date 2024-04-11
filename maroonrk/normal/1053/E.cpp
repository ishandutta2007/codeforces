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
	cout<<"yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"no"<<endl;
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
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

vi waf(vi a,int bc){
	vi b;
	rep(i,a.size()){
		b.pb(i);
		//dmp(b);
		int s;
		while((s=b.size())>=3){
			int x=b[s-3],y=b[s-2],z=b[s-1];
			bool upd=false;
			if(a[y]!=-1){
				if(a[x]==-1&&a[z]!=-1){
					upd=true;
					a[x]=a[z];
				}else if(a[x]!=-1&&a[z]==-1){
					upd=true;
					a[z]=a[x];
				}
			}
			if(!upd)break;
			b.pop_back();
			b.pop_back();
		}
	}
	for(int i=1;i<int(b.size());i+=2)
		a[b[i]]=bc;
	return a;
}

vi sub(int n,vi a){
	int s=a.size();
	vi nx(s,-1);
	
	vvc<int> pos(n);
	rep(i,s)if(a[i]!=-1)
		pos[a[i]].pb(i);
	
	rep(i,n)
		rep(j,pos[i].size())
			if(pos[i][j]%2!=pos[i][0]%2)
				no();
	
	vc<pi> lr;
	rep(i,n)
		rep(j,int(pos[i].size())-1){
			lr.eb(pos[i][j],pos[i][j+1]);
			nx[pos[i][j]]=pos[i][j+1];
		}
	sort(all(lr),[](pi x,pi y){return x.b-x.a<y.b-y.a;});
	
	vi rem;
	rep(i,n)if(pos[i].empty())
		rem.pb(i);
	
	for(auto w:lr){
		int l=w.a,r=w.b;
		int cur=l+1;
		vi z;
		while(cur<r){
			while(nx[cur]!=-1)cur=nx[cur];
			if(cur>r)no();
			z.pb(a[cur]);
			cur++;
		}
		int cnt=(z.size()+1)/2;
		for(auto v:z)if(v!=-1)cnt--;
		if(cnt<0)no();
		for(auto&v:z)if(v==-1&&cnt){
			v=rem.back();
			rem.pop_back();
			cnt--;
		}
		vi b=waf(z,a[l]);
		cur=l+1;
		rep(i,b.size()){
			while(nx[cur]!=-1)cur=nx[cur];
			a[cur++]=b[i];
		}
	}
	
	return a;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	if(n==1){
		yes(0);
		print(1);
		return 0;
	}
	int s=n*2-1;
	vi a=readvi(s,-1);
	if(a[0]!=-1&&a[s-1]!=-1&&a[0]!=a[s-1])
		no();
	if(a[0]==-1&&a[s-1]!=-1)
		a[0]=a[s-1];
	a.pop_back();
	int o=-1;
	rep(i,s-1)if(a[i]!=-1){
		o=i;
		break;
	}
	if(o==-1){
		a[0]=0;
		o=0;
	}else{
		rep(i,s-1){
			if(i+o<s-1)a[i]=a[i+o];
			else a[i]=-1;
		}
	}
	a.pb(a[0]);
	dmp(a);
	
	vi ans=sub(n,a);
	ans.pop_back();
	yes(0);
	rep(i,s){
		int j=(i+s-1-o)%(s-1);
		print(ans[j]+1,i==s-1?1:2);
	}
}