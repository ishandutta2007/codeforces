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

int N,R,K;
int A[555555];
int B[555555];

bool check(int x){
	int cost=0;
	deque<pint>deq;
	int sum=0;
	rep(i,N){
		if(deq.size()&&deq.front().fi+R<i){
			sum-=deq.front().se;
			deq.pop_front();
		}

		if(B[i]+sum<x){
			int pos=min(N-1,i+R);
			int num=x-B[i]-sum;
			deq.eb(pos,num);
			cost+=num;
			sum+=num;
			

			if(cost>K)return false;
		}
	}
	return true;
}

signed main(){
	scanf("%lld%lld%lld",&N,&R,&K);
	rep(i,N)scanf("%lld",&A[i]);
	rep(i,N){
		B[max(0ll,i-R)]+=A[i];
		B[min(N,i+R+1)]-=A[i];
	}
	rep(i,N)B[i+1]+=B[i];

	int lb=0,ub=1001001001001001001ll;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(check(mid))lb=mid;
		else ub=mid;
	}
	cout<<lb<<endl;
	return 0;
}