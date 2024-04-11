#include<cstdio>
int n,x,a,b;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(x&1)
			a++;
		else
			b++;
	}
	printf("%d\n",a<b?a:b);
}