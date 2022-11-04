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

const int MX = 1005;
int n;
ii p[MX];
map<ii, int> mp;

ii operator - (ii a, ii b) {
	return {a.fi - b.fi, a.se - b.se};
}

ii f (ii a, ii b) {
	if (a > b) swap(a, b);
	b = b - a;
	int g = __gcd(b.fi, b.se);
	b.fi /= g;
	b.se /= g;
	return b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].fi >> p[i].se;

	for (int i = 0; i < n; i++) {
		set<ii> st;

		for (int j = i + 1; j < n; j++)
			st.insert(f(p[i], p[j]));
		for (int j = 0; j < i; j++)
			st.erase(f(p[i], p[j]));

		for (ii x : st)
			mp[x]++;
	}

	ll res = 0, acu = 0;
	for (auto &x : mp) {
		res += acu * x.se;
		acu += x.se;
	}

	cout << res << endl;

	return 0;
}