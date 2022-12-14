#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define endl '\n'
#define mem(a) memset(a,0x3f,sizeof a)
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
const int N = 5e3+10;
int a[N], b[N], dp[N][N];  // dp[i][j]ij
int q,w;
int ff[N][N];
int ans = 1e18;
void solve()
{
	mem(dp);
	mem(ff);
	int n; cin>>n;
	int flag = 0;
	for1
	{
		int x; cin>>x;
		if(x>0) 
		{
			flag = 1;
			q++;
			a[q] = i;
		}
		else 
		{
			w++;
			b[w] = i;
		}
	}
	if(!flag) 
	{
		cout<<0<<endl;
		return;	
	}
	for2(i,0,w) dp[0][i] = ff[0][i] = 0;
	for2(i,1,q) 
	{
		for2(j,1,w) 
		{
			int t = abs(a[i] - b[j]);
			dp[i][j] = ff[i - 1][j - 1] + t;
		}
		for2(j,0,w)
		{
			ff[i][j] = min(ff[i][j - 1], dp[i][j]);
		}
			
	}
	for2(i,1,w)
	{
		ans = min(ans,dp[q][i]);
	}	
	cout<<ans<<endl;
	return;
}
signed main()
{
	ios;
	int tt=1;
//	cin>>tt;
	while(tt--)
	{
		solve();
	}


}