#include <iostream>
using namespace std;
int arr[105][105];
struct ret{
	int n,m;
	string s;
	void init(int nn,int mm,string ss)
	{
		n=nn;
		m=mm;
		s=ss;
	}
};
ret dp[105][105][15];
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	k++;
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		{
			char a;
			cin >> a;
			arr[i][x]=a-'0';
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		{
			for (int j=0;j<k;j++)
			dp[i][x][j].init(-(1<<30),0,"");
		}
	}
	for (int i=0;i<m;i++)
	dp[n-1][i][arr[n-1][i]%k].init(arr[n-1][i],i+1,"");
	for (int i=n-2;i>=0;i--)
	{
		for (int x=0;x<m;x++)
		{
			for (int j=0;j<k;j++)
			{
				int f=(j-arr[i][x]);
				while (f<0)
				f+=k;
				if (x==0)
				dp[i][x][j].init(dp[i+1][1][f].n+arr[i][x],dp[i+1][1][f].m,dp[i+1][1][f].s+"L");
				else if (x==m-1)
				dp[i][x][j].init(dp[i+1][m-2][f].n+arr[i][x],dp[i+1][m-2][f].m,dp[i+1][m-2][f].s+"R");
				else
				{
					if (dp[i+1][x-1][f].n<dp[i+1][x+1][f].n)
					dp[i][x][j].init(dp[i+1][x+1][f].n+arr[i][x],dp[i+1][x+1][f].m,dp[i+1][x+1][f].s+"L");
					else
					dp[i][x][j].init(dp[i+1][x-1][f].n+arr[i][x],dp[i+1][x-1][f].m,dp[i+1][x-1][f].s+"R");
				}
			}
		}
	}
	int ans=-1,st;
	string s;
	for (int i=0;i<m;i++)
	{
		if (dp[0][i][0].n>ans)
		{
			ans=dp[0][i][0].n;
			st=dp[0][i][0].m;
			s=dp[0][i][0].s;
		}
	}
	if (ans==-1)
	cout << -1;
	else
	cout << ans << endl << st << endl << s;
}