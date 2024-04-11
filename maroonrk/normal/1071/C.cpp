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
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	vc<tuple<int,int,int>> ans;
	auto brute=[&](int cur,int m,int o){
		vi w;
		rep(i,m)rng(j,i+1,m){
			int k=j*2-i;
			if(k<m)
				w.pb((1<<i)+(1<<j)+(1<<k));
		}
		int s=w.size();
		int res=-1;
		rep(bit,1<<s){
			int x=cur;
			rep(i,s)if(bit&1<<i)
				x^=w[i];
			if(x==0&&popcount(res)>popcount(bit))
				res=bit;
		}
		if(res==-1){
			no();
		}
		rep(i,s)if(res&1<<i){
			int z[3];
			rep(k,3){
				z[k]=topbit(w[i]);
				w[i]^=1<<z[k];
			}
			reverse(z,z+3);
			ans.eb(o+z[0],o+z[1],o+z[2]);
		}
	};
	int n;cin>>n;
	vi a=readvi(n);
	
	auto flip=[&](int x,int y,int z){
		a[x]^=1;
		a[y]^=1;
		a[z]^=1;
		ans.eb(x,y,z);
	};
	
	
	deque<int> idx;
	rep(i,n)idx.pb(i);
	while(idx.size()>8){
		while(idx.size()>8){
			int i=idx[0];
			if(a[i]==0){
				idx.pop_front();
				continue;
			}
			if(a[i+1]==0){
				if(a[i+2]==0){
					flip(i,i+3,i+6);
				}else{
					flip(i,i+2,i+4);
				}
			}else{
				if(a[i+2]==0){
					break;
				}else{
					flip(i,i+1,i+2);
				}
			}
		}
		
		while(idx.size()>8){
			int i=idx.back();
			if(a[i]==0){
				idx.pop_back();
				continue;
			}
			if(a[i-1]==0){
				if(a[i-2]==0){
					flip(i-6,i-3,i);
				}else{
					flip(i-4,i-2,i);
				}
			}else{
				if(a[i-2]==0){
					break;
				}else{
					flip(i-2,i-1,i);
				}
			}
		}
		
		if(idx.size()>8){
			int i=idx.front(),j=idx.back();
			if((i+j)%2==0){
				flip(i,(i+j)/2,j);
				flip(i+1,(i+j)/2,j-1);
			}else{
				flip(i,(i+j-1)/2,j-1);
				flip(i+1,(i+1+j)/2,j);
			}
		}
	}
	
	int cur=0,m=idx.size();
	rep(i,m)cur+=a[idx[i]]<<i;
	brute(cur,m,idx.front());
	
	yes(0);
	cout<<ans.size()<<endl;
	for(auto v:ans){
		int x,y,z;tie(x,y,z)=v;
		cout<<x+1<<" "<<y+1<<" "<<z+1<<"\n";
	}
}