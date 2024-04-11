#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

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

const int INF=numeric_limits<int>::max()/10;

signed main(){
	int N;cin>>N;
	vint A(N);rep(i,N)cin>>A[i];

	vint dp(2,-INF);
	dp[0]=0;
	rep(i,N){
		vint nex(2,-INF);
		int c;
		if(A[i]%2==0)c=0;
		else c=1;

		rep(j,2){
			nex[j]=dp[j];
			chmax(nex[j],dp[j^c]+A[i]);
		}
		dp=nex;
	}
	cout<<dp[1]<<endl;
	return 0;
}