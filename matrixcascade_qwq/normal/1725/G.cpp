#include<cstdio>
#define int long long
inline int Get(int x){
	int ss=0;
	if(x%2==0) ss+=x/2-1;
	else ss+=x/2;
	ss+=x/4-(x>=4);
	return ss;
}
int n,ll,rr;
signed main(){
	scanf("%lld",&n);
	ll=1,rr=2e9+5;
	while(ll<rr){
		int mid=ll+rr>>1;
		if(Get(mid)>=n) rr=mid;
		else ll=mid+1;
	}
	printf("%lld\n",ll);
	return 0;
}