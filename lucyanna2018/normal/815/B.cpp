#include<stdio.h>

#define mod 1000000007
int add(int x,int y){
	return (x+=y)<mod?x:x-mod;
}
int sub(int x,int y){
	return add(x,mod-y);
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

int n,a[222222],coef[222222];
int fac[222222],ifac[222222];
int c(int x,int y){
	return mul(fac[x],mul(ifac[y],ifac[x-y]));
}
int main(){
	scanf("%d",&n);
	fac[0] = ifac[0] = 1;
	for(int i=1; i<=n; i++){
		fac[i] = mul(fac[i-1],i);
		ifac[i] = pw(fac[i], mod-2);
	}
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	int k = (n-1) / 4, m, l;
	if(n % 4 == 0){
		m = 2 * k + 1;
		l = 0;
		for(int i=0; i<=m; i++){
			int now = c(m,i);
			coef[l++] = now;
			coef[l++] = sub(0,now);
		}
	}else
	if(n % 4 == 1){
		m = 2 * k;
		l = 0;
		for(int i=0; i<=m; i++){
			int now = c(m,i);
			coef[l++] = now;
			coef[l++] = 0;
		}
	}else
	if(n % 4 == 2){
		m = 2 * k;
		l = 0;
		for(int i=0; i<=m; i++){
			int now = c(m,i);
			coef[l++] = now;
			coef[l++] = now;
		}
	}else{
		m = 2 * k;
		l = 0;
		for(int i=0; i<=m; i++){
			int now = c(m,i);
			coef[l++] = now;
			coef[l++] = now;
		}
		l = 1;
		for(int i=0; i<=m; i++){
			int now = c(m,i);
			coef[l] = add(coef[l],now);l++;
			coef[l] = sub(coef[l],now);l++;
		}
	}
	int res=0;
	for(int i=0; i<n; i++)
		res=add(res,mul(coef[i],a[i]));
	printf("%d\n",res);
	return 0;
}