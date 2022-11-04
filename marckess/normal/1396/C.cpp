#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n;
ll r1, r2, r3, d, a[MX];
ll pre[MX], suf[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> r1 >> r2 >> r3 >> d;
	forn (i, n) cin >> a[i];

	forn (i, n) {
		if (i) pre[i] = pre[i - 1];

		pre[i] += min({
			a[i] * r1 + 2 * d + 2 * r1,
			a[i] * r1 + 0 * d + 1 * r3,
		           r2 + 2 * d + 1 * r1,
		});

		if (i >= 1) {
			ll x = i >= 2 ? pre[i - 2] : 0;

			x += min({
				a[i - 1] * r1 + 2 * r1,
				a[i - 1] * r1 + 1 * r3,
				           r2 + 1 * r1,
			})
			+ 2 * d
			+ min({
				a[i] * r1 + 2 * r1,
				a[i] * r1 + 1 * r3,
				       r2 + 1 * r1,
			});

			pre[i] = min(pre[i], x);
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		suf[i] = suf[i + 1];

		suf[i] += min({
			a[i] * r1 + 2 * r1 + (i + 1 == n ? 2 * d : 0),
			a[i] * r1 + 1 * r3,
			       r2 + 1 * r1 + (i + 1 == n ? 2 * d : 0),
		});
	}

	forn (i, n) suf[i] += d * (n - i - 1);

	suf[n - 2] -= suf[n - 1];
	suf[n - 2] += min({
			a[n - 1] * r1 + 2 * r1 + d,
			a[n - 1] * r1 + 1 * r3,
			           r2 + 1 * r1 + d,
		});

	ll res = suf[0];

	forn (i, n) res = min(res, pre[i] + suf[i + 1]);

	res += (n - 1) * d;

	cout << res << endl;

	return 0;
}