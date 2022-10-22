#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int Q;
vector <ll> S;
ld res;

ld Get(ll x, int ind)
{
	return (ll(ind) * x - S[ind]) / ld(ind + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> Q;
	S.push_back(0);
	int pnt = 0;
	while (Q--) {
		int typ, x; cin >> typ;
		if (typ == 1) {
			cin >> x;
			while (pnt + 1 < S.size() && Get(x, pnt + 1) >= Get(x, pnt)) pnt++;
			res = max(res, Get(x, pnt));
			S.push_back(S.back() + x);
		} else cout << fixed << setprecision(10) << res << endl;
	}
	return 0;
}