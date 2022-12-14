// Problem: C. Hamiltonian Wall
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/C
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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int n,m;
string a[2];
int vis[2][N];
int ans;
int ins[2][N];
int mx;
void dfs(int x,int y,int tt)
{
	if (vis[x][y]) return;
	vis[x][y]=1;
	mx=max(mx,tt);
	// cout<<x<<" "<<y<<" "<<tt<<'\n';
	if (x) 
	{
		if (a[x-1][y]=='B') dfs(x-1,y,tt+1);
	}
	else 
	{
		if (a[x+1][y]=='B') dfs(x+1,y,tt+1);
	}
	if (y) 
	{
		if (a[x][y-1]=='B') dfs(x,y-1,tt+1);
	}
	if (y+1<m)
	{
		if (a[x][y+1]=='B') dfs(x,y+1,tt+1);
	}
}
void clr()
{
	for (int i=0;i<2;i++)
		for (int j=0;j<m;j++) vis[i][j]=0;
}
void BellaKira()
{
	cin>>n;
	cin>>a[0]>>a[1];
	int tt=0;
	ans=0;
	int tot=0;
	m=n;
	for (int i=0;i<2;i++)
		for (int j=0;j<m;j++) vis[i][j]=0,tot+=(a[i][j]=='B');
	for (int j=0;j<m;j++)
	{
		bool bl=0;
		for (int i=0;i<2;i++)
		{
			if (a[i][j]=='B'&&!vis[i][j])
			{
				bl=1;
				mx=0;
				// cout<<"?"<<i<<" "<<j<<'\n';
				dfs(i,j,1);
				// cout<<"?"<<mx<<" "<<tot<<'\n';
				if (mx==tot) ans|=1;
				clr();
			}
		}
		if (bl) break;
	}
	if (ans)
		cout<<"YES\n";
	else cout<<"NO\n";
				
				
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}