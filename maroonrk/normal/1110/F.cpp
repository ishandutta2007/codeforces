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

const int Nmax=500010;
struct Edge{
	int to,len;
	bool operator<(const Edge&rhs)const{
		return to<rhs.to;
	}
};
ostream& operator<<(ostream&os,Edge e){
	return os<<"To:"<<e.to<<", Len:"<<e.len;
}
vector<Edge> tr[Nmax];
int lfMin[Nmax],lfMax[Nmax];
void dfs1(int v,int l,vi&idx,vi&len){
	if(tr[v].empty()){
		lfMin[v]=lfMax[v]=idx.size();
		idx.PB(v);
		len.PB(l);
	}else{
		sort(ALL(tr[v]));
		for(auto e:tr[v]){
			dfs1(e.to,l+e.len,idx,len);
		}
		lfMin[v]=lfMin[tr[v].front().to];
		lfMax[v]=lfMax[tr[v].back().to];
	}
}

//Range Add/Get Min
struct SegTree{
	vi mn,lazy;
	int s;
	void Init(vi data){
		int n=data.size();
		s=1;
		while(s<n)s*=2;
		mn.resize(s*2,0);
		REP(i,n)
			mn[i+s]=data[i];
		for(int i=s-1;i>=1;i--)
			mn[i]=min(mn[i*2],mn[i*2+1]);
		lazy.resize(s*2,0);
	}
	void Propagate(int i){
		mn[i]+=lazy[i];
		lazy[i*2]+=lazy[i];
		lazy[i*2+1]+=lazy[i];
		lazy[i]=0;
	}
	int GetNodeMin(int i){
		return mn[i]+lazy[i];
	}
	void Update(int i){
		assert(lazy[i]==0);
		mn[i]=min(GetNodeMin(i*2),GetNodeMin(i*2+1));
	}
	void Add(int b,int e,int v,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e)return void(lazy[i]+=v);
		Propagate(i);
		Add(b,e,v,l,(l+r)/2,i*2);
		Add(b,e,v,(l+r)/2,r,i*2+1);
		Update(i);
	}
	void Add(int b,int e,int v){
		if(b<e&&v)
			Add(b,e,v,0,s,1);
	}
	int Get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return inf;
		if(b<=l&&r<=e)return GetNodeMin(i);
		Propagate(i);
		return min(
			Get(b,e,l,(l+r)/2,i*2),
			Get(b,e,(l+r)/2,r,i*2+1)
		);
	}
	int Get(int b,int e){
		return Get(b,e,0,s,1);
	}
};

struct Query{
	int l,r,i;
};
vector<Query> qs[Nmax];
int leafS,ans[Nmax];
int off=0;
void dfs2(int v,SegTree&seg){
	for(auto q:qs[v]){
		cerr<<v<<" "<<q.i<<" "<<q.l<<" "<<q.r<<" "<<seg.Get(q.l,q.r)<<endl;
		ans[q.i]=seg.Get(q.l,q.r)+off;
	}
	for(auto e:tr[v]){
		int bg=lfMin[e.to],ed=lfMax[e.to]+1;
		off+=e.len;
		seg.Add(bg,ed,-e.len*2);
		dfs2(e.to,seg);
		off-=e.len;
		seg.Add(bg,ed,e.len*2);
	}
}

signed main(){
	bool dbg=false;
	int n=read(),q=read();
	if(n==-1){
		dbg=true;
		n=500000;
	}
	FOR(i,1,n){
		int p,w;
		if(!dbg){
			p=read()-1,w=read();
		}else{
			p=i/2;
			w=rand()%1000000000+1;
		}
		tr[p].PB(Edge{i,w});
	}
	vi idx,len;
	dfs1(0,0,idx,len);
	cerr<<idx<<endl;
	cerr<<len<<endl;
	leafS=idx.size();
	REP(i,q){
		int v,l,r;
		if(!dbg){
			v=read()-1,l=read()-1,r=read()-1;
		}else{
			v=rand()%n;
			l=idx[rand()%idx.size()];
			r=idx[rand()%idx.size()];
			if(l>r)swap(l,r);
		}
		l=lower_bound(ALL(idx),l)-idx.begin();
		r=upper_bound(ALL(idx),r)-idx.begin();
		qs[v].PB(Query{l,r,i});
	}
	SegTree seg;
	seg.Init(len);
	dfs2(0,seg);
	REP(i,q)
		print(ans[i]);
}