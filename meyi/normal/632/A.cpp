#pragma GCC optimize(3)
#include<cstdio>
long long n,m,s,t;
char a[50][10];
main(){
	scanf("%lld%lld",&n,&m);
	for(register int i=0;i<n;++i)scanf("%s",a+i);
	while(n--){
		t<<=1;
		if(a[n][4]=='p')++t;
		s+=t;
	}
	printf("%lld",m*s>>1);
}