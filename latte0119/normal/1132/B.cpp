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

signed main(){
	int N;scanf("%lld",&N);
	vint A(N);rep(i,N)scanf("%lld",&A[i]);
	sort(all(A));

	reverse(all(A));

	int acc=accumulate(all(A),0ll);
	int Q;scanf("%lld",&Q);
	while(Q--){
		int q;scanf("%lld",&q);
		printf("%lld\n",acc-A[q-1]);
	}
	return 0;
}