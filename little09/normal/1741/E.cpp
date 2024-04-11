// Author: Little09
// Problem: E. Sending a Sequence Over the Network
// Contest: Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/E
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
vector<int>b[N];
int dp[N];

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) b[i].clear();
	for (int i=1;i<=n;i++)
	{
		int l=i,r=i+a[i];
		if (r<=n) b[r].push_back(l);
	}
	for (int i=1;i<=n;i++) dp[i]=0;
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		if (i-a[i]-1>=0&&dp[i-a[i]-1]) dp[i]=1;
		for (int j:b[i]) if (dp[j-1]) dp[i]=1;
	}
	if (dp[n]) printYES;
	else printNO;
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