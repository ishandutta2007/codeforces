#include<bits/stdc++.h>
using namespace std;

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

int N;
int A[111111];
int Q;
vpint qs[333];
int ans[111111];
int dp[111111];
signed main(){
	scanf("%d",&N);
	rep(i,N)scanf("%d",&A[i]);
	scanf("%d",&Q);
	rep(i,Q){
		int p,k;
		scanf("%d%d",&p,&k);
		p--;
		if(k<=300){
			qs[k].eb(p,i);
		}
		else{
			while(p<N){
				ans[i]++;
				p+=A[p]+k;
			}
		}
	}

	for(int k=1;k<=300;k++){
		for(int i=N-1;i>=0;i--){
			dp[i]=1;
			if(i+A[i]+k<N)dp[i]+=dp[i+A[i]+k];
		}
		for(auto &q:qs[k]){
			ans[q.se]=dp[q.fi];
		}
	}

	rep(i,Q)printf("%d\n",ans[i]);
	return 0;
}