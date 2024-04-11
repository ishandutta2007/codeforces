// Author: Little09
// Problem: C. Robot in a Hallway
// Contest: Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[2][N],g[2][N],s[2][N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[0][i];
	for (int i=1;i<=n;i++) cin >> a[1][i];
	for (int j=0;j<=1;j++)
	{
		for (int i=1;i<=n;i++) if (a[j][i]) a[j][i]++;
		for (int i=1;i<=n;i++) g[j][i]=a[j][i]+i;
		for (int i=1;i<=n;i++) s[j][i]=a[j][i]-i;
		for (int i=n-1;i>=1;i--) g[j][i]=max(g[j][i],g[j][i+1]);
		for (int i=n-1;i>=1;i--) s[j][i]=max(s[j][i],s[j][i+1]);
	}
	int x=0,ans=2e9,res=0,tot=0;
	for (int i=1;i<=n;i++)
	{
		res=max(res,a[x][i]-tot);
		if (i==n)
		{
			res=max(res,a[x^1][i]-tot-1);
			ans=min(ans,res);
			break;
		}
		int u=res;
		u=max(u,s[x][i+1]+i-tot);
		//cout << s[x][i+1]+i-tot << endl;
		u=max(u,g[x^1][i+1]-tot+i-1-2*n);
		//cout << g[x^1][i+1] << endl;
		u=max(u,a[x^1][i]-(tot+2*n-2*i+1));
		ans=min(ans,u);
		x^=1;
		tot+=2;
		res=max(res,a[x][i]-tot+1);
	}
	cout << ans+2*n-1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}