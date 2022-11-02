#include<cstdio>
typedef long long ll;
ll a,l,r,k=1000000000000000000ll;
int main(){
	scanf("%lld",&a);
	l=a-k%a*9%a*9%a;
	printf("%lld %lld",l,l+k-1);
}