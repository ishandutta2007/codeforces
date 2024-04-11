#include <bits/stdc++.h>
using namespace std;
int n,arr[500005];
long long dp[2][500005];
int go(int a)
{
	stack<int> s;
	s.push(0);
	for (int i=1;i<=n;i++)
	{
		while (arr[i]<=arr[s.top()])
		s.pop();
		dp[a][i]=dp[a][s.top()]+1LL*arr[i]*(i-s.top());
		s.push(i);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	go(0);
	reverse(arr+1,arr+n+1);
	go(1);
	reverse(arr+1,arr+n+1);
	pair<long long,int> mx(0,1);
	for (int i=1;i<=n;i++)
	mx=max(mx,make_pair(dp[0][i]+dp[1][n-i+1]-arr[i],i));
	for (int i=mx.second+1;i<=n;i++)
	arr[i]=min(arr[i],arr[i-1]);
	for (int i=mx.second-1;i>0;i--)
	arr[i]=min(arr[i],arr[i+1]);
	for (int i=1;i<=n;i++)
	printf("%d ",arr[i]);
}