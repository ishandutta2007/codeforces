#include <iostream>
using namespace std;
int dp[100005];
bool b[100005];
int main()
{
	int n,m;
	cin >> n >> m;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	for (int i=n-1;i>=0;i--)
	{
		if (b[arr[i]])
		dp[i]=dp[i+1];
		else
		{
			b[arr[i]]=true;
			dp[i]=1+dp[i+1];
		}
	}
	for (int i=0;i<m;i++)
	{
		int a;
		cin >> a;
		cout << dp[a-1] << endl;
	}
}