// Lynkcat.
// Problem: C. Minimize the Thickness
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define int ll
#define N 2005
using namespace std;
int n,a[N],s[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	int Ans=n;
	for (int i=1;i<=n;i++)
	{
		int x=s[i];
		int lst=i;
		int ans=i;
		for (int j=i+1;j<=n;j++)
			if (s[j]-s[lst]>x) {
				ans=0;
				break;
			} else
			if (s[j]-s[lst]==x)
			{
				ans=max(ans,j-lst);
				lst=j;
			}
		if (lst!=n) ans=0;
		if (ans==0) continue;
		Ans=min(Ans,ans);
	}
	cout<<Ans<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}