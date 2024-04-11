#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) ROF(i,0,b)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
auto& errStream=cerr;
#ifdef LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))
#define fs first
#define sc second

template<class T> using V=vector<T>;
template<class T> using VV=V<V<T>>;

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	rep(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
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
	os<<"(";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<")";
}

ll read(){
	ll i;
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
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

constexpr ll TEN(int n){
	return n==0?1:TEN(n-1)*10;
}

template<class T>
vector<T> Uniqued(const vector<T>&vv){
	auto v(vv);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	return v;
}
template<class T>
void MakeUniqued(vector<T>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.end());
}

struct QuickFind{
	vi g;
	VV<int> mem;
	QuickFind(int n):g(n),mem(n){
		iota(all(g),0);
		rep(i,n)
			mem[i].pb(i);
	}
	int find(int i){
		return g[i];
	}
	void unite(int a,int b){
		a=g[a],b=g[b];
		if(a==b)return;
		if(mem[a].size()<mem[b].size())
			swap(a,b);
		for(auto v:mem[b]){
			g[v]=a;
			mem[a].pb(v);
		}
	}
};

vi ask(vi x){
	if(x.empty())return {};
	assert(x.size()%2==0);
	for(auto&v:x)v++;
	cout<<"Q "<<x.size()/2<<" ";
	print(x);
	cout.flush();
	string s=readString();
	vi res;
	for(auto c:s)
		res.pb(c-'0');
	return res;
}

void answer(vi x){
	vi y[3];
	rep(i,x.size())
		y[x[i]].pb(i+1);
	cout<<"A";
	rep(k,3)
		cout<<" "<<y[k].size();
	cout<<endl;
	rep(k,3)
		print(y[k]);
	cout.flush();
}

void Solve(){
	int n=read();
	QuickFind qf(n);
	rep(k,2){
		vi idx;
		for(int i=k;i+1<n;i+=2){
			idx.pb(i);
			idx.pb(i+1);
		}
		vi res=ask(idx);
		rep(i,res.size())if(res[i])
			qf.unite(i*2+k,i*2+1+k);
	}
	vi idx;
	rep(i,n)if(qf.find(i)==i)
		idx.pb(i);
	int s=idx.size();
	vi w(s,0);
	rep(k,2){
		vi z,p;
		rep(i,s){
			if(i%4/2==k){
				if(i>=2){
					z.pb(idx[i-2]);
					z.pb(idx[i]);
					p.pb(i-2);
					p.pb(i);
				}
			}
		}
		vi res=ask(z);
		rep(i,res.size())if(res[i])
			w[p[i*2+1]]=1;
	}
	vi as(s);
	rep(i,s){
		if(i<2)
			as[i]=i;
		else{
			if(w[i])
				as[i]=as[i-2];
			else
				as[i]=3-as[i-2]-as[i-1];
		}
	}
	vi res(n);
	rep(i,s)
		for(auto j:qf.mem[idx[i]])
			res[j]=as[i];
	answer(res);
}

signed main(){
	int t=read();
	rep(_,t)
		Solve();
}