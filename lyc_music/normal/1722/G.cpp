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
#define N 200005
using namespace std;
int n,ans[N];
void BellaKira()
{
	cin>>n;
	if (n%2==0)
	{
		int tt=0;
		for (int i=1;i<=n;i+=2)
		{
			ans[i]=tt;
			tt++;
		}
		int tt1=0;
		if ((n/2)%2==0)
		{
			for (int i=2;i<=n;i+=2)
			{
				ans[i]=tt1|(1ll<<30);
				tt1++;
			}
		} else
		{
			for (int i=2;i<=n-1;i+=2)
			{
				ans[i]=tt1|(1ll<<30);
				tt1++;
			}
			ans[n]=tt1|(1ll<<29);
			tt1++;
			ans[n-2]|=(1ll<<29);
		}
	} else
	{
		if ((n/2)%2==0)
		{
			int tt=1;
			for (int i=1;i<=n;i+=2)
			{
				ans[i]=tt;
				tt++;
			}
			ans[n]=0;
			tt=1;
			for (int i=2;i<=n;i+=2)
			{
				ans[i]=tt|(1ll<<30);
				tt++;
			}
		} else
		{
			int tt=1;
			for (int i=1;i<=n;i+=2)
			{
				ans[i]=tt|(1ll<<30);
				tt++;
			}
			ans[n]=(1ll<<30);
			tt=1;
			for (int i=2;i<=n;i+=2)
			{
				ans[i]=tt;
				tt++;
			}
		}
	}
	static int g[2];
	g[0]=g[1]=0;
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ",g[i%2]^=ans[i];
	cout<<endl;
	
	// cout<<g[0]<<" "<<g[1]<<endl;
		
			
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