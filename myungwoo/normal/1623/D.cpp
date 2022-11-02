#include <bits/stdc++.h>
using namespace std;

using lld = long long;

const int MOD = (int)1e9 + 7;

struct Int {
	Int(int v = 0): v(v%MOD) {}
	Int(lld v): v(v%MOD) {}
	int v;
	friend Int operator + (const Int& lhs, const Int& rhs) {
		return Int((lhs.v+rhs.v)%MOD);
	}
	friend Int operator - (const Int& lhs, const Int& rhs) {
		return Int((lhs.v-rhs.v+MOD)%MOD);
	}
	friend Int operator * (const Int& lhs, const Int& rhs) {
		return Int(((lld)lhs.v*rhs.v)%MOD);
	}
	friend Int operator / (const Int& lhs, const Int& rhs) {
		return Int(((lld)lhs.v*rhs.pow(MOD-2))%MOD);
	}
	int pow(int m) const {
		int ret = 1, v = this->v;
		for (;m;m>>=1,v=(lld)v*v%MOD) if (m&1) ret = (lld)ret*v%MOD;
		return ret;
	}
};

void solve()
{
	int N, M, r, c, y, x;
	Int p;
	cin >> N >> M >> r >> c >> y >> x >> p.v;
	p = 1 - p/100;
	int dr = -1, dc = -1, ir = r, ic = c;
	if (r+dr < 1 || r+dr > N) dr *= -1;
	if (c+dc < 1 || c+dc > M) dc *= -1;
	int idr = dr, idc = dc;
	Int a = 0, b = 1;
	for (;;){
		r += dr; c += dc;
		a = a+1;
		if (r == y || c == x){
			a = a*p;
			b = b*p;
		}
		if (r+dr < 1 || r+dr > N) dr *= -1;
		if (c+dc < 1 || c+dc > M) dc *= -1;
		if (r == ir && c == ic && dr == idr && dc == idc) break;
	}
	cout << (a/(1-b)).v << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}