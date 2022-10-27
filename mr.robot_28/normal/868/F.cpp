#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int inf = 1e18;
vector <int> a(1e5 + 5);
vector <int> dp(1e5 + 5, inf);
int L = 0;
int R = 0;
int c = 0;
vector <int> data1(1e5 + 5, 0);
void erase(int x)
{
	c -= (--data1[a[x]]);
}
void add(int x)
{
	c += data1[a[x]]++;
}
int cost(int l, int r)
{
	while (r > R)
	{
		add(++R);
	}
	while (r < R)
	{
		erase(R--);
	}
	while (l < L)
	{
		add(--L);
	}
	while (L < l)
	{
		erase(L++);
	}
	return c;
}
int min(int a, int b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}
void compute(vector <int>& temp, int l, int r, int optl, int optr)
{
	if (r < l)
	{
		return;
	}
	int midd = (r + l) / 2;
	int ans = inf;
	int opt = optl;
	for (int k = min(optr, midd); k >= optl; k--)
	{
		if (dp[k - 1] + cost(k, midd) <= ans)
		{
			opt = k;
			ans = dp[k - 1] + cost(k, midd);
		}
	}
	temp[midd] = ans;
	compute(temp, l, midd - 1, optl, opt);
	compute(temp, midd + 1, r, opt, optr);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	data1[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dp[0] = 0;
	for (int i = 0; i < k; i++)
	{
		vector <int> temp(1e5 + 5, inf);
		compute(temp, 1, n, 1, n);
		swap(temp, dp);
	}
	cout << dp[n];
	return 0;
}