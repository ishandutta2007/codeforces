#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int a[100005];
long long int b[100005];
long long int dp[100005];
long long int k[100005];
long long int l=1;
long long int cb=0;
double cd;
double epsilon=1;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	//for(int i=0;i<n;i++) a[i]--;
	dp[0]=0;
	k[0]=b[0];
	for(int i=1;i<n;i++)
	{
		if(cb>=l) cb=l-1;
		while(cb+1<l && dp[cb]+k[cb]*a[i]>=dp[cb+1]+k[cb+1]*a[i]) cb++;
		while(cb>0 && dp[cb]+k[cb]*a[i]>dp[cb-1]+k[cb-1]*a[i]) cb--;
		cd=dp[cb]+k[cb]*a[i];
		while(l>=2 && (cd-dp[l-2])/(0.0+k[l-2]-b[i])<=(dp[l-2]-dp[l-1])/(0.0+k[l-1]-k[l-2])) l--;
		dp[l]=cd;
		k[l]=b[i];
		l++;
	}
	cout<<dp[l-1]<<endl;
	return 0;
}