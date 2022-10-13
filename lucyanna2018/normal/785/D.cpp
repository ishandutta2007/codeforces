#include<stdio.h>
#include<string.h>
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
int fac[444444];
char s[222222];int ls;
int main(){
	fac[0] = 1;
	for(int i=1; i<444444; i++)
		fac[i] = mul(fac[i-1],i);
	scanf("%s",s);
	ls = strlen(s);
	int r = 0;
	for(int i=0; i<ls; i++)
		if(s[i] == ')')
			r++;
	int c = 0,res = 0;
	for(int i=0; i<ls; i++)
		if(s[i] == '('){
			++c;
			if(r > 0)
			res = add(res, mul(fac[c-1+r],pw(mul(fac[c],fac[r-1]),mod-2)));
		}
		else
			r--;
	printf("%d\n",res);
	return 0;
}