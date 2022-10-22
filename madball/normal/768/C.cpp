#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e+9 + 7;
const ld eps = 1e-7;

#ifdef LOCAL
//#define STRESS
#endif

vector<int> nextar;
void change(vector<int> &ar, int x, int odd)
{
	fill(nextar.begin(), nextar.end(), 0);
	int cnt = odd;
	for (int i = 0; i < ar.size(); ++i)
	{
		int take = ar[i] / 2;
		if ((cnt & 1) == 0)
			take += ar[i] % 2;
		nextar[i ^ x] += take;
		nextar[i] += ar[i] - take;
		cnt += ar[i];
	}
	copy(nextar.begin(), nextar.end(), ar.begin());
	fill(nextar.begin(), nextar.end(), 0);
}

pair<int, int> mm(vector<int> const &ar)
{
	pair<int, int> res(-1, -1);
	for (int i = 0; i < ar.size(); ++i)
		if (ar[i])
		{
			res.second = i;
			if (res.first == -1)
				res.first = i;
		}
	return res;
}

bool eq(vector<int> const &a, vector<int> const &b)
{
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); ++i)
		if (a[i] != b[i])
			return false;
	return true;
}

const int STEPS = 1000;

pair<int, int> doit(vector<int> ar, int x, int step, int k, int odd)
{
	nextar.resize(step);
	for (int j = min(k, STEPS); j; --j, --k)
		change(ar, x, odd);
	if (k == 0)
		return mm(ar);
	pair<int, int> once = mm(ar);
	vector<int> prv(ar.begin(), ar.end());
	int t = 0;
	for (int j = 0; j < STEPS && k > 0; ++j)
	{
		change(ar, x, odd);
		--k;
		++t;
		if (eq(ar, prv))
		{
			k %= t;
			while (k--)
			{
				change(ar, x, odd);
			}
			return mm(ar);
		}
	}
	if (k == 0)
		return mm(ar);
	int cnt = 16;
	for (int i = 0; cnt > 8 && i < step; ++i)
		for (; cnt > 8 && ar[i] > 0; --ar[i], --cnt)
		{
			++nextar[i];
		}
	for (int i = step - 1; cnt > 0 && i >= 0; --i)
		for (; cnt > 0 && ar[i] > 0; --ar[i], --cnt)
		{
			++nextar[i];
		}
	copy(nextar.begin(), nextar.end(), ar.begin());
	fill(nextar.begin(), nextar.end(), 0);
	once = mm(ar);
	prv = vector<int>(ar.begin(), ar.end());
	t = 0;
	for (int j = 0; j < STEPS && k > 0; ++j)
	{
		change(ar, x, odd);
		--k;
		++t;
		if (eq(ar, prv))
		{
			k %= t;
			while (k--)
			{
				change(ar, x, odd);
			}
			return mm(ar);
		}
	}
	if (k == 0)
		return mm(ar);
	throw;
}

int ar[100500];
vector<int> low;
vector<int> hoi;
void solve()
{
	int n, k, x;
	int mi, ma;
	scanf("%d %d %d", &n, &k, &x);
	for (int i =0 ; i < n; ++i)
	{
		scanf("%d",&ar[i]);
		if (i == 0)
			mi = ma = ar[i];
		mi = min(mi, ar[i]);
		ma = max(ma, ar[i]);
	}
	int step;
	for (step = 1; step <= x; step *= 2);
	low.resize(step, 0);
	hoi.resize(step, 0);
	int mil = mi - mi % step;
	int mal = ma - ma % step;
	int odd = 0;
	for (int i = 0; i < n; ++i)
	{
		if (mil <= ar[i] && ar[i] < mil + step)
			++low[ar[i] % step];
		if (mal <= ar[i] && ar[i] < mal + step)
			++hoi[ar[i] % step];
		if (ar[i] < mal)
			++odd;
	}
	pair<int, int> mm1 = doit(low, x, step, k, 0);
	pair<int,int> mm2 = doit(hoi, x, step, k, odd);
	printf("%d %d", mal + mm2.second, mil + mm1.first);
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