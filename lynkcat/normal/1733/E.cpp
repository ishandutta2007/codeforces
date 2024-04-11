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
#define N 125
using namespace std;
int f[N][N],n=120,t,x,y;
void BellaKira()
{
	cin>>t>>x>>y;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) f[i][j]=0;
	if (x+y>t) return cout<<"NO\n",void();
	t-=x+y;
	f[0][0]=t;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			if (i+1<n)
			{
				f[i+1][j]+=(f[i][j])/2;
			}
			if (j+1<n)
			{
				f[i][j+1]+=(f[i][j]+1)/2;
			}
		}
	int X=0,Y=0;
	while (X<n&&Y<n)
	{
		// cout<<X<<" "<<Y<<" "<<f[X][Y]<<endl;
		if (x==X&&y==Y) return cout<<"YES\n",void();
		if (f[X][Y]%2==1) X++;
		else Y++;
	}
	cout<<"NO\n";
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