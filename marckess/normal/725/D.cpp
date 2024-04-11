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

const int MX = 300005;
int n, res = MX;
ll x;
ii a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> a[i].fi >> a[i].se;
		if (!i) {
			x = a[i].fi;
			a[i].se = ll(2e18) + 5;
		}
	}
	a[n++] = {0, ll(2e18) + 3};

	sort(a, a + n, greater<ii>());

	priority_queue<ll> si;
	priority_queue<ll, vector<ll>, greater<ll>> no;
	ll acu = 0;

	forn (i, n) {
		if (a[i].fi <= x && a[i].se < ll(2e18) + 5) {
			ll dis = x - a[i].fi;

			while (si.size() && no.size() && si.top() > no.top()) {
				acu -= si.top();
				acu += no.top();
				
				ll temp = si.top();
				si.pop();
				si.push(no.top());
				no.pop();
				no.push(temp);
			}

			while (no.size() && acu + no.top() <= dis) {
				acu += no.top();
				si.push(no.top());
				no.pop();
			}

			res = min(res, i - (int)si.size());
		}

		no.emplace(a[i].se - a[i].fi + 1);
	}

	cout << res << endl;
	
	return 0;
}