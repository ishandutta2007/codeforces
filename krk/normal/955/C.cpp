#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll Inf = 1000000000000000000ll;

int q;
vector <ll> seq;

ll Sqrt(ll x)
{
	ll res = ll(sqrt(ld(x)));
	while ((res + 1) * (res + 1) <= x) res++;
	while (res * res > x) res--;
	return res;
}

bool Square(ll x) 
{
	ll g = Sqrt(x);
	return g * g == x;
}

int main()
{
	for (ll i = 2; i * i * i <= Inf; i++) {
		ll cur = i * i;
		while (cur <= Inf / i) {
			cur *= i;
			if (!Square(cur)) seq.push_back(cur); 
		}
	}
	sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
	scanf("%d", &q);
	while (q--) {
		ll lef, rig; scanf("%I64d %I64d", &lef, &rig);
		ll res = Sqrt(rig) - Sqrt(lef - 1);
		res += upper_bound(seq.begin(), seq.end(), rig) - lower_bound(seq.begin(), seq.end(), lef);
		printf("%I64d\n", res);
	}
	return 0;
}