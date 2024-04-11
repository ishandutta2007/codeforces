#include <bits/stdc++.h>
using namespace std;
bool vis[2005][2005];
int n,k,a[10][2005];
string s[]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"},ans;
bool solve(int idx,int cnt)
{
	if (cnt>k)
	return 0;
	if (idx==n)
	return (cnt==k);
	if (vis[idx][cnt])
	return 0;
	vis[idx][cnt]=1;
	for (int i=9;i>=0;i--)
	{
		if (solve(idx+1,cnt+a[i][idx]))
		{
			ans+=i+'0';
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin >> n >> k;
	for (int i=0;i<n;i++)
	{
		string x;
		cin >> x;
		for (int j=0;j<10;j++)
		{
			for (int l=0;l<7;l++)
			{
				a[j][i]+=(x[l]!=s[j][l]);
				if (x[l]=='1' && s[j][l]=='0')
				a[j][i]=1e9;
			}
		}
	}
	if (solve(0,0))
	{
		reverse(ans.begin(),ans.end());
		cout << ans;
	}
	else
	cout << "-1";
}