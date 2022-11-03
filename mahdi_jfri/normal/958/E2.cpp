#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

const int maxn = 5e5 + 20;

ll n , x[maxn] , a[maxn];
pair<ll , int> dp[maxn];

pair<ll , int> f(ll m)
{
	dp[0] = make_pair(0 , 0);
	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		pair<ll , int> t;

		if(i >= 2)
			t = make_pair(dp[i - 2].first + a[i] + m , dp[i - 2].second + 1);
		else
			t = make_pair(a[i] + m , 1);

		if(t.first < dp[i].first || (t.first == dp[i].first && t.second < dp[i].second))
			dp[i] = t;
	}

	return dp[n];
}

int main()
{
	int k;
	cin >> k >> n;

	for(int i = 0; i < n; i++)
		cin >> x[i];
	sort(x , x + n);

	n--;
	for(int i = 1; i <= n; i++)
		a[i] = x[i] - x[i - 1];

	ll l = -1e10 , r = 1e10;

	while(l <= r)
	{
		ll m = (l + r) / 2;

		auto t = f(m);
		if(t.second > k)
			l = m + 1;
		else
			r = m - 1;
	}

	auto t = f(l);
	cout << t.first - k * l << endl;

}