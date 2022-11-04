// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, x, a[MX], b[MX], pre[MX], suf[MX];

ll in (int i, int k) {
	ll p = 0;
	if (i < n) p += abs(a[i + 1] - k);
	if (i) p += abs(a[i] - k);
	if (i && i < n) p -= abs(a[i] - a[i + 1]);
	return p;
}

ll in (int i, int k, int l) {
	ll p = abs(k - l);
	if (i < n) p += abs(a[i + 1] - k);
	if (i) p += abs(a[i] - l);
	if (i && i < n) p -= abs(a[i] - a[i + 1]);
	return p;
}

void main_() {
	cin >> n >> x;
	
	ll acu = 0;
	forr (i, 1, n) {
		cin >> a[i];
		if (i > 1)
			acu += abs(a[i] - a[i - 1]);
	}
	
	ll a = 1e18, b = 1e18, c = 1e18, d = 1e18;
	forn (i, n + 1) {
		a = min(a, in(i, 1));
		b = min(b, in(i, x));
		c = min(c, in(i, 1, x));
		d = min(d, in(i, x, 1));
	}
	
	if (x == 1) cout << acu + a << endl;
	else cout << acu + min({a + b, c, d}) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}