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
#define N 100005 
using namespace std;
int n,a[N];
int cnt[3];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=3;
		cnt[a[i]]++;
	}
		if (cnt[0]>=n/2)
		{
			cout<<2<<endl;
			int x=n/2;
			for (int j=1;j<=n;j++)
				if (x&&a[j]==0) cout<<0,x--;
				else cout<<1;
			return;
		}
	cout<<0<<endl;
	int x=n/2;
	for (int j=1;j<=n;j++)
		if (!x||a[j]==0) cout<<0;
		else cout<<1,x--;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}