#include <bits/stdc++.h>
#include <random>

using namespace std;

int64_t power(int64_t a, int64_t b, int64_t p)
{
	if (!b) return 1;
	int64_t t = power(a, b>>1, p);
	t = t * t % p;
	if (b & 1) t = t * a % p;
	return t;
}

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rd(0);

int main()
{
	
	int n;
	scanf("%d", &n);
	vector<int64_t> h(n);
	for (int i = 0; i < n; ++i) h[i] = rd();
	vector<tuple<int, int, int>> v, w;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		v.push_back({ a, b, i });
		w.push_back({ c, d, i });
	}

	auto go = [&](vector<tuple<int, int, int>>&v)
	{
		vector<int64_t> r(n);
		vector<int> p;
		for (int i = 0; i < n; ++i)
		{
			auto [a, b, id] = v[i];
			p.push_back(a);
			p.push_back(b);
		}
		sort(p.begin(), p.end());
		vector<int64_t> x(2 * n + 4), y(2 * n + 4);
		for (int i = 0; i < n; ++i)
		{
			auto &[a, b, id] = v[i];
			a = lower_bound(p.begin(), p.end(), a) - p.begin()+1;
			b = lower_bound(p.begin(), p.end(), b) - p.begin()+1;
			x[a] ^= h[id];
			y[b] ^= h[id];
		}
		for (int i = 1; i <= 2 * n + 3; ++i) y[i] ^= y[i - 1];
		for (int i = 2 * n + 2; i >= 0; --i) x[i] ^= x[i + 1];
		for (auto [a, b, id] : v)
		{
			r[id] = y[a - 1] ^ x[b + 1];
		}
		return r;
	};

	auto a = go(v);
	auto b = go(w);
	if (a != b)
		puts("NO");
	else
		puts("YES");

	return 0;
}