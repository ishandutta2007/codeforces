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

int N;
D P[22][22];

D dp[1<<18][18];

signed main(){
	cout<<setprecision(20);

	cin>>N;
	rep(i,N)rep(j,N)cin>>P[i][j];


	dp[(1<<N)-1][0]=1;
	for(int i=(1<<N)-2;i>0;i--){
		rep(j,N){
			if(!(i>>j&1))continue;
			rep(k,N){
				if(i>>k&1)continue;
				chmax(dp[i][j],dp[i|(1<<k)][k]*P[k][j]+dp[i|(1<<k)][j]*P[j][k]);
			}
		}
	}

	D ans=0;
	rep(i,N)chmax(ans,dp[1<<i][i]);
	cout<<ans<<endl;
	return 0;
}