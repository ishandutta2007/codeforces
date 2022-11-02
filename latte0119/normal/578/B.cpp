#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,K,X;
int A[222222];


int L[222222];
int R[222222];

signed main(){
	scanf("%lld%lld%lld",&N,&K,&X);
	rep(i,N)scanf("%lld",&A[i]);
	for(int i=1;i<N;i++){
		L[i]=L[i-1]|A[i-1];
	}
	for(int i=N-2;i>=0;i--){
		R[i]=R[i+1]|A[i+1];
	}

	int ans=0;
	rep(i,N){
		int tmp=A[i];
		rep(j,K)tmp*=X;
		tmp|=L[i];
		tmp|=R[i];
		chmax(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}