#include<cstdio>
long long a,b,c,d,e,f;
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
	if((c-a)*(c-a)+(d-b)*(d-b)==(e-c)*(e-c)+(f-d)*(f-d)&&(d-b)*(e-c)!=(f-d)*(c-a))
		printf("Yes");
	else
		printf("No");
}