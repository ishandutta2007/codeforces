#include<cstdio>
const int N=1000002;
long long n,a[N],l,r,mid,s,i;
bool check(long long x){
	s=0;
	for(i=1;i<=n;i++)
		s+=x-a[i];
	return s>=x;
}
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(a[i]>l)
			l=a[i];
	}
	r=1ll<<40;
	while(l<r){
		mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%lld",r);
	//while(1);
	return 0;
}