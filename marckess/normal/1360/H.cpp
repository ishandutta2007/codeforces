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

const int MX = 105;
int n, m;
ll a[MX];

ll f (ll k) {
	ll idx = k;
	forn (i, n) if (a[i] < k) idx--;
	return idx;
}

string imp (ll k) {
	string s;
	while (k) {
		s.pb(k % 2 + '0');
		k /= 2;
	}
	while (s.size() < m) s.pb('0');
	reverse(all(s));
	return s;
}

void solve () {
	cin >> n >> m;

	forn (i, n) {
		string s;
		cin >> s;
		a[i] = stoll(s, 0, 2);
	}

	ll x = ((1ll << m) - n - 1) / 2;
	x = max(x, 0ll);
	ll act = ((1ll << m) - 1) / 2;

	while (1) {
		ll idx = f(act);
		
		if (idx < x) {
			act++;
			continue;
		}

		if (idx > x) {
			act--;
			continue;
		}

		int f = 0;

		forn (i, n) if (act == a[i]) {
			act++;
			f = 1;
			break;
		}

		if (f) continue;

		cout << imp(act) << endl;
		return;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}