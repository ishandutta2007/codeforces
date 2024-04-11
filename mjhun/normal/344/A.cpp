#include <cstdio>

int main(){
	int n,a=-1,b,r=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&b);
		r+=b!=a;
		a=b;
	}
	printf("%d\n",r);
	return 0;
}