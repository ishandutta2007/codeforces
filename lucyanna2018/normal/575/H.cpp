#include<stdio.h>
int inv[1111111],n;
#define mod 1000000007
int add(int x,int y){
	return (x+=y)<mod?x:x-mod;
}
int mul(int x,int y){
	return (int)((long long int)x*y%mod);
}
int main(){
	scanf("%d",&n);
	int s = 1, z = 1,z2;
	inv[1] = 1;
	for(int i=2; i<=n+1; i++)
		inv[i] = mul(inv[mod%i],mod-mod/i);
	for(int i=1; i<=n; i++){
		z = mul(mul(z, 4*i-2),inv[i]);
		s = add(s,z);
		z2 = mul(mul(z, i),inv[i+1]);
		s = add(s,z2);
		s = add(s,z2);
	}
	printf("%d\n",s);
	return 0;
}