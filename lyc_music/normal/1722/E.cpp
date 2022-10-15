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
#define N 1005
using namespace std;
int n,q,s[N][N];
void BellaKira()
{
	cin>>n>>q;
	memset(s,0,sizeof(s));
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		s[x][y]+=x*y;
	}
	for (int i=1;i<=1000;i++)
		for (int j=1;j<=1000;j++)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for (int i=1;i<=q;i++)
	{
		int l,L,r,R;
		cin>>l>>L>>r>>R;
		l++,r--;
		L++,R--;
		if (l>r||L>R) cout<<0<<'\n';
		else
		cout<<s[r][R]-s[l-1][R]-s[r][L-1]+s[l-1][L-1]<<'\n';
	}
	
		
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