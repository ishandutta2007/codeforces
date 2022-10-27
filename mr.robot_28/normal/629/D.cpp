#include <bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const double pi = 3.141592653589793;
vector <int> t;
vector <int> dp;
void update(int v, int l, int r, int ind)
{
	if(l == r)
	{
		t[v] = dp[ind];
	}
	else
	{
		if(ind <= (r + l) / 2)
		{
			update(v * 2, l, (r + l) / 2, ind);
		}
		else
		{
			update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
		}
		t[v] = max(t[v * 2], t[v * 2 + 1]);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(al <= l && r <= ar)
	{
		return t[v];
	}
	else if(l <= ar && r >= al)
	{
		return max(ans(v * 2, l, (r + l) / 2, al, ar), ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	else
	{
		return 0;
	}
}
bool cmp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
	if(a.first.first * a.first.first * a.first.second == b.first.first * b.first.first * b.first.second)
	{
		return a.second > b.second;
	}
	return a.first.first * a.first.first * a.first.second < b.first.first *b.first.first * b.first.second;
}
signed main()
{
	int n;
	cin >> n;
	dp.resize(n);
	t.resize(4 * n, 0);
	vector <pair <pair <int, int> , int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first.first >> A[i].first.second;
		A[i].second = i;
	}
	sort(A.begin(), A.end(), cmp);
	for(int i = 0; i < n; i++)
	{
		int f = ans(1, 0, n - 1, 0, A[i].second);
		dp[A[i].second] = f + A[i].first.first * A[i].first.first * A[i].first.second;
			update(1, 0, n - 1, A[i].second);
	}
	double ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(pi * dp[i] > ans)
		{
			ans = pi * dp[i];
		}
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}