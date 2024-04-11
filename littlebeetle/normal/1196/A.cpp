#include<cstdio>
const int N=100002;
int T;
long long a,b,c;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		printf("%I64d\n",(a+b+c)/2);
	}
}