#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

struct event
{
	ll x, k; bool close;
	bool operator<(const event &o) const
	{
		return make_tuple(x, close, ((!close) ? k : (-k))) < make_tuple(o.x, o.close, ((!o.close) ? o.k : (-o.k)));
	}
};

struct st
{
	ll a, b, k;
};

int main()
{
	#ifdef DGC
		freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<event> e;
	for (ll a, b, k; n--; )
	{
		cin >> a >> b >> k;
		b -= k;
		e.push_back({ a, k, false });
		e.push_back({ b, k, true });
	}

	sort(e.begin(), e.end());

	ll last = -1;
	multiset<ll> s;
	vector<st> v;

	for (auto i : e)
	{
		if (s.empty()) last = i.x;
		ll mn = s.empty() ? (-1) : (*s.begin());
		if (!i.close) s.insert(i.k);
		if (i.close) s.erase(s.find(i.k));
		if (s.empty() || (mn != -1 && *s.begin() != mn))
			v.push_back({ last, i.x - (!i.close), mn }), last = i.x - (!i.close) + 1;
	}

	last = 0;
	ll ans = 0;
	for (auto i : v)
	{
		if (i.a + i.k <= last) --ans, last = i.a;
		else last = max(i.a, last);

		if (last <= i.b)
		{
			ll take = (i.b + i.k - last) / i.k;
			ans += take;
			last = last + i.k * take;
		}
	}

	cout << ans << "\n";

	return 0;
}