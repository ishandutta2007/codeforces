#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int mod=1e9+7;

int pw(int x,int y,int ret=1) {
	rep(i,1,y) ret=(ret*x)%mod;
	return ret; 
}

signed main() {
	int n,m; scanf("%lld%lld",&n,&m);
	printf("%lld\n",pw(2,m)*pw(n+1,m-1)%mod*(n+1-m)%mod);
	return 0;
}