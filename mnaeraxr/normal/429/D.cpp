#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

typedef long long i64;
typedef complex<i64> point;

const i64 oo = 0x3f3f3f3f3f3f3f3f;

inline i64 sqr(i64 x) { return x * x; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<point> p(n);
	i64 sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		sum += a;
		p[i] = point(i, sum);
	}

	auto cmp = [](point a, point b)
	{
		return make_pair(a.imag(), a.real()) < make_pair(b.imag(), b.real());
	};

	set<point, decltype(cmp)> S(cmp);
	i64 ans = oo;
	int ptr = 0;

	for (int i = 0; i < n; ++i)
	{
		while (ptr < i && sqr(p[i].real() - p[ptr].real()) >= ans)
			S.erase(p[ptr++]);

		auto lo = S.lower_bound(point(-oo, p[i].imag() - sqrt(ans) - 1));
		auto hi = S.upper_bound(point(-oo, p[i].imag() + sqrt(ans) + 1));

		for (decltype(lo) it = lo; it != hi; ++it)
			ans = min(ans, norm(p[i] - *it));

		S.insert(p[i]);
	}

	cout << ans << endl;
	
	return 0;
}