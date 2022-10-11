#include <iostream>
using namespace std;
#define mod 1000000007
int h[8005][8005],len[8005][8005],dp[8005];
long long tmp;
int go(int n)
{
	int x=0;
	while (n)
	{
		n/=10;
		x++;
	}
	return x;
}
int main()
{
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		h[i][i]=s[i]-'a';
		len[i][i]=1;
		for (int x=i+1;x<s.size();x++)
		{
			tmp=h[i][x-1];
			tmp=(tmp*26LL+s[x]-'a')%mod;
			h[i][x]=tmp;
			len[i][x]=x-i+1;
		}
	}
	for (int i=0;i<s.size();i++)
	{
		for (int x=i;x<s.size();x++)
		{
			if (x+len[i][x]<s.size() && h[x+1][x+len[i][x]]==h[i][i+len[i][x]-1])
			len[i][x+len[i][x]]=min(len[i][x+len[i][x]],len[i][x]);
		}
	}
	for (int i=0;i<s.size();i++)
	dp[i]=(1<<30);
	dp[0]=2;
	for (int i=1;i<s.size();i++)
	{
		dp[i]=len[0][i]+go((i+1)/len[0][i]);
		for (int x=i-1;x>=0;x--)
		dp[i]=min(dp[i],dp[x]+len[x+1][i]+go((i-x)/len[x+1][i]));
	}
	cout << dp[s.size()-1];
}