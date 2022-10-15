// Lynkcat.
// Problem: C. Binary String
// URL: https://codeforces.com/contest/1680/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
string st;
int s[N][2];
void BellaKira()
{
	cin>>st;
	int n=st.size();
	st=' '+st;
	int ans=n;
	for (int i=1;i<=n;i++)
		s[i][1]=(s[i-1][1]+(st[i]=='1')),
		s[i][0]=(s[i-1][0]+(st[i]=='0'));
	for (int i=0;i<=n;i++)
	{
		int l=i+1,r=n;
		int now=i+1;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (s[mid][0]-s[i][0]<=s[i][1]+s[n][1]-s[mid][1])
			{
				now=mid;
				l=mid+1;
			} else r=mid-1;
		}
		if (i==n) ans=min(ans,s[i][1]);
		for (int j=now;j<=now+1&&j<=n;j++)
		{
			ans=min(ans,max(s[now][0]-s[i][0],s[i][1]+s[n][1]-s[now][1]));
		}
	}
	cout<<ans<<endl;
			
		
		
}	
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}