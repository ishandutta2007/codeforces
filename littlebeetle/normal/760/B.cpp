#include<cstdio>
typedef long long ll;
ll n,m,k,l,r,mid;
ll sum(ll p,ll x){
	if(p>=x)return (1+x)*x/2+p-x;
	return (x-p+1+x)*p/2;
}
bool check(ll x){
	return x+sum(k-1,x-1)+sum(n-k,x-1)<=m;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	l=0;r=m;
	while(l<r){
		mid=l+r+1>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%lld",l);
	return 0;
}