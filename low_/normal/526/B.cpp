#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

int n, a[3000];

int _pow(int tp, int up)
{
	if (up==0) return 1;
	if (up==1) return tp;
	
	int t=pow(tp, up/2);
	if (up%2==1) return t*t*tp;
	else return t*t;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	a[0]=-1;
	a[1]=0;
	for (int i=2; i<_pow(2, n+1); i++) cin>>a[i];
	
	int dp[3000];
	for (int i=0; i<_pow(2, n+1); i++) dp[i]=a[i];
	int Ans=0;
	
	for (int i=_pow(2, n)-1; i>=1; i--)
	{
		dp[i]=max(dp[2*i], dp[2*i+1])+dp[i];
		Ans+=(max(dp[2*i], dp[2*i+1])-min(dp[2*i], dp[2*i+1]));
	}
	
	cout<<Ans;
}