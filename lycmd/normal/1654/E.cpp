#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
int const N=100010,M=70000010,T=M/2,K=318;
int n,ans,a[N],cnt[M];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int d=-K;d<=K;d++){
		for(int i=1;i<=n;i++)
			if(0<=a[i]-i*d+T&&a[i]-i*d+T<M)
				ans=max(ans,++cnt[a[i]-i*d+T]);
		for(int i=1;i<=n;i++)
			if(0<=a[i]-i*d+T&&a[i]-i*d+T<M)
				cnt[a[i]-i*d+T]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=max(i-K,1);j<=min(i+K,n);j++)
			if(i!=j&&(a[i]-a[j])%(i-j)==0)
				ans=max(ans,(++cnt[(a[i]-a[j])/(i-j)+T])+1);
		for(int j=max(i-K,1);j<=min(i+K,n);j++)
			if(i!=j&&(a[i]-a[j])%(i-j)==0)
				cnt[(a[i]-a[j])/(i-j)+T]--;
	}
	cout<<n-ans<<"\n";
}