#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
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
	scanf("%"  SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

template<class T>
void print(const vector<T>&v){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?1:2);
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

struct SegTree{
	int s;
	vi lz;
	SegTree(int n){
		s=1;
		while(s<n)s*=2;
		lz.resize(s*2,-1);
	}
	void Prop(int i){
		if(lz[i]!=-1){
			if(lz[i]<=1){
				lz[i*2]=lz[i*2+1]=lz[i];
			}else{
				rep(k,2)
					lz[i*2+k]=1-lz[i*2+k];
			}
		}
		lz[i]=-1;
	}
	void Set(int b,int e,int v,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			lz[i]=v;
			return;
		}
		Prop(i);
		int m=(l+r)/2;
		Set(b,e,v,l,m,i*2);
		Set(b,e,v,m,r,i*2+1);
	}
	void Set(int b,int e,int v){
		if(b<e)Set(b,e,v,0,s,1);
	}
	void Flip(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			lz[i]=1-lz[i];
			return;
		}
		Prop(i);
		int m=(l+r)/2;
		Flip(b,e,l,m,i*2);
		Flip(b,e,m,r,i*2+1);
	}
	void Flip(int b,int e){
		if(b<e)Flip(b,e,0,s,1);
	}
	void dfs(int i,int d,vi&dst){
		if(i<s){
			Prop(i);
			rep(k,2)
				dfs(i*2+k,d,dst);
		}else{
			if(lz[i]!=-1){
				if(lz[i]<=1)
					d=lz[i];
				else
					d=1-d;
			}
			dst.pb(d);
		}
	}
	vi Get(int d){
		vi res;
		dfs(1,d,res);
		return res;
	}
};

signed main(){
	int n=read(),q=read();
	vi a(n);
	rep(i,n)a[i]=read();
	const int S=100010;
	SegTree seg(S);
	rep(i,q){
		string s=readString();
		int x=read();
		if(s[0]=='<'){
			if(x>0){
				seg.Flip(0,x);
				x=-(x-1);
			}
			x=-x+1;
			seg.Set(x,S,1);
		}else{
			if(x<0){
				x=-x;
				seg.Flip(0,x);
				x--;
			}
			x++;
			seg.Set(x,S,0);
		}
	}
	vi x=seg.Get(0),y=seg.Get(1);
	vi res;
	for(auto v:a){
		int sgn;
		if(v<0){
			sgn=x[-v];
		}else{
			sgn=y[v];
		}
		if(sgn==0)
			res.pb(-abs(v));
		else
			res.pb(abs(v));
	}
	print(res);
}