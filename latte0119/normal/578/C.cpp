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

using D=double;

int N;
int A[222222];

double S[222222];
D calc(D x){
	for(int i=0;i<N;i++){
		S[i+1]=S[i]+A[i]-x;
	}

	double ans=0.0;
	double ma=0,mi=0;
	for(int i=1;i<=N;i++){
		if(ma>S[i])chmax(ans,ma-S[i]);
		if(mi<S[i])chmax(ans,S[i]-mi);

		chmax(ma,S[i]);
		chmin(mi,S[i]);
	}

	return ans;
}

signed main(){
	scanf("%lld",&N);
	rep(i,N)scanf("%lld",&A[i]);

	D lb=50000;
	D rb=-50000;

	rep(i,100){
		D ll=(lb*2+rb)/3;
		D rr=(lb+rb*2)/3;

		D fl=calc(ll);
		D fr=calc(rr);
		if(fl<fr)rb=rr;
		else lb=ll;
	}
	printf("%.20f\n",calc(lb));
	return 0;
}