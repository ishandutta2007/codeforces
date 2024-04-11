#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 3010
#define ll long long
#define inf 1e18
using namespace std;

ll a1[N],a2[N];
ll n,dp[N][N];
ll ans=inf,temp;

int main(){
	scanf("%lld", &n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a2[i]);
		a2[i]-=i;a1[i]=a2[i];
	}
	sort(a2+1,a2+n+1);
	
	for(int i=1;i<=n;++i){
		temp=inf;
		for(int j=1;j<=n;++j){
			temp=min(temp,dp[i-1][j]);
			dp[i][j]=temp+abs(a1[i]-a2[j]);
		}
	}
	/*
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
		 printf("%lld ",dp[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<=n;++i)
	 ans=min(ans,dp[n][i]);
	printf("%lld", ans);
	return 0;
}