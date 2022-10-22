#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXN = 200500;
const int INF = 1e+9 + 7;
const ld EPS = 1e-7;

#ifdef LOCAL
#define STRESS
#endif

const int POWS = 42;
ll pows[POWS];
ll ends[POWS];
ll rs[POWS];

void cut()
{
	for (int i = 1; i < POWS; ++i)
		if (pows[i] > pows[i - 1])
		{
			rs[i] += pows[i] - pows[i - 1];
			pows[i] = pows[i - 1];
		}
}

vector<int> ans;

void solve()
{
	int n;
#ifdef STRESS
	n = 100000;
#else
	scanf("%d", &n);
#endif
	for (int i = 0; i < n; ++i)
	{
		ll a;
#ifdef STRESS
		a = (ll)(1) << (i % 40);
#else
		scanf("%lld", &a);
#endif
		int j = 0;
		ll b;
		for (b = 1; b < a; b <<= 1) ++j;
		if (b == a)
			++pows[j];
		else
			++rs[j];
	}
	cut();
	for (int m = pows[0]; m > 0; --m)
	{
		if (pows[0] > m)
		{
			rs[0] += pows[0] - m;
			pows[0] = m;
		}
		cut();
		ll s1 = 0;
		ll s2 = 0;
		bool succ = true;
		for (int i = POWS - 1; succ && i >= -1; --i)
		{
			s2 += i == POWS - 1 ? 0 : rs[i + 1];
			if (i >= 0)
				s1 += pows[i] - (i == POWS - 1 ? 0 : pows[i + 1]);
			if (s2 > s1)
				succ = false;
		}
		if (succ)
			ans.push_back(m);
	}
	sort(ans.begin(), ans.end());
	if (ans.empty())
		printf("-1\n");
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}