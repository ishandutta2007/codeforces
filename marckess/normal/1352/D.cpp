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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, a[MX];
deque<int> q;

void solve () {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		q.pb(a[i]);
	}

	int a = 0, b = 0, ant = 0, res = 0;
	while (q.size()) {
		int act = 0;
		res++;

		while (q.size() && act <= ant) {
			a += q.front();
			act += q.front();
			q.pop_front();
		}
		ant = act;

		if (!q.size()) break;

		act = 0;
		res++;

		while (q.size() && act <= ant) {
			b += q.back();
			act += q.back();
			q.pop_back();
		}
		ant = act;
	}

	cout << res << " " << a << " " << b << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}