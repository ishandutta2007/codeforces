#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll mod = 1ll << 60;
int q;
ll off[66];

int lvl (ll n) {
	ll p = 0;
	for (int i = 0; i < 60; i++)
		if (n & (1ll << i))
			p = i;
	return p;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> q;
	while (q--) {
		int op;
		ll t, x, k;
		cin >> op;

		if (op == 1) {
			cin >> x >> k;
			int in = lvl(x);

			(off[in] += k) %= mod;
		} else if (op == 2) {
			cin >> x >> k;
			int in = lvl(x);

			while (in < 60) {
				(off[in] += k) %= mod;
				(k *= 2) %= mod;
				in++;
			}
		} else {
			cin >> x;
			int in = lvl(x);
			queue<ll> st;

			ll pos = x - (1ll << in);
			pos = MOD(pos + off[in], 1ll << in);
			x = MOD((1ll << in + 1) + pos, 1ll << in);

			while (in >= 0) {
				ll pos = x - (1ll << in);
				pos = MOD(pos - off[in], 1ll << in);
				st.push((1ll << in) + pos);
				x /= 2;
				in--;
			}

			while (st.size()) {
				cout << st.front() << " ";
				st.pop();
			}
			cout << endl;
		}
	}

	return 0;
}