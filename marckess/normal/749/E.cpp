#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], q[MX];
ll ft[MX];
ld res = 0;

void reset () {
	memset(ft, 0, sizeof(ft));
}

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

ll query (int i) {
	ll sum = 0;
	while (i) {
		sum += ft[i];
		i -= i & -i;
	}
	return sum;
}

ll query (ll a, ll b) {
	return query(b) - query(a-1);
}

ld sum_n (ll n) {
	return n * (n + 1) / 2;
}

ld sum_n2 (ll n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

ld obtInv () {
	ll res = 0;
	reset();

	for (int i = 0; i < n; i++) {
		res += query(a[i], n);
		update(a[i], 1);
	}

	return res;
}

ld obtSumSeg () {
	ll res = 0;
	reset();

	for (int i = 0; i < n; i++) {
		res += query(a[i], n) * (n - i);
		update(a[i], i + 1);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	res = (-sum_n(n) + (n + 2) * (sum_n2(n) / sum_n(n)) + (-n - 1)) / 4.0L;
	res += obtInv();
	res -= obtSumSeg() / sum_n(n);

	cout << fixed << setprecision(11) << res << endl;

	return 0;
}