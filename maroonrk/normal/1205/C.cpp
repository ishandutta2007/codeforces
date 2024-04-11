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
    static mt19937_64 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

bool ask(int r1,int c1,int r2,int c2){
	cout<<"? "<<r1+1<<" "<<c1+1<<" "<<r2+1<<" "<<c2+1<<endl;
	return read();
}

bool same(int r1,int c1,int r2,int c2){
	if(r1+c1>r2+c2){
		swap(r1,r2);
		swap(c1,c2);
	}
	return ask(r1,c1,r2,c2);
}

int n;
vvc<int> ans;

void dfs(int r,int c,int v){
	assert(ans[r][c]==-1);
	ans[r][c]=v;
	rng(dr,-2,3){
		for(auto dc:{2-abs(dr),abs(dr)-2}){
			if(dr*dc<0)continue;
			int nr=r+dr,nc=c+dc;
			if(inc(0,nr,n-1)&&inc(0,nc,n-1)&&ans[nr][nc]==-1){
				dfs(nr,nc,v^!same(r,c,nr,nc));
			}
		}
	}
}

void brute(int of){
	if(ans[of][of+2]!=ans[of+1][of+1]){
		dfs(of+1,of+2,ask(of,of,of+1,of+2));
		return;
	}
	/*if(ans[of+2][of]!=ans[of+1][of+1]){
		dfs(of+2,of+1,ask(of,of,of+2,of+1));
		return;
	}*/
	if(ans[of][of]==ans[of+1][of+1]){
		if(same(of,of+1,of+1,of+2)){
			dfs(of+1,of+2,ask(of,of,of+1,of+2));
		}else{
			dfs(of+1,of+2,ask(of,of+1,of+2,of+2));
		}
	}else{
		if(same(of,of+1,of+1,of+2)){
			dfs(of+1,of+2,!ask(of,of+1,of+2,of+2));
		}else{
			dfs(of+1,of+2,ask(of,of,of+1,of+2));
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	cin>>n;
	ans.resize(n,vi(n,-1));
	ans[n-1][n-1]=0;
	dfs(0,0,1);
	rep(i,n-2){
		if(ans[i][i]==1&&ans[i+2][i+2]==0){
			brute(i);
			break;
		}
	}
	cout<<"!"<<endl;
	for(auto v:ans)
	//	print(v);
	rep(i,n)
		print(v[i],i==n-1?1:0);
}