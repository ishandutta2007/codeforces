#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 400000;
int n, t[MX], p[MX], sig[MX], cn = 0, mod = 1e9+7;
string s;
set<int> st;
ll res = 2;

ii query (int x) {
	ii r;
	auto it = st.upper_bound(x);
	
	if (it != st.end()) r.se = *it;
	else r.se = 1e9;

	if (it != st.begin()) {
		it--;
		if (it != st.begin()) it--, r.fi = *it;
		else r.fi = 0;
	} else r.fi = 0;

	return r;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> p[i];
		if (s == "ADD") t[i] = 0;
		else t[i] = 1;
		cn += t[i];
	}

	if (!cn) {
		cout << n+1 << endl;
		return 0;
	}

	sig[n] = -1;
	for (int i = n-1; i >= 0; i--)
		if (t[i+1]) sig[i] = i+1;
		else sig[i] = sig[i+1];

	int i = 0;
	while (!t[i]) st.insert(p[i++]);

	while (1) {
		int a, b;
		tie(a, b) = query(p[i]);

		if (sig[i] == -1) {
			int cn = 1;

			i++;
			while (i < n) {
				if (a < p[i] && p[i] < b) cn++;
				i++;
			}

			res = res * cn % mod;
			break;
		}

		if (a < p[sig[i]] && p[sig[i]] < b) res *= 2;
		else if (p[sig[i]] < a || b < p[sig[i]]) res = 0;
		res %= mod;

		st.erase(p[i]);
		i++;
		while (!t[i]) st.insert(p[i++]);
	}

	cout << res << endl;

	return 0;
}