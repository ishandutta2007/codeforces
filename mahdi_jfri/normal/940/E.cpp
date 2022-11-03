#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

ll a[maxn] , dp[maxn] , mn[maxn] , sum[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , c;
	cin >> n >> c;

	if(c == 1)
		return cout << 0 << endl , 0;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i] , sum[i] = sum[i - 1] + a[i];

	deque<int> dq;
	for(int i = 1; i <= n; i++)
	{
		while(!dq.empty() && a[i] < a[dq.back()])
			dq.pop_back();
		dq.pb(i);

		if(dq.front() == i - c)
			dq.pop_front();

		if(i >= c)
			mn[i] = a[dq.front()];
	}

	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + a[i];
		if(i >= c)
			dp[i] = min(dp[i] , dp[i - c] + sum[i] - sum[i - c] - mn[i]);
	}

	cout << dp[n] << endl;

}