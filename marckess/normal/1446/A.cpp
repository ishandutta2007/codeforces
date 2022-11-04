#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
vii a;
ll w;

void solve () {
	cin >> n >> w;
	a.clear();
	forn (i, n) {
		int x;
		cin >> x;
		a.emplace_back(x, i + 1);
	}
	sort(all(a));
	forn (i, n) if ((w + 1) / 2 <= a[i].fi && a[i].fi <= w) {
		cout << 1 << endl << a[i].se << endl;
		return;
	}
	ll s = 0;
	forn (i, n) {
		s += a[i].fi;
		if ((w + 1) / 2 <= s && s <= w) {
			cout << i + 1 << endl;
			forn (j, i + 1)
				cout << a[j].se << " ";
			cout << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
		
	return 0;
}