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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, a[MX], b[MX];

void main_() {
	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	
	vii res;
	forn (kk, n + 1) {
		forn (i, n - 1) {
			if (ii(a[i], b[i]) > ii(a[i + 1], b[i + 1])) {
				res.pb({i + 1, i + 2});
				swap(a[i], a[i + 1]);
				swap(b[i], b[i + 1]);
			}
		}
	}
	
	if (is_sorted(a, a + n) && is_sorted(b, b + n)) {
		cout << res.size() << endl;
		for (ii p : res)
			cout << p.fi << " " << p.se << endl;
	} else {
		cout << -1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}