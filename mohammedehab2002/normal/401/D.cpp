#include <iostream>
using namespace std;
string s;
long long pow[19],fact[19],dp[(1<<18)][100];
int m,cnt[10];
int main()
{
	cin >> s >> m;
	pow[0]=1;
	fact[0]=1;
	for (int i=1;i<19;i++)
	{
		pow[i]=10*pow[i-1];
		fact[i]=i*fact[i-1];
	}
	for (int i=0;i<s.size();i++)
	cnt[s[i]-'0']++;
	dp[0][0]=1;
	for (int mask=1;mask<(1<<s.size());mask++)
	{
		int x=__builtin_popcount(mask)-1;
		for (int mod=0;mod<m;mod++)
		{
			for (int i=0;i<s.size();i++)
			{
				if (mask&(1<<i) && (x!=s.size()-1 || s[i]!='0'))
				dp[mask][(mod+pow[x]*(s[i]-'0'))%m]+=dp[mask^(1<<i)][mod];
			}
		}
	}
	long long ans=dp[(1<<s.size())-1][0];
	for (int i=0;i<10;i++)
	ans/=fact[cnt[i]];
	cout << ans;
}