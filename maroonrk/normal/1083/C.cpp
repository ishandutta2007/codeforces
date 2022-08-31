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

template<class T>
void print(const vector<T>&v){
	REP(i,v.size())
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
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	return v;
}
template<class T>
void MakeUniqued(vector<T>&v){
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
}

int TopBit(signed t){
	return 31-__builtin_clz(t);
}
int TopBit(ll t){
	return 63-__builtin_clzll(t);
}
int PopCount(signed t){
	return __builtin_popcount(t);
}
int PopCount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(int(1)<<TopBit(i))==i;
}

//require BitOp
template<class T>
struct SparseTable{
	vector<vector<T>> st;
	void Init(const vector<T>& data){
		if(data.empty())
			return;
		int n=data.size(),h=TopBit(n);
		st.resize(h+1);
		st[0]=data;
		FOR(j, 1, h + 1){
			st[j].resize(n-(1<<j)+1);
			REP(i,n-(1<<j)+1)
				st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
	T GetMin(int b, int e){
		int diff = TopBit(e-b);
		return min(st[diff][b], st[diff][e - (1 << diff)]);
	}
};

//Euler Tour + O(1) LCA
//requires SparseTable
const int Nmax=200010;
vi tr[Nmax];
int dep[Nmax],ein[Nmax],eout[Nmax];
vector<pi> dep_idx;
void dfs1(int v,int p,int d){
	dep[v]=d;
	ein[v]=dep_idx.size();
	dep_idx.EB(d,v);
	for(auto to:tr[v])if(to!=p){
		dfs1(to,v,d+1);
		dep_idx.EB(d,v);
	}
	eout[v]=dep_idx.size();
}
SparseTable<pi> st_lca;
void InitTable(){
	st_lca.Init(dep_idx);
}
int LCA(int a,int b){
	int l=min(ein[a],ein[b]);
	int r=max(eout[a],eout[b]);
	pi w=st_lca.GetMin(l,r);
	return w.second;
}
bool Ascend(int v,int p){
	return ein[p]<=ein[v]&&eout[v]<=eout[p];
}

bool cmp(int a,int b){
	return ein[b]<ein[a]&&eout[a]<eout[b];
}
struct Node{
	int t,a,b,c;
	Node(int tt=-1,int aa=-1,int bb=-1,int cc=-1):t(tt),a(aa),b(bb),c(cc){
		if(tt!=-1&&tt!=-2){
			if(ein[a]>ein[b])
				swap(a,b);
		}
	}
};
Node NewNode(int v){
	return Node(1,v,v);
}
Node Merge(Node x,Node y){
	if(x.t==-2)return y;
	if(y.t==-2)return x;
	if(x.t==-1||y.t==-1)
		return Node(-1);
	if(x.t>y.t)swap(x,y);
	if(y.t==1){
		bool path=true;
		int idx[4]{x.a,x.b,y.a,y.b};
		sort(idx,idx+4,cmp);
		REP(i,3)
			if(!Ascend(idx[i],idx[i+1]))
				path=false;
		if(path){
			return Node(1,idx[0],idx[3]);
		}
		int lca=LCA(x.b,y.b);
		if(!Ascend(x.a,lca))return Node(-1);
		if(!Ascend(y.a,lca))return Node(-1);
		return Node{2,x.b,y.b,lca};
	}else{
		if(x.t==1){
			if(!Ascend(x.a,y.c))return Node(-1);
			REP(_,2){
				int idx[3]{x.a,x.b,y.a};
				sort(idx,idx+3,cmp);
				bool path=true;
				REP(i,2)
					if(!Ascend(idx[i],idx[i+1]))
						path=false;
				if(path)
					return Node(2,idx[0],y.b,y.c);
				swap(y.a,y.b);
			}
			return Node(-1);
		}else{
			if(x.c!=y.c)return Node(-1);
			REP(_,2){
				int a=-1,b=-1;
				if(Ascend(x.a,y.a))
					a=x.a;
				else if(Ascend(y.a,x.a))
					a=y.a;
				if(Ascend(x.b,y.b))
					b=x.b;
				else if(Ascend(y.b,x.b))
					b=y.b;
				if(a!=-1&&b!=-1){
					return Node(2,a,b,x.c);
				}
				swap(y.a,y.b);
			}
			return Node(-1);
		}
	}
}

struct SegTree{
	int s;
	vector<Node> buf;
	SegTree(vi data){
		int n=data.size();
		s=1;
		while(s<n)s*=2;
		cerr<<endl;
		buf.resize(s*2,Node(-1));
		cerr<<endl;
		REP(i,n)
			buf[s+i]=NewNode(data[i]);
		cerr<<endl;
		for(int i=s-1;i>=1;i--)
			Update(i);
		cerr<<endl;
	}
	void Update(int i){
		buf[i]=Merge(buf[i*2],buf[i*2+1]);
	}
	void Set(int i,int v){
		i+=s;
		buf[i]=NewNode(v);
		while(i>>=1)
			Update(i);
	}
	int Find(Node&cur,int l,int r,int i){
		Node nx=Merge(cur,buf[i]);
		if(nx.t!=-1){
			cur=nx;
			return r;
		}
		if(i>=s)
			return l;
		int mid=(l+r)/2;
		int res=Find(cur,l,mid,i*2);
		if(res<mid)return res;
		return Find(cur,mid,r,i*2+1);
	}
	int Find(){
		Node cur(-2);
		return Find(cur,0,s,1);
	}
};

signed main(){
	int n=read();
	vi p(n);
	REP(i,n)
		p[i]=read();
	vi q(n);
	REP(i,n)
		q[p[i]]=i;
	
	FOR(i,1,n){
		int d=read()-1;
		tr[i].PB(d);
		tr[d].PB(i);
	}
	dfs1(0,-1,0);
	InitTable();
	
	cerr<<endl;
	
	SegTree seg(q);
	
	cerr<<endl;
	
	int num=read();
	REP(_,num){
		int t=read();
		if(t==1){
			int a=read()-1,b=read()-1;
			seg.Set(p[a],b);
			seg.Set(p[b],a);
			swap(p[a],p[b]);
		}else{
			int ans=seg.Find();
			print(ans);
		}
	}
}