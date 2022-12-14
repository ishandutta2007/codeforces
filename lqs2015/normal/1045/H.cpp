#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define y0 y_0
#define y1 y_1
#define yn y_n
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;
const long long Mod=1000000007;

long long fact[800015],inv[800015],lena,lenb;

long long fpow(long long a,long long b){
	if(b==0)return 1;
	long long res=fpow(a,b/2);
	(res*=res)%=Mod;
	return b%2==0?res:res*a%Mod;
}

void preprocess(){
	fact[0]=1;
	for(long long i=1;i<=800010;i++)fact[i]=(long long)fact[i-1]*(long long)i%Mod;
	for(long long i=0;i<=800010;i++)inv[i]=fpow(fact[i],Mod-2);
}

long long binomial(long long n,long long m){
	if(n<0) return 0;
	if(m==0)return 1;
	if(n<m)return 0;
	if(m<0 || n<0) return 0;
	long long res=fact[n];
	(res*=inv[m])%=Mod;
	(res*=inv[n-m])%=Mod;
	return res;
}

long long split(long long n,long long m){
	if (n==0 && m==0) return 1;
	return binomial(n+m-1,m-1);
}

long long calc(long long c00,long long c01,long long c10,long long c11){
	if(c10<0 || c01<0 || (c10-c01!=0&&c10-c01!=-1))return 0;
	long long res=split(c00,c10+1);
	(res*=split(c11,c01))%=Mod;
	return res;
}

long long solve(long long n,long long c00,long long c01,long long c10,long long c11,char* s){
	if (strlen(s)>n)
	{
		long long len=n;
		for (long long i=0;i<len;i++) s[i]='1';
		s[len]='\0';
	}
	if (strlen(s)<n) return 0;
	long long res=0;
	for(long long i=n-1;i>=0;i--){
		if(s[i]=='1'){
			if(i<n-1){
				if(i<n-1&&s[i+1]=='0')c00--;
				else if(i<n-1)c10--;
				(res+=calc(c00,c01,c10,c11))%=Mod;
				if(i<n-1&&s[i+1]=='0')c00++;
				else if(i<n-1)c10++;
			}
			if(i<n-1&&s[i+1]=='0')c01--;
			else if(i<n-1)c11--;
		}else{
			if(i<n-1&&s[i+1]=='0')c00--;
			else if(i<n-1)c10--;
		}
	}
	if ((n>1 || s[0]=='1') && !c00 && !c11 && !c10 && !c01) res++;
	return res;
}

long long n,c00,c01,c10,c11;
char a[400005],b[400005];

int main(){
	preprocess();
	scanf("%s %s %I64d %I64d %I64d %I64d",a,b,&c00,&c01,&c10,&c11);
	n=c00+c01+c10+c11+1;
	lena=strlen(a);
	lenb=strlen(b);
	reverse(a,a+lena);
	reverse(b,b+lenb);
	a[0]--;
	long long p=0;
	while(a[p]<'0')a[p]='1',a[++p]--;
	long long resb=solve(n,c00,c01,c10,c11,b),resa=solve(n,c00,c01,c10,c11,a);
	printf("%I64d\n",(resb+Mod-resa)%Mod);
	return 0;
}