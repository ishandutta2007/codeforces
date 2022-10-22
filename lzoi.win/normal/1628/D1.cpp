#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN=2005,mod=1e9+7;
int n,m,k;
int f[MAXN][MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
//double f[MAXN][MAXN];
int main(){
	/*
	n=7;
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++)
			for(double x=0; x<=1; x+=1e-6)
				f[i][j]=max(f[i][j],min(f[i-1][j]-x,f[i-1][j-1]+x));
		f[i][i]=i;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++)
			cout<<f[i][j]*(1<<i-1)<<' ';
		puts("");
	}
	return 0;
	*/
	n=2000;
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++)
			f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
		f[i][i]=i*Fstpw(2,i-1)%mod;
	}
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&n,&m,&k);
		k=k*Fstpw(mod+1>>1,n-1)%mod*f[n][m]%mod;
		printf("%d\n",k);
	}
	return 0;
}