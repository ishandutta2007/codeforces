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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, k, no;
string s;
set<int> a, b;

int del (int l, int r, set<int> &b) {
	vi se;

	if (b.size()) {
		if (*b.begin() < l || r < *b.begin()) {
			se.pb(*b.begin());
		} else {
			auto it = b.upper_bound(r);
			if (it != b.end()) se.pb(*it);
		}

		if (*b.rbegin() < l || r < *b.rbegin()) {
			se.pb(*b.rbegin());
		} else {
			auto it = b.lower_bound(l);
			if (it != b.begin()) {
				it--;
				se.pb(*it);
			}
		}
	}

	if (se.empty()) {
		cout << "tokitsukaze" << endl;
		exit(0);
	}

	return se.back() - se[0] + 1 > k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> s;

	forn (i, n) (s[i] == '0' ? a : b).insert(i);

	for (int i = 0; i + k <= n; i++) {
		no += del(i, i + k - 1, b);
		no += del(i, i + k - 1, a);
	}

	if (no) cout << "once again" << endl;
	else cout << "quailty" << endl;

	return 0;
}