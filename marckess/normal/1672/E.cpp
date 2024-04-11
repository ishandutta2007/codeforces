// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

// #define endl '\n'
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

const int MX = 2005;
int n;

int query (int w) {
	if (w < 1) return 1e9;
	cout << "? " << w << endl;
	int r;
	cin >> r;
	if (!r) r = 1e9;
	return r;
}

void main_() {
	cin >> n;
	
	int i = 1, j = n * 2001, rep = 23;
	while (rep--) {
		int m = (i + j) / 2;
		if (query(m) == 1) j = m;
		else i = m;
	}
	
	ll res = j;
	for (int i = 2; i <= n; i++) {
		int w = j / i;
		int r = query(w);
		res = min(res, 1ll * r * w);
	}
	
	cout << "! " << res << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}