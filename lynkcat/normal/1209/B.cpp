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
#define N 105
using namespace std;
int n,a[N],b[N];
string st;
int ans;
void BellaKira()
{
	cin>>n;
	cin>>st;
	st=' '+st;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for (int j=0;j<=1000;j++)
	{
			int now=0;
		for (int i=1;i<=n;i++)	now+=st[i]-'0';
		ans=max(ans,now);
		for (int i=1;i<=n;i++)	
			if (j>=b[i]&&(j-b[i])%a[i]==0) st[i]='1'-st[i]+'0';
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