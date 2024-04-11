#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct SW {
	deque< pair<ll, int> > pq;

	void push (ll x, int i) {
		while (pq.size() && pq.back().fi >= x)
			pq.pop_back();
		pq.emplace_back(x, i);
	}

	ll query (int i) {
		while (pq.size() && pq.front().se < i)
			pq.pop_front();
		if (pq.size())
			return pq.front().fi;
		return 1e18;
	}
};

int n, a, b, c, d, st, ln;
ll t[300005], ab[300005], cd[300005];
SW sw;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> a >> b >> c >> d >> st >> ln; 

	ab[0] = cd[0] = st;
	t[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> st;
		
		ab[i] = ab[i-1];
		cd[i] = cd[i-1];
		if (st) {
			ab[i] += a;
			cd[i] += c;
		} else {
			ab[i] -= b;
			cd[i] -= d;
		}
	}

	int i = 0, j = 0;

	while (j <= n && t[j] < ln) {
		sw.push(cd[j], t[j]);
		j++;
	}

	if (sw.query(0) >= 0) {
		cout << 0 << endl;
		return 0;
	}

	while (i <= n) {
		if (ab[i] < 0) {
			cout << -1 << endl;
			return 0;
		}

		while (j <= n && t[j] <= t[i] + ln) {
			sw.push(cd[j], t[j]);
			j++;
		}

		ll x = sw.query(t[i]+1) - cd[i] + ab[i];
		if (x >= 0) {
			cout << t[i]+1 << endl;
			return 0;
		}
		i++;
	}

	cout << -1 << endl;

	return 0;
}