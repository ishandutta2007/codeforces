// Lynkcat.
// Problem: D. Vowels
// Contest: Codeforces - 10.9(1)
// URL: https://codeforces.com/gym/403085/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
// #define int ll
#define N 10005
using namespace std;
int n,f[N],a[N],s[N];
int cnt[N];
int ans;
void BellaKira()
{
	cin>>n;
	int p=0;
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		for (auto u:st)
			a[i]|=(1<<(u-'a')),p|=a[i];
	}
	if (p!=(1<<24)-1) return cout<<0<<'\n',void();
	for (int i=1;i<=n;i++)
		f[a[i]%(1<<12)]++;
	for (int j=0;j<12;j++)
		for (int i=0;i<(1<<12);i++)
			if ((i>>j)&1)
				f[i]+=f[i-(1<<j)];
	for (int i=0;i<(1<<12);i++)
	{
		for (int j=1;j<=n;j++)
			if ((a[j]>>12)&i)
			{
				s[a[j]%(1<<12)]++;
			}
		for (int j=0;j<12;j++)
			for (int ii=0;ii<(1<<12);ii++)
				if ((ii>>j)&1)
					s[ii]+=s[ii-(1<<j)];
		// s[0]=0;
		for (int j=0;j<(1<<12);j++)
		{
			int x=n-f[j^((1<<12)-1)]+s[j^((1<<12)-1)];
			cnt[x]++;
			if (i+j)
				ans^=x*x;
		}
		for (int j=0;j<(1<<12);j++) s[j]=0;
	}
	cout<<ans<<'\n';	
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}