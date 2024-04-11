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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ii p[MX];

ii operator - (ii a, ii b) {
	return {a.fi - b.fi, a.se - b.se};
}

ll operator ^ (ii a, ii b) {
	return a.fi * b.se - a.se * b.fi;
}

int md (ii o, ii p, ii q) {
	ll f = (p - o) ^ (q - o);
	return f ? f / abs(f) : 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].fi >> p[i].se;
		p[i].se -= p[i].fi * p[i].fi;
	}
	sort(p, p + n, greater<ii>());
	n = unique(p, p+n, [&] (const ii &a, const ii &b) { return a.fi == b.fi; }) - p;
	sort(p, p + n);

	vii h = {p[0]};

	for (int i = 1; i < n; i++) {
		while (h.size() >= 2 && md(*(h.end() - 2), p[i], *(h.end() - 1)) <= 0) h.pop_back();
		h.push_back(p[i]);
	}

	cout << (int)h.size() - 1 << endl;

	return 0;
}