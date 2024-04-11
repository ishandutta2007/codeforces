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
int n,a[N];
int pre[N];
int pre1[N];
int lst[N];
void BellaKira()
{
	cin>>n;
	map<int,int>Mp;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) 
	{
		if (!Mp.count(a[i])) lst[i]=0;
		else lst[i]=Mp[a[i]];
		Mp[a[i]]=i;
	}
	int ans=Mp.size();
	for (int i=1;i<=n;i++) pre[i]=max(pre[i-1],a[i]);
	for (int i=1;i<=n;i++) pre1[i]=min(pre1[i-1],a[i]);
	int tt=0;
	int x=0;
	a[n+1]=n+1;
	for (int i=n;i>=1;i--)
	{
		if (i!=n&&a[i]>a[i+1]) break;
		if (i==n) tt++;
		else  tt+=a[i]!=a[i+1];
		if (lst[i]&&a[i]<a[i+1]) x++;
		else if (lst[i]==0&&a[i]==a[i+1]) x--;
		// cout<<i<<" "<<x<<" "<<tt<<endl;
		if (x==0)
			ans=min(ans,(int)Mp.size()-tt);
	}
	cout<<ans<<'\n';
}
signed main()
{
	pre1[0]=inf;
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}