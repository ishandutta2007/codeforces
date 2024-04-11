#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<ll> vll;
typedef pair<ll, ll> pll; typedef complex<ll> cll;
#define all(x) begin(x), end(x)
#define pb push_back
template<class A> void addlog( A a ) { cerr << a << endl; }
template<class A, class... B> void addlog( A a, B... b )
{ cerr << a << ' '; addlog(b...); }
#define  REP(i, b, e) for (int i=int(b); i<=int(e); ++i)
#define BREP(i, b, e) for (int i=int(e); i>=int(b); --i)


string c;
ll s = 0, h = 0;


int main () {
	ll N; cin >> N;
	REP (i, 1, N) {
		cin >> c; cin >> c;
		if (c == "soft") ++ s;
		else if (c == "hard") ++ h;
		else assert(false);
	}
	if (s < h) swap(s, h);
	assert(h <= s);
	
	REP (n, 1, 100) {
		ll ms = (n * n + 1) / 2;
		ll mh = (n * n) / 2;
		if (s <= ms && h <= mh) {
			cout << n << endl;
			return 0;
		}
	} assert(false);
	
	return 0;
}