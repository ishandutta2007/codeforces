// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m, k;

vii read (int n) {
	vii a;
	forn (i, n) {
		ll x, cn = 1;
		cin >> x;
		while (x % m == 0) {
			x /= m;
			cn *= m;
		}
		if (a.size() && a.back().fi == x) a.back().se += cn;
		else a.pb({x, cn});
	}
	return a;
}

void main_() {
	cin >> n >> m;
	vii a = read(n);
	
	cin >> k;
	vii b = read(k);
	
	if (a == b) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}