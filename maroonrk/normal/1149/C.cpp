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

struct Node{
	int mx,mn,a,b,c,lz;
	Node(){
		mx=mn=a=b=c=lz=0;
	}
	void CleanLazy(){
		mx+=lz;
		mn+=lz;
		a-=lz;
		c-=lz;
		lz=0;
	}
	Node(Node x,Node y){
		x.CleanLazy();
		y.CleanLazy();
		mx=max(x.mx,y.mx);
		mn=min(x.mn,y.mn);
		a=max({x.a,y.a,x.mx-y.mn*2});
		b=max({x.b,y.b,x.a+y.mx,x.mx+y.c});
		c=max({x.c,y.c,-x.mn*2+y.mx});
		lz=0;
	}
	void AddLazy(int v){
		lz+=v;
	}
	void Prop(Node&x,Node&y){
		x.AddLazy(lz);
		y.AddLazy(lz);
		CleanLazy();
	}
	int Get(){
		return b;
	}
};

struct SegmentTree{
	V<Node> buf;
	int s;
	SegmentTree(int n){
		s=1;
		while(s<n)s*=2;
		buf.resize(s*2);
	}
	int Get(){
		return buf[1].Get();
	}
	void Update(int b,int e,int l,int r,int i,int v){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e){
			buf[i].AddLazy(v);
			return;
		}
		buf[i].Prop(buf[i*2],buf[i*2+1]);
		Update(b,e,l,(l+r)/2,i*2,v);
		Update(b,e,(l+r)/2,r,i*2+1,v);
		buf[i]=Node(buf[i*2],buf[i*2+1]);
	}
	void Update(int b,int e,int v){
		Update(b,e,0,s,1,v);
	}
	void dfs(int i){
		if(i<s){
			buf[i].Prop(buf[i*2],buf[i*2+1]);
			dfs(i*2);
			dfs(i*2+1);
		}
		cerr<<i<<" "<<buf[i].Get()<<endl;
	}
};

signed main(){
	int n=(read()-1)*2,q=read();
	string s=readString();
	SegmentTree seg(n+1);
	rep(i,n){
		if(s[i]=='(')
			seg.Update(i+1,n+2,1);
		else
			seg.Update(i+1,n+2,-1);
	}
	print(seg.Get());
	rep(_,q){
		int a=read()-1,b=read()-1;
		if(s[a]!=s[b]){
			swap(s[a],s[b]);
			for(auto i:{a,b})
				if(s[i]=='(')
					seg.Update(i+1,n+2,2);
				else
					seg.Update(i+1,n+2,-2);
		}
		print(seg.Get());
		//seg.dfs(1);
	}
}