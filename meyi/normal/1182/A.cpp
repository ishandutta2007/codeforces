#include<cstdio>
inline int qpow2(int k){
	int f=1,r=1;
	while(k){
		if(k&1)r<<=f;
		f<<=1;
		k>>=1;
	}
	return r;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",n&1?0:qpow2(n>>1));
}