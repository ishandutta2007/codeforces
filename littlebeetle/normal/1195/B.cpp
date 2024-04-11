#include<cstdio>
long long n,k,l,r,mid;
int main(){
	scanf("%I64d%I64d",&n,&k);
	l=0;r=n;
	while(l<r){
		mid=(l+r)/2;
		if((1+mid)*mid/2-(n-mid)>=k)
			r=mid;
		else
			l=mid+1;
	}
	printf("%I64d",n-r);
}