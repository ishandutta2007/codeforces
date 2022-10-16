#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second
 
namespace std
{
	bool operator<(point a, point b)
	{
		if (a.real() != b.real())
			return a.real() < b.real();
		return a.imag() < b.imag();
	}
}
 
pair<ld, point> f(int x, int h1, int h2)
{
	int hm = min(h1, h2);
	int hM = max(h1, h2);
	point a = { x, hm };
	point b = { x+1, hm };
	point c = { h1 > h2 ? x : x + 1, hM };
	point d = { x + 0.5L, hm / 2.0L };
 
	return { hm + (max(h1, h2) - hm) / 2.0L,
		((a + b + c) / 6.0L + d * (ld)hm) / (0.5L + hm) };
}
 
ll ro(ld x)
{
	return roundl(x * 1e7);
}
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
 
	int n; ld x, y;
	cin >> n >> x >> y;
	point pp = { x, y };
 
	int B = n / 2, A = n - B;
 
	vector<vector<pair<point, int>>> mp(20);
	for (int i = 0; i < 1 << B; ++i)
	{
		int s = 0;
		ld a, ra = 0; point p, rp = {0, 0};
		for (int j = B - 1; j >= 0; --j)
		{
			int s2 = s + ((i >> j & 1) ? -1 : +1);
			if (s2 < 0) { s = s2; break; }
			tie(a, p) = f(A + j, s2, s);
			rp = (a * p + ra * rp) / (a + ra);
			ra += a;
			s = s2;
		}
		if (s < 0) continue;
		mp[s].push_back({ ra * (pp - rp), i });
	}
 
	for (auto &i : mp)
	{
		for (auto &j : i)
			j.F = { ro(real(j.F)), ro(imag(j.F)) };
		sort(i.begin(), i.end());
	}
 
	for (int i = 0; i < 1 << A; ++i)
	{
		int s = 0;
		ld a, ra = 0; point p, rp = {0, 0};
		for (int j = 0; j < A; ++j)
		{
			int s2 = s + ((i >> j & 1) ? +1 : -1);
			if (s2 < 0) { s = s2; break; }
			tie(a, p) = f(j, s, s2);
			rp = (a * p + ra * rp) / (a + ra);
			ra += a;
			s = s2;
		}
		if (s < 0) continue;
		auto pt = ra * (rp - pp);
		pt = { ro(real(pt)), ro(imag(pt)) };
		auto it = lower_bound(mp[s].begin(), mp[s].end(), make_pair(pt, 0));
		if (it < mp[s].end() && it->F == pt)
		{
			string ans = "";
			for (int j = 0; j < A; ++j)
				ans += (i >> j & 1) ? '(' : ')';
			for (int j = 0; j < B; ++j)
				ans += (it->S >> j & 1) ? '(' : ')';
			cout << ans << "\n";
			return 0;
		}
	}
 
	return 0;
}