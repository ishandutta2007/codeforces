#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

const int MAXN = (int)1e5 + 10;

int wut[MAXN];
int dp[MAXN];
int doit(const vector<int>& ar)
{
	int n = sz(ar);
	memset(wut, 127, (n + 1) * 4);
	memset(dp, 0, n * 4);
	wut[0] = -1;
	int res = 0;
	For(i, n)
	{
		auto it = lower_bound(wut, wut + n + 1, ar[i]);
		dp[i] = it - wut;
		res = max(res, dp[i]);
		if (wut[dp[i] - 1] < ar[i] && ar[i] < wut[dp[i]])
			wut[dp[i]] = ar[i];
		//wut[dp[i]] = min(wut[dp[i]], ar[i]);
	}
	return res;
}

bool marked[MAXN];
vector<vector<int>> ans;
void cut(vector<int>& ar, int res)
{
	ans.emplace_back();
	memset(marked, 0, sz(ar));
	int cur;
	for (cur = 0; dp[cur] < res; ++cur);
	marked[cur] = true;
	ans.back().push_back(ar[cur]);
	while (dp[cur] > 1)
	{
		int prv = cur;
		while (ar[prv] > ar[cur] || dp[prv] != dp[cur] - 1)
			--prv;
		marked[prv] = true;
		cur = prv;
		ans.back().push_back(ar[cur]);
	}
	reverse(all(ans.back()));
	int j = 0;
	For(i, sz(ar))
	{
		if (marked[i])
			continue;
		ar[j] = ar[i];
		++j;
	}
	ar.resize(j);
}

int expected[MAXN];

void solve()
{
	ans.clear();
	int n;
	cin >> n;
	vector<int> ar(n);
	For(i, n)
	{
		cin >> ar[i];
		--ar[i];
	}
	while (!ar.empty())
	{
		int done = doit(ar);
		if (done > expected[sz(ar)])
		{
			cut(ar, done);
			continue;
		}
		int old_size = sz(ans);
		ans.resize(old_size + done);
		For(i, sz(ar))
			ans[old_size + dp[i] - 1].push_back(ar[i]);
		break;
	}
	if (sz(ans) > expected[n])
		throw;
	cout << sz(ans) << '\n';
	for (auto e : ans)
	{
		cout << sz(e);
		for (auto f : e)
			cout << ' ' << f + 1;
		cout << '\n';
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	for (int i = 1; i * (i + 1) / 2 < MAXN; ++i)
		expected[i * (i + 1) / 2] = i;
	for (int i = 1; i < MAXN; ++i)
		expected[i] = max(expected[i], expected[i - 1]);
	int t;
	cin >> t;
	For(test, t)
		solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}