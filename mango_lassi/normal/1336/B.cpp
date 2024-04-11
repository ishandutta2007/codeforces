#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 4 * (ll)1e18;

bool bnd(int a, int b, int c) {
	return a <= b && b <= c;
}

ll offer(const vector<int>& va, const vector<int>& vb, const vector<int>& vc) {
	int na = va.size(), nb = vb.size(), nc = vc.size();
	int ia = -1, ib = 0, ic = 0;
	ll res = INF;
	for (; ib < vb.size(); ++ib) {
		while(ia+1 < na && va[ia+1] <= vb[ib]) ++ia;
		while(ic < nc && vc[ic] < vb[ib]) ++ic;
		if (bnd(0, ia, na-1) && bnd(0, ic, nc-1)) {
			ll a = va[ia], b = vb[ib], c = vc[ic];
			ll off = 2*(a*a + b*b + c*c - a*b - b*c - c*a);
			if (off < res) res = off;
		}
	}
	return res;
}

void solve() {
	// minimise (x - y)^2 + (y - z)^2 + (z - x)^2
	// = 2(x^2 + y^2 + z^2 - xy - yz - zx)
	// dx: 2x - y - z
	// -> If we know the middle value, the lower and upper want to be as close to it as possible

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> va(n), vb(m), vc(k);
	for (int& v : va) cin >> v;
	for (int& v : vb) cin >> v;
	for (int& v : vc) cin >> v;
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	sort(vc.begin(), vc.end());

	ll res = INF;
	res = min(res, offer(va, vb, vc));
	res = min(res, offer(va, vc, vb));
	res = min(res, offer(vb, va, vc));
	res = min(res, offer(vb, vc, va));
	res = min(res, offer(vc, va, vb));
	res = min(res, offer(vc, vb, va));
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; ++t) solve();
}