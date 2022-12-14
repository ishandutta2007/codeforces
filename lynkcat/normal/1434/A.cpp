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
#define N 100005
using namespace std;
int a[15];
int n,b[N];
pa c[N*7];
int vis[N],lst[N];
int cnt;
void BellaKira()
{
	for (int i=1;i<=6;i++)
		cin>>a[i];
	sort(a+1,a+6+1);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=6;j++)
		{
			c[++cnt]=mp(i,j);
		}
	sort(c+1,c+cnt+1,[&](pa x,pa y)
	{
		return b[x.fi]-a[x.se]<b[y.fi]-a[y.se];
	});
	int tt=0;
	multiset<int>S;
	int ans=inf;
	for (int i=cnt;i>=1;i--)
	{
		if (!vis[c[i].fi])
		{
			vis[c[i].fi]=1;
			tt++;
			S.insert(b[c[i].fi]-a[c[i].se]);
			lst[c[i].fi]=b[c[i].fi]-a[c[i].se];
		}else
		{
			S.erase(S.find(lst[c[i].fi]));
			S.insert(b[c[i].fi]-a[c[i].se]);
			lst[c[i].fi]=b[c[i].fi]-a[c[i].se];
		}
		if (tt==n)
		{
			ans=min(ans,(*S.rbegin())-b[c[i].fi]+a[c[i].se]);
			// cout<<"?"<<b[c[i].fi]-a[c[i].se]<<" "<<(*S.rbegin())<<endl;
		}
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