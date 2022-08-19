#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) FOR(i,0,b)
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

struct UnionFind{
	vi rank,par;
	UnionFind(int n){
		rank.assign(n,0);
		par.assign(n,-1);
	}
	int Find(int i){
		return par[i]==-1?i:(par[i]=Find(par[i]));
	}
	bool Same(int a,int b){
		return Find(a)==Find(b);
	}
	bool Unite(int a,int b){
		a=Find(a);
		b=Find(b);
		if(a==b)
			return false;
		if(rank[a]<rank[b])
			swap(a,b);
		par[b]=a;
		if(rank[a]==rank[b])
			rank[a]++;
		return true;
	}
};

signed main(){
	int n=read(),m=read(),a=read(),b=read();
	VV<pi> g(n);
	UnionFind uf(n);
	rep(_,m){
		int u=read()-1,v=read()-1,c=read();
		g[u].eb(v,c);
		g[v].eb(u,c);
		if(c==a)
			uf.Unite(u,v);
	}
	rep(i,n){
		V<pi> tmp;
		for(auto e:g[i]){
			if(e.second==b&&uf.Same(i,e.first))
				continue;
			tmp.pb(e);
		}
		g[i]=tmp;
	}
	int s=0;
	vi num(n,-1);
	{
		map<int,int> idx;
		rep(i,n)
			idx[uf.Find(i)]++;
		for(auto&kv:idx)
			if(kv.second>=4)
				kv.second=s++;
			else
				kv.second=-1;
		rep(i,n)
			num[i]=idx[uf.Find(i)];
	}
	vi dist(n*(1<<s),inf);
	vi ans(n,inf);
	priority_queue<pi,V<pi>,greater<pi>> pq;
	const auto Reach=[&](int v,int mask,int d){
		chmin(ans[v],d);
		int w=(v<<s)+mask;
		if(dist[w]>d){
			dist[w]=d;
			pq.push(pi(d,w));
		}
	};
	Reach(0,num[0]==-1?0:1<<num[0],0);
	while(!pq.empty()){
		auto t=pq.top();pq.pop();
		int d=t.first;
		int v=t.second>>s,mask=t.second&((1<<s)-1);
		for(auto e:g[v]){
			int ms=mask;
			int to=e.first;
			if(e.second==b){
				if(num[to]!=-1){
					if(mask&(1<<num[to]))
						continue;
					ms|=1<<num[to];
				}
			}
			Reach(to,ms,d+e.second);
		}
	}
	print(ans);
}