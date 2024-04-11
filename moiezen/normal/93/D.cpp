#include <cstdio>
#define mo 1000000007
long long pow(int x,int y){
	if(!y) return 1;
	long long temp=pow(x,y>>1);
	(temp*=temp)%=mo;
	if(y&1) (temp*=x)%=mo;
	return temp;
}
long long g(int x){
	if(!x) return 0;
	if(x&1) return (11*pow(3,x/2)-7+mo)%mo;
	return (19*pow(3,x/2-1)-7+mo)%mo;
}
long long f(int x){
	return (g(x)+g((x+1)/2))*(mo+1)/2%mo;
}
int main(){
	int l,r;
	scanf("%d%d",&l,&r);
	printf("%d",(int)((f(r)-f(l-1)+mo)%mo));
}