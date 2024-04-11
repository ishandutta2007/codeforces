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

int N,K;
int A[222222];

const int INF=1001001001001001001ll;
inline void add(int &a,int b){
	a+=b;
	chmin(a,INF);
}
void solve_naive(){
	for(int k=0;;k++){
		rep(i,N)if(A[i]>=K){
			cout<<k<<endl;
			return;
		}
		for(int i=0;i+1<N;i++)add(A[i+1],A[i]);
	}
}

inline void mul(int &a,int b){
	if(INF/a>=b)a*=b;
	else a=INF;
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int binom(int n,int k){
	
	vint lis(k);
	rep(i,k)lis[i]=n-i;

	for(int j=1;j<=k;j++){
		int d=j;
		rep(i,lis.size()){
			int g=gcd(lis[i],d);
			lis[i]/=g;
			d/=g;
		}
	}

	int ret=1;
	rep(i,lis.size())mul(ret,lis[i]);
	return ret;
}

bool check(int T){
	int val=0;
	for(int i=0;i<10&&i<N;i++){
		int bi=binom(T-1+i,i);
		mul(bi,A[N-1-i]);
		add(val,bi);
	}
	return val>=K;
}

signed main(){
	scanf("%lld%lld",&N,&K);
	rep(i,N)scanf("%lld",&A[i]);

	int minidx=N;
	rep(i,N)if(A[i])chmin(minidx,i);
	if(N-1-minidx>=10){
		solve_naive();
		return 0;
	}


	rep(i,N)if(A[i]>=K){
		cout<<0<<endl;
		return 0;
	}
	int lb=0,ub=1000000000000000000ll;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(check(mid))ub=mid;
		else lb=mid;
	}
	cout<<ub<<endl;
    return 0;
}