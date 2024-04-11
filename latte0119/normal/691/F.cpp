#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

inline int topbit(unsigned long long x){
	return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
	return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
	return __builtin_parity(x);
}

const int MAXV=3000000;

int N,Q;
int A[1111111];

int cnt[MAXV+1];

int ans[MAXV+1];

signed main(){
	scanf("%lld",&N);
	rep(i,N)scanf("%lld",&A[i]);
	rep(i,N)cnt[A[i]]++;

	for(int i=1;i<=MAXV;i++){
		for(int j=1;i*j<=MAXV;j++){
			ans[i*j]+=cnt[i]*cnt[j];
		}
	}

	rep(i,N)if(A[i]*A[i]<=MAXV)ans[A[i]*A[i]]--;

	rep(i,MAXV)ans[i+1]+=ans[i];

	scanf("%lld",&Q);
	rep(i,Q){
		int p;scanf("%lld",&p);
		int tmp=N*(N-1)-ans[p-1];
		printf("%lld\n",tmp);
	}
	return 0;
}