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

using D=double;

int N,T;
int a[222222],t[222222];

D calc(D z){
	D ret=0;
	rep(i,N)ret+=a[i]*max(D(0),1-z*(t[i]-T));
	return ret;
}

signed main(){
	scanf("%lld%lld",&N,&T);
	rep(i,N)scanf("%lld",&a[i]);
	rep(i,N)scanf("%lld",&t[i]);

	D lb=-1,ub=1;
	rep(i,50){
		D m1=(lb*2+ub)/3;
		D m2=(lb+ub*2)/3;

		if(calc(m1)<calc(m2))ub=m2;
		else lb=m1;
	}

	cout<<setprecision(20);
	cout<<calc(lb)<<endl;
	return 0;
}