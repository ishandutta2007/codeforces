#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
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
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
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

struct Query{
	int t,v;
};

struct BIT{
	vi buf;
	int s;
	BIT(int n){
		buf.resize(s=n,0);
	}
	void Add(int i,int v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	int Get(int i){
		int res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	int Range(int b,int e){
		b--,e--;
		int res=Get(e);
		if(b>=0)res-=Get(b);
		return res;
	}
	int Kth(int k){
		int res=0;
		for(int i=20;i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
};

signed main(){
	bool dbg=true;
	dbg=false;
	int q=read();
	vector<Query> qs(q);
	vi vs(q);
	REP(i,q){
		if(!dbg){
			string s=readString();
			int v=read();
			int t=s[0]=='+';
			qs[i]=Query{t,v};
		}else{
			qs[i]=Query{1,rand()%1000000000+1};
		}
		vs[i]=qs[i].v;
	}
	sort(ALL(vs));
	vs.erase(unique(ALL(vs)),vs.end());
	BIT bit(vs.size());
	const auto Idx=[&](int v){
		return lower_bound(ALL(vs),v)-vs.begin();
	};
	vi ans(q);
	multiset<signed> s;
	const auto Solve=[&](){
		if(s.empty())
			return int(0);
		int res=s.size()-1;
		int sum=*s.begin();
		while(sum<500000000){
			auto itr=s.upper_bound(sum*2);
			if(itr==s.end())break;
			int x=*itr;
			sum=bit.Get(Idx(x)-1);
			if(sum*2<x){
				res--;
			}
			sum+=x;
		}
		return res;
	};
	REP(i,q){
		if(qs[i].t==1){
			s.insert(qs[i].v);
			bit.Add(Idx(qs[i].v),qs[i].v);
		}else{
			s.erase(s.find(qs[i].v));
			bit.Add(Idx(qs[i].v),-qs[i].v);
		}
		ans[i]=Solve();
	}
	REP(i,q)
		print(ans[i]);
}