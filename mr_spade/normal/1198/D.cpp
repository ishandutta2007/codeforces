#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n;
int dp[N][N][N][N];
string a[N];
int f(int l,int r,int l2,int r2)
{
	if(~dp[l][r][l2][r2])
		return dp[l][r][l2][r2];
	int &res=dp[l][r][l2][r2];
	register int i;
	res=max(r-l+1,r2-l2+1);
	if(l==r&&l2==r2)
		return res=a[l][l2]=='#'?1:0;
	if(r-l+1>=r2-l2+1)
		for(i=l;i<r;i++)
			res=min(res,f(l,i,l2,r2)+f(i+1,r,l2,r2));
	else
		for(i=l2;i<r2;i++)
			res=min(res,f(l,r,l2,i)+f(l,r,i+1,r2));
	return res;
}
signed main()
{
	register int i;
	ios::sync_with_stdio(0);
	cin>>n;memset(dp,-1,sizeof(dp));
	for(i=1;i<=n;i++)
		cin>>a[i],a[i]='$'+a[i];
	cout<<f(1,n,1,n)<<endl;
	return 0;
}