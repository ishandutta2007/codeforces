#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define ABIG 1
#define BBIG -1
int main() {
	ios_base::sync_with_stdio(false);
	string a,b; cin >> a; cin >> b;
	bool opp = false;
	if (b.length() > a.length()) {
		swap(a,b); opp = true;
	}
	ll alen = a.length();
	ll blen = b.length();
	ll n = alen;
	ll d = alen - blen;
	assert(d>=0);
	ll ans = 0;
	for (ll i = 0; i < d; i++) {
		if (a[i] != '0') {
			ans = ABIG;
		}
	}
	for (ll i = 0; i < blen; i++) {
		if (ans != 0) break;
		if (a[d+i] > b[i]) {
			ans = ABIG;
		}
		else if (a[d+i] < b[i]) {
			ans = BBIG;
		}
	}
	if (opp) ans *= -1;
	if (ans == ABIG) {
		cout << ">" << endl;
	}
	else if (ans == BBIG) {
		cout << "<" << endl;
	}
	else if (ans == 0) {
		cout << "=" << endl;
	}
	else {
		assert(false);
	}
}