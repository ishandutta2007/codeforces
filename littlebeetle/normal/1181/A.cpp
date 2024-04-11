#include<cstdio>
long long x,y,z,p;
int main(){
	scanf("%lld%lld%lld",&x,&y,&z);
	p=x/z+y/z;
	x%=z;y%=z;
	if(x+y<z)
		printf("%lld 0",p);
	else
		printf("%lld %lld",p+1,z-(x>y?x:y));
}