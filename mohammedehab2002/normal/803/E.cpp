#include <iostream>
#include <string.h>
using namespace std;
char dp[1005][2005];
char a[]="WLD";
int a2[3]={-1,1,0};
string ans="";
string s;
void go(int n,int k)
{
	if (n==0)
	return;
	for (int i=0;i<3;i++)
	{
		if (dp[n][k]==a[i])
		go(n-1,k+a2[i]);
	}
	ans+=dp[n][k];
}
int main()
{
	int n,k;
	cin >> n >> k >> s;
	for (int i=0;i<=n;i++)
	{
		for (int x=-k;x<=k;x++)
		dp[i][x+k]='N';
	}
	dp[0][k]='Y';
	for (int i=1;i<=n;i++)
	{
		for (int x=-k;x<=k;x++)
		{
			for (int j=0;j<3;j++)
			{
				if (a[j]==s[i-1] || s[i-1]=='?')
				{
					if (x+a2[j]<=-k || x+a2[j]>=k)
					continue;
					if (dp[i-1][x+a2[j]+k]!='N')
					dp[i][x+k]=a[j];
				}
			}
		}
	}
	if (dp[n][2*k]!='N')
	go(n,2*k);
	else if (dp[n][0]!='N')
	go(n,0);
	else
	{
		cout << "NO";
		return 0;
	}
	cout << ans;
}