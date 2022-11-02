#include<cstdio>
const int M=998244353*2;
int i,n;
long long a,f;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a),
		f=(f*2+a*(n-i+2))%M;
	printf("%lld",f/2);
}