#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int f[200005];
int nf[200005];

int pw(int a, int b){
	if(b==0)return 1;
	if(b%2)return (1LL*a*pw(a,b-1))%MOD;
	int m=pw(a,b/2);
	return (1LL*m*m)%MOD;
}

int comb(int n, int k){
	return (((1LL*f[n]*nf[k])%MOD)*nf[n-k])%MOD;
}

int h(int n, int m, int g){
	int r=0;
	while(1){
		if(n+m<=0||n<0||m<0)return r;
		if(g){
			if(n==0&&m==1)return (r+1)%MOD;
			n--;g=0;
		}
		else {
			if(n==1&&m==0)return (r+1)%MOD;
			if(m>0&&n+m>1)r=(r+comb(n+m-1,n))%MOD;
			if(!n)return r;
			n--;g=1;
		}
	}
}

int main(){
	f[0]=nf[0]=1;
	for(int i=1;i<200005;++i){
		f[i]=(1LL*i*f[i-1])%MOD;
		nf[i]=pw(f[i],MOD-2);
	}
	int n,m,g;
	scanf("%d%d%d",&n,&m,&g);
	printf("%d\n",h(n,m,g));
	return 0;
}