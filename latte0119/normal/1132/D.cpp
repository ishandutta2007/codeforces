#include<bits/stdc++.h>
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

const int INF=1001001001001001ll;
int N,K;
int A[222222],B[222222];


bool check(int x){
	vint a(N);
	rep(i,N)a[i]=A[i];


	priority_queue<pint,vector<pint>,greater<pint>>que;
	rep(i,N){
		if(a[i]<K*B[i])que.push(pint(a[i]/B[i],i));
	}

	for(int t=0;t<K;t++){				
		if(que.empty())break;
		int i=que.top().se;
		que.pop();
		if(a[i]<t*B[i])return false;
		a[i]+=x;
		if(a[i]<K*B[i])que.push(pint(a[i]/B[i],i));	
		
	}

	rep(i,N)if(a[i]<B[i]*K)return false;	
	return true;
}

signed main(){
	scanf("%lld%lld",&N,&K);K--;
	rep(i,N)scanf("%lld",&A[i]);
	rep(i,N)scanf("%lld",&B[i]);


	int lb=-1,ub=INF;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(check(mid))ub=mid;
		else lb=mid;
	}

	if(ub==INF)cout<<-1<<endl;
	else cout<<ub<<endl;
}