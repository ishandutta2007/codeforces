#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, a[MX], mx = 0, t = 0;
deque<int> dq;
ll m;
ii res[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> m;
		dq.push_back(m);
		mx = max((ll)mx, m);
	}

	while (1) {
		int a = dq.front(); dq.pop_front();
		int b = dq.front(); dq.pop_front();

		res[t++] = {a, b};
		if (a < b) swap(a, b);
		dq.push_front(a);
		dq.push_back(b);
		if (a == mx) break;
	}

	dq.pop_front();
	for (int i = 0; i < n - 1; i++) {
		a[i] = dq.front();
		dq.pop_front();
	}

	while (q--) {
		cin >> m;
		m--;
		if (m < t) {
			cout << res[m].fi << " " << res[m].se << endl;
		} else {
			m = (m - t) % (n - 1);
			cout << mx << " " << a[m] << endl;
		}
	}
 
	return 0;
}