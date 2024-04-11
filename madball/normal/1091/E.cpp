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

int get_root(const vector<int>& ar)
{
	int root = 0;
	For(i, sz(ar))
		if (ar[i] >= i + 1)
			root = i + 1;
	return root;
}

vector<int> get_head(const vector<int>& ar)
{
	int root = get_root(ar);
	vector<int> res(root);
	For(i, root)
		res[i] = ar[i] - root + 1;
	return res;
}

vector<int> get_tail(const vector<int>& ar)
{
	int root = get_root(ar);
	vector<int> res(root);
	for (int i = sz(ar) - 1; i >= root; --i)
		res[ar[i] - 1] = max(res[ar[i] - 1], i - root + 1);
	for (int i = sz(res) - 2; i >= 0; --i)
		res[i] = max(res[i], res[i + 1]);
	return res;
}

bool check(const vector<int>& ar)
{
	auto head = get_head(ar);
	auto tail = get_tail(ar);
	lint bal = 0;
	For(i, sz(head))
	{
		bal += tail[i];
		bal -= head[i];
		if (bal < 0)
			return false;
	}
	return true;
}

bool check_with(const vector<int>& ar, int add)
{
	if (add == 0)
		return check(ar);
	vector<int> ar2(sz(ar));
	For(i, sz(ar))
		ar2[i] = ar[i];
	reverse(all(ar2));
	ar2.insert(lower_bound(all(ar2), add), add);
	reverse(all(ar2));
	return check(ar2);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> ar(n);
	For(i, n)
		cin >> ar[i];
	sort(all(ar));
	reverse(all(ar));
	while (!ar.empty() && ar.back() == 0)
	{
		ar.pop_back();
		--n;
	}
	lint s = 0;
	for (auto e : ar)
		s += e;
	int root = get_root(ar);
	vector<int> res;

#ifdef LOCAL1
	cout << root << '\n';
	for (auto e : get_head(ar))
		cout << e << ' ';
	cout << '\n';
	for (auto e : get_tail(ar))
		cout << e << ' ';
	cout << '\n';
	for (int i = s % 2; i <= n; i += 2)
		if (check_with(ar, i))
			cout << i << ' ';
	cout << '\n';
#endif

	int l = (s % 2) - 2;
	int r = root + ((s + root) % 2 ? 1 : 2);
	while (l + 2 < r)
	{
		int m = (r + l) / 2;
		if ((m + l) % 2)
			--m;
		if (check_with(ar, m))
			r = m;
		else
			l = m;
	}
	for (int i = r; i <= root; i += 2)
		res.push_back(i);

	l = root - ((s + root) % 2 ? 1 : 2);
	r = n + ((s + n) % 2 ? 1 : 2);
	while (l + 2 < r)
	{
		int m = (l + r) / 2;
		if ((m + l) % 2)
			--m;
		if (check_with(ar, m))
			l = m;
		else
			r = m;
	}
	for (int i = l; i >= root; i -= 2)
		res.push_back(i);
	sort(all(res));
	res.resize(unique(all(res)) - res.begin());
	for (auto e : res)
		cout << e << ' ';
	if (res.empty())
		cout << -1;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}