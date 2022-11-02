// Author: Little09
// Problem: D. Equal Binary Subsequences
// Contest: Codeforces - Codeforces Round #825 (Div. 2)
// URL: https://codeforces.com/contest/1736/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define endl "\n"
#define lowbit(x) ((x)&(-(x)))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

int find(int x)
{
	int u=a[x];
	while (x<=2*n&&a[x]==u) x++;
	return x-1;
}

int ans[N],cntt;


void work()
{
	cin >> n;
	cntt=0;
	for (int i=1;i<=2*n;i++)
	{
		char x;
		cin >> x;
		a[i]=x-'0';
	}
	int cnt=0;
	for (int i=1;i<=2*n;i++) cnt+=a[i];
	if (cnt%2==1)
	{
		cout << -1 << endl;
		return;
	}
	int tp=a[1];
	for (int i=1;i<=2*n;i++)
	{
		int u=find(i);
		// cout << i << " " << u << endl;
		// for (int j=1;j<=2*n;j++) cout << a[j];
		// cout << endl;
		if ((u-i+1)%2==0)
		{
			i=u;
			continue;
		}
		if (tp==a[i])
		{
			a[u]^=1;
			ans[++cntt]=u;
			i=i-1;
			tp^=1;
		}
		else 
		{
			a[u+1]^=1;
			ans[++cntt]=u+1;
			i=i-1;
			tp^=1;
		}
	}
	cout << cntt << " ";
	for (int i=1;i<=cntt;i++) cout << ans[i] << " ";
	cout << endl;
	// for (int i=1;i<=2*n;i++) cout << a[i];
	// cout << endl;
	for (int i=1;i<=n;i++) cout << i*2-1 << " ";
	cout << endl;
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