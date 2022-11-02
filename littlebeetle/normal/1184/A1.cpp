#include<cstdio>
typedef long long ll;
ll r,x,y;
int main(){
	scanf("%lld",&r);
	for(x=1;x*x<=r;x++){
		y=(r-x*x-x-1)/(2*x);
		if(y>0&&x*x+2*x*y+x+1==r){
			printf("%lld %lld",x,y);
			return 0;
		}
	}
	printf("NO");
}