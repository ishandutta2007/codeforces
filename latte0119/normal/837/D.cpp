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

const int INF=1001001001001001001ll;
/*
5^25<1e18
*/
int N,K;

int dp[222][222*25];

signed main(){
	cin>>N>>K;

	fill_n(*dp,222*222*25,-INF);
	dp[0][0]=0;
	rep(i,N){
		int a;cin>>a;
		int cnt2=0,cnt5=0;
		while(a%2==0){
			cnt2++;
			a/=2;
		}

		while(a%5==0){
			cnt5++;
			a/=5;
		}
	
		for(int j=N;j>=0;j--){
			rep(k,N*25){
			chmax(dp[j+1][k+cnt5],dp[j][k]+cnt2);
			}
		}
	}

	int ans=0;
	rep(k,N*25+1)chmax(ans,min(k,dp[K][k]));
	cout<<ans<<endl;
    return 0;
}