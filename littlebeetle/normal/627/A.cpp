#include<cstdio>
typedef long long ll;
ll s,x,y,z,ans=1,p;
int main(){
	scanf("%lld%lld",&s,&x);
	y=s-x;
	if(y==0)
		p=-2;
	if(y%2==1){
		printf("0");
		return 0;
	}
	while(y){
		z=y&-y;
		if((z>>1)&x){
			printf("0");
			return 0;
		}
		y-=z;
	}
	while(x)
		x-=x&-x,ans<<=1;
	printf("%lld",ans+p);
}