// Lynkcat.
// Problem: C. Detective Task
// URL: https://codeforces.com/contest/1675/problem/C
// Memory Limit: 256 MB
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
int n;
string  st;
int s[N][2];
void BellaKira()
{
	cin>>st;
	n=st.size();
	st=' '+st;
	for (int i=1;i<=n;i++)
	{
		s[i][0]=s[i-1][0];
		s[i][1]=s[i-1][1];
		if (st[i]=='1') s[i][1]++;
		else if (st[i]=='0')s[i][0]++;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		if (s[i-1][0]==0&&s[i][1]==s[n][1]) ans++;
	cout<<ans<<endl;
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}