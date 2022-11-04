#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, ca, cb;
string s, t;
vi a, b;
vii res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s >> t;

	for (char c : s) {
		if (c == 'a') ca++;
		else cb++;
	}
	for (char c : t) {
		if (c == 'a') ca++;
		else cb++;
	}

	if (ca % 2 || cb % 2) {
		cout << -1 << endl;
		return 0;
	}

	ca = cb = 0;
	for (char c : s) ca += c == 'a';
	for (char c : t) cb += c == 'a';

	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (s[i] == 'a') a.pb(i);
			else b.pb(i);
		}
	}

	for (int i = 0; ca > cb; i += 2) {
		swap(s[a[i]], t[a[i+1]]);
		res.pb(a[i], a[i+1]);
		ca--, cb++;
	}

	for (int i = 0; cb > ca; i += 2) {
		swap(s[b[i]], t[b[i+1]]);
		res.pb(b[i], b[i+1]);
		ca++, cb--;
	}

	a.clear(), b.clear();

	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (s[i] == 'a') a.pb(i);
			else b.pb(i);
		}
	}

	for (int i = 0; i + 1 < a.size(); i += 2) {
		res.pb(a[i], a[i+1]);
		res.pb(b[i], b[i+1]);
	}

	if (a.size() & 1) {
		res.pb(a.back(), a.back());
		res.pb(a.back(), b.back());
	}

	cout << res.size() << endl;
	for (ii &x : res)
		cout << x.fi+1 << " " << x.se+1 << endl;

	return 0;
}