#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define int ll
typedef unsigned long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
inline ll calc(ll l,ll r){
	return (l+r)*(r-l+1)>>1;
}
int n;
ll x;
inline bool check(int k){
	if(k<=n)return calc(1ull,k)<x;
	else return calc(1ull,n)+calc(max(n-(k-n),1ull),n-1)<x;
}
inline int half(){
	int l=1,r=2*n-1,ret=0;
	while(l<=r){
		ri mid=l+r>>1;
		if(check(mid-1))ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int t_case;
signed main(){
	scanf("%llu",&t_case);
	while(t_case--){
		scanf("%llu%llu",&n,&x);
		printf("%llu\n",half());
	}
	return 0;
}