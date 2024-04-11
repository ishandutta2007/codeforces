#include<cstdio>
int T,n,a,b;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&n);
		n%=3;
		if(n==0)printf("%d\n",a);
		if(n==1)printf("%d\n",b);
		if(n==2)printf("%d\n",a^b);
	}
}