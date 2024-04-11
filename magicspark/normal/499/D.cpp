#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
int n,T;
double dp[5005][5005];
double pw[5005];
double p[5005];
double sum[5005];
int t[5005];
inline double power(double x,int y){
	double ret=1;
	while(y){
		if(y&1)ret*=x;
		x*=x;
		y>>=1;
	}
	return ret;
}
int main(){
	cin>>n>>T;
	for(int i=1;i<=n;i++)scanf("%lf%d",&p[i],&t[i]),p[i]/=100.0;
	dp[0][0]=1;
	register double ans=0;
	for(register int i=0;i<n;++i){
		memset(sum,0,sizeof(sum));
		double prob=power(1-p[i+1],t[i+1]),prob2=prob;
		for(register int j=0;j<=T;++j){
			register int ed=min(T,j+t[i+1]);
			if(T<j+t[i+1])prob2/=(1-p[i+1]);
			if(dp[i][j]<3e-10)continue;
			sum[j+1]+=dp[i][j];
			sum[ed+1]-=dp[i][j]*prob2;
			if(j+t[i+1]<=T)dp[i+1][j+t[i+1]]+=dp[i][j]*prob;
		}
		for(register int j=0;j<=T;++j){
			if(j)sum[j]+=sum[j-1]*(1-p[i+1]);
			dp[i+1][j]+=sum[j]*p[i+1];
			ans+=dp[i+1][j];
		}
	}
	printf("%.12lf\n",ans);
	return 0;
}