#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

using uint=unsigned int;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int Nmax=5019;

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
	
	//0 must be added to the end as a sentinel
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
struct SparceTable{
	T st[21][Nmax];
	void Init(int n,T data[]){
		if(n<=0)
			return;
		int h = 1;
		while ((1 << h) < n) h++;
		REP(i, n) st[0][i] = data[i];
		FOR(j, 1, h + 1)
			REP(i, n - (1<<j) + 1)
				st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
	}
	inline int TopBit(int t){
		return 31-__builtin_clz(t);
	}
	T GetMin(int b, int e){
		int diff = TopBit(e-b);
		return min(st[diff][b], st[diff][e - (1 << diff)]);
	}
};
SparceTable<int> st;

const int mod=1000000007;
void Add(int& a,int b){
	a+=b;
	if(a>=mod)a-=mod;
}

char str[Nmax];
int dp[Nmax][Nmax];
int main(){
	int n=read();
	scanf("%s",str);
	SuffixArray sa=SA_IS::BuildSA(str,n+1);
	st.Init(n,&sa.lcp[0]);
	REP(i,n)
		dp[i][0]=1;
	FOR(i,1,n){
		REP(j,i)if(str[j+1]!='0'){
			int s=i-j,p=0;
			if(j+1>=s){
				int a=j+1-s,b=i+1-s;
				int x=sa.as[a],y=sa.as[b];
				if(x>y)swap(x,y);
				int k=st.GetMin(x,y);
				if(k<s&&str[a+k]<str[b+k])
					p=a;
				else
					p=a+1;
			}
			Add(dp[i][j+1],dp[j][p]);
		}
		for(int j=i-1;j>=0;j--)
			Add(dp[i][j],dp[i][j+1]);
	}
	cout<<dp[n-1][0]<<endl;
}