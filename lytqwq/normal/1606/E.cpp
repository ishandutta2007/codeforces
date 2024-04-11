#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353; 
int n,x,inv[N];
int f[N][N],vis[N][N];
int Qp(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*1ll*x%mod;
		x=x*1ll*x%mod;
		y>>=1;
	}
	return res;
}
int dp(int q1,int q2){
	if(vis[q1][q2])return f[q1][q2];
	vis[q1][q2]=1;
	if(q2<q1){
		f[q1][q2]=Qp(q2,q1);
	}
	else{
		f[q1][q2]=Qp(q1-1,q1);
		int res=1;
		for(int i=0;i<q1;i++){
			f[q1][q2]=(f[q1][q2]+res*1ll*dp(q1-i,q2-q1+1)%mod*1ll*Qp(q1-1,i))%mod;
			res=res*1ll*(q1-i)%mod*inv[i+1]%mod;
		}
	}
	return f[q1][q2];
}
int main(){
	scanf("%d%d",&n,&x);
	inv[0]=inv[1]=1;
	for(int i=2;i<=500;i++){
		inv[i]=inv[mod%i]*1ll*(mod-mod/i)%mod; 
	}
	printf("%d\n",dp(n,x));
	return 0;
}
/*
Qp(n-1,n)+Qp(n-1,k)\timesQp(
*/