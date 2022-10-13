#include<stdio.h>
int F,W,H;
int fac[222222],ifac[222222];

#define mod 1000000007
int add(int x,int y){
	return (x+=y)<mod?x:x-mod;
}
int mul(int x,int y){
	return (int)((long long int)x*y%mod);
}
int pw(int x,int y){
	int r=1;
	while(1){
		if(y&1)r=mul(r,x);
		if(y>>=1)x=mul(x,x);else
			break;
	}
	return r;
}
int inv(int x){
	return pw(x,mod-2);
}
int c(int x,int y){
	return mul(fac[x],mul(ifac[y],ifac[x-y]));
}
int calc(int F,int W,int H){
	if(W == 0)return 1;
	if(W <= H)return 0;
	int res = 0;
	for(int u=1; u<=F+1 && u*(H+1)<=W; u++){
		int L = W - u*(H+1);
		res = add(res, mul(c(F+1, u), c(L+u-1,u-1)));
	}
	return res;
}

int main(){
	fac[0] = ifac[0] = 1;
	for(int i=1; i<222222; i++){
		fac[i] = mul(fac[i-1],i);
		ifac[i] = inv(fac[i]);
	}
	scanf("%d%d%d",&F,&W,&H);
	printf("%d\n",mul(calc(F,W,H),inv(c(F+W,F))));
	return 0;
}