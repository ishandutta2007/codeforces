#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define MAXN 200000

ll mod = pow(10, 9) + 7;
ll modexp = mod - 1; // mod is a prime

ll powmod(ll b, ll e, ll m)
{
	ll r = 1;
	while (e) {
		if (e & 1) {
			r = (r * b) % m;
		}
		b = (b * b) % m;
		e >>= 1;
	}
	return r;
}

// return y : xy = 1 mod p
ll inverse(ll x, ll p)
{
	return powmod(x, p - 1, p);
}

int expcnt[MAXN + 1] = {};

ll lprod[MAXN + 1], rprod[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	cin >> n;
	while (n--) {
		cin >> p;
		expcnt[p]++;
	}

	vii data;
	for (int i = 0; i <= MAXN; i++) {
		if (expcnt[i] > 0) {
			data.push_back(make_pair(i, expcnt[i]));
//			cerr << i << ": " << expcnt[i] << endl;
		}
	}
	int ndata = data.size();

	fill_n(lprod, MAXN + 1, 1);
	fill_n(rprod, MAXN + 1, 1);

	lprod[0] = rprod[ndata] = 1;
	for (int i = 0; i < ndata; i++) {
		lprod[i + 1] = ((data[i].second + 1) * lprod[i]) % modexp;
	}
	for (int i = ndata; i--; ) {
		rprod[i] = ((data[i].second + 1) * rprod[i + 1]) % modexp;
	}

//	for (int i = 0; i <= ndata; i++) {
//		cerr << lprod[i] << " " << rprod[i] << endl;
//	}

	ll ans = 1;
	for (int i = 0; i < ndata; i++) {
		ll pow = 1LL * data[i].second * (data[i].second + 1) / 2;
		pow %= modexp;
		ll extrapow = (lprod[i] * rprod[i + 1]) % modexp;
		ll exp = (pow * extrapow) % modexp;

		ans = (ans * powmod(data[i].first, exp, mod)) % mod;
	}
	cout << ans << endl;
    return 0;
}