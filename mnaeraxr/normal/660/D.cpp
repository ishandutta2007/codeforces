#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

typedef long long ll;
typedef complex<ll> point;

namespace std
{
	bool operator<(const point &p, const point &q)
	{
		if (p.real() != q.real())
			return p.real() < q.real();
		return p.imag() < q.imag();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<point> P(n);
	vector<pair<point, point>> Q;

	for (int i = 0; i < n; ++i)
	{
		ll x, y;
		cin >> x >> y;

		P[i] = point(x, y);

		for (int j = 0; j < i; ++j)
		{
			point p = P[i] + P[j], q = P[i] - P[j];

			if (q.imag() < 0 || (q.imag() == 0 && q.real() < 0))
				q = q * point(-1, 0);

			ll d = __gcd(abs(q.real()), abs(q.imag()));
			q /= d;

			Q.push_back({p, q});
		}
	}

	sort(Q.begin(), Q.end());

	ll ans = 0;

	for (int i = 0, j, k; i < Q.size(); i = j)
		for (j = i; j < Q.size() && Q[j].first == Q[i].first; j = k)
		{
			for (k = j; k < Q.size() && Q[i].first == Q[k].first && Q[j].second == Q[k].second; ++k);

			ans += (ll) (j - i) * (k - j);
		}

	cout << ans << endl;

	return 0;
}