#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define REP(i, n) rep(i, 0, n)
#define rs resize
#define all(v) (v).begin(), (v).end()

ll pow(ll b, ll e)
{
	ll r = 1;
	while (e--) r *= b;
	return r;
}

int compare(ll A, ll B) {
	return A == B ? 0 : 
		A < B ? -1 : 1;
}

int run() {
	ll x, y;
	cin >> x >> y;

	// note: signum(x^y - y^x) = signum(x^y (1 - x^y y^{-x}))
	// 	   = signum(1 - x^y y^-x)
	// 	   = signum(1 - e^( y log x - x log y))
	// 	   = signum( x log y - y log x )


	// compare:
	// x^y - y^x    <0, =0,>0 ?
	// e^(y log x) - e^(x log y)

	// x^y / y^x = e^( y log x - x log y )    <1,=1,>1 ?
	//
	// y log x - x log y   <0,=0,>0 ?
	//
	// <=> y log x <=> x log y
	// <=> log x / x <=> (log y) / y

	if (x == y) return 0;
	if (x == 1) return -1;  // 1^y = 1 < y^1
	if (y == 1) return 1;

	if (x == 2) {
		// 2^y <? y^2
		// y = 3: 2^3 = 8 <? 9 = 3^2, yes
		if (y == 3) return -1;
		if (y == 4) return 0;
		return 1;
	} else if (y == 2) {
		if (x == 3) return 1;
		if (x == 4) return 0;
		return -1;
	}
/*
	ld lhs = logl(x) * y;
	ld rhs = logl(y) * x;

	if (abs(lhs - rhs) > 1e-10) {
		if (lhs < rhs) return -1;
		else return 1;
	}

	if (x < 12 && y < 12) {
		return compare(pow(x, y), pow(y, x));
	}
*/

	return x < y ? 1 : -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
/*
	for (ll A = 1; A <= 20; A++) {
		for (ll B = 1; B <= 20; B++) {
			ll retA = 1, retB = 1;
			REP(i, B) retA *= A;
			REP(i, A) retB *= B;
			ll ans = retA - retB;
			if (ans < -1) ans = -1;
			if (ans > 1) ans = 1;

			if (ans >= 0) cout << " ";
			cout << ans << " ";
		}
		cout << endl;
	}
*/
	int ans = run();
	if (ans == 0) cout << "=";
	else if (ans == 1) cout << ">";
	else cout << "<";
	cout << endl;

	return 0;
}