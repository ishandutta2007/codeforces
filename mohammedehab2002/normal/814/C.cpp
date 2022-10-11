#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int dp[26][1505];
int main()
{
	int n;
	string s;
	cin >> n >> s;
	for (int i=0;i<26;i++)
	{
		for (int x=0;x<s.size();x++)
		{
			int need=0;
			if (s[x]-'a'!=i)
			need++;
			dp[i][need]=max(dp[i][need],1);
			for (int j=x+1;j<s.size();j++)
			{
				if (s[j]-'a'!=i)
				need++;
				dp[i][need]=max(dp[i][need],j-x+1);
			}
		}
		for (int x=1;x<=s.size();x++)
		dp[i][x]=max(dp[i][x],dp[i][x-1]);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int a;
		char c;
		cin >> a >> c;
		cout << dp[c-'a'][a] << endl;
	}
}