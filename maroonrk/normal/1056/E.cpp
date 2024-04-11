#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
//#define int ll

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

const int Nmax=1000010;

struct SuffixArray{
	vi sa,as,lcp;
};
namespace SA_IS{
	int bucket[Nmax];
	template <class T>
	void CreateBeginBucket(const T* data, int size, int maxVal){
		REP(i, maxVal + 1) bucket[i] = 0;
		REP(i, size) bucket[(int)data[i]]++;
		int sum = 0;
		REP(i, maxVal + 1){ bucket[i] += sum; swap(bucket[i], sum); }
	}
	 
	template <class T>
	void CreateEndBucket(const T* data, int size, int maxVal){
		REP(i, maxVal + 1) bucket[i] = 0;
		REP(i, size) bucket[(int)data[i]]++;
		int sum = 0;
		REP(i, maxVal + 1){ sum += bucket[i]; bucket[i] = sum; }
	}
	 
	template<class T>
	void InducedSort(const T* data, int size, int* SA, int maxVal, bool* isL){
		CreateBeginBucket(data, size, maxVal);
		REP(i, size) if (SA[i] > 0 && isL[SA[i] - 1]) SA[bucket[(int)data[SA[i] - 1]]++] = SA[i] - 1;
	}
	 
	template<class T>
	void InvertInducedSort(const T* data, int size, int* SA, int maxVal, bool* isL){
		CreateEndBucket(data, size, maxVal);
		for (int i = size - 1; i >= 0; --i) if (SA[i] > 0 && !isL[SA[i] - 1]) SA[--bucket[(int)data[SA[i] - 1]]] = SA[i] - 1;
	}
	 
	template <class T>
	void DBGOUT(const T* sa, int size){
		REP(i, size) printf("%d ", int(sa[i]));
		printf("\n");
	}
	 
	template<class T>
	void SA_IS(const T* data, int size, int* SA, int maxVal, bool* isL){
		REP(i, size) SA[i] = -1;
	#define isLMS(x) (x>0 && isL[x-1] && !isL[x])
		isL[size - 1] = false;
		for (int i = size - 2; i >= 0; i--) isL[i] = data[i] > data[i + 1] || (data[i] == data[i + 1] && isL[i + 1]);
		CreateEndBucket(data, size, maxVal);
		FOR(i, 1, size) if (isLMS(i)) SA[--bucket[(int)data[i]]] = i;
		InducedSort(data, size, SA, maxVal, isL);
		InvertInducedSort(data, size, SA, maxVal, isL);
	 
		int c = 0;
		REP(i, size) if (isLMS(SA[i])) SA[c++] = SA[i];
		FOR(i, c, size) SA[i] = -1;
	 
		int idx = -1;
		int prev = -1;
		REP(i, c){
			bool diff = false;
			REP(d, size){
				if (prev == -1 || data[SA[i] + d] != data[prev + d] || isL[SA[i] + d] != isL[prev + d]){
					diff = true;
					break;
				}
				else if (d > 0 && isLMS(SA[i] + d)) break;
			}
			if (diff){ idx++; prev = SA[i]; }
			SA[c + SA[i] / 2] = idx;
		}
		int j = size;
		for (int i = size - 1; i >= c; i--) if (SA[i] >= 0) SA[--j] = SA[i];
	 
		int* nxdata = SA + size - c;
		int* nxsa = SA;
		if (c == idx + 1) REP(i, c) nxsa[nxdata[i]] = i;
		else SA_IS(nxdata, c, nxsa, idx, isL + size);
	 
		j = c;
		for (int i = size - 1; i >= 1; i--) if (isLMS(i)) nxdata[--j] = i;
		REP(i, c) nxsa[i] = nxdata[nxsa[i]];
		FOR(i, c, size) SA[i] = -1;
		CreateEndBucket(data, size, maxVal);
		for (int i = c - 1; i >= 0; i--) swap(nxsa[i], SA[--bucket[(int)data[nxsa[i]]]]);
		InducedSort(data, size, SA, maxVal, isL);
		InvertInducedSort(data, size, SA, maxVal, isL);
	#undef isLMS
	}
	 
	bool isLPool[Nmax * 2];
	template<class T>
	void SA_IS(const T* data, int size, int* SA){
		int mv = 0;
		REP(i, size) if (mv < data[i]) mv = data[i];
		SA_IS(data, size, SA, mv, isLPool);
	}
	 
	int sa[Nmax],as[Nmax],lcp[Nmax];
	template<class T>
	void CreateLCP(const T* data, int size){
		REP(i,size) as[sa[i]]=i;
		int same=0;
		REP(i,size){
			if(as[i]<size-1){
				int j=sa[as[i]+1];
				while(i+same<size&&j+same<size&&data[i+same]==data[j+same])
					same++;
			}
			lcp[as[i]]=same;
			same=max(same-1,0);
		}
	}
	
	//last element should be 0(as a sentinel)
	//n is the length of the data(including the sentinel)
	//sa[i] index of i'th smallest suffix
	//lcp[i] lcp(sa[i],sa[i+1])
	template<class T>
	SuffixArray BuildSA(const T* data,int n){
		fill(bucket,bucket+n,0);
		fill(isLPool,isLPool+2*n,false);
		fill(sa,sa+n,0);
		fill(as,as+n,0);
		fill(lcp,lcp+n,0);
		SA_IS(data,n,sa);
		CreateLCP(data,n);
		return SuffixArray{vi(sa,sa+n),vi(as,as+n),vi(lcp,lcp+n)};
	}
}

template<class T>
struct SparseTable{
	vector<vector<T>> st;
	inline int TopBit(int t){
		return 31-__builtin_clz(t);
	}
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

char tBuf[Nmax];

signed main(){
	string s=readString();
	
	scanf("%s",tBuf);
	int tlen=strlen(tBuf);
	auto sa=SA_IS::BuildSA(tBuf,tlen+1);
	SparseTable<int> st;
	st.Init(sa.lcp);
	
	const auto Same=[&](int i,int j,int l){
		i=sa.as[i];
		j=sa.as[j];
		if(i>j)swap(i,j);
		return st.GetMin(i,j)>=l;
	};
	
	int n=s.size();
	int c0=0,c1=0;
	for(auto c:s)
		if(c=='0')
			c0++;
		else
			c1++;
	
	int ans=0;
	const auto Check=[&](int l0,int l1){
		int cur=0,p0=-1,p1=-1;
		REP(i,n){
			if(s[i]=='0'){
				if(p0!=-1){
					if(!Same(p0,cur,l0))
						return;
				}
				p0=cur;
				cur+=l0;
			}else{
				if(p1!=-1){
					if(!Same(p1,cur,l1))
						return;
				}
				p1=cur;
				cur+=l1;
			}
		}
		if(l0==l1&&Same(p0,p1,l0))
			return;
		ans++;
	};
	
	for(int a=1;a*n<=tlen;a++){
		int rem=tlen-a*n;
		if(rem%c0==0){
			Check(a+rem/c0,a);
		}
		if(rem&&rem%c1==0){
			Check(a,a+rem/c1);
		}
	}
	print(ans);
}