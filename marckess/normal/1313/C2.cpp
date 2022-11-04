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
typedef vector<ii> vii;

const int MX = 500005;
ll n, a[MX];
ll izq[MX], der[MX], acu, res[MX];
stack<ii> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		ll l = 1;

		while (st.size() && st.top().fi > a[i]) {
			acu -= st.top().fi * st.top().se;
			l += st.top().se;
			st.pop();
		}

		st.emplace(a[i], l);
		acu += st.top().fi * st.top().se;
		izq[i] = acu;
	}

	acu = 0;
	while (st.size()) st.pop();

	for (int i = n; i > 0; i--) {
		ll l = 1;

		while (st.size() && st.top().fi > a[i]) {
			acu -= st.top().fi * st.top().se;
			l += st.top().se;
			st.pop();
		}

		st.emplace(a[i], l);
		acu += st.top().fi * st.top().se;
		der[i] = acu;
	}

	ll mx = 0, ind = 1;
	for (int i = 1; i <= n; i++) {
		ll p = izq[i] + der[i] - a[i];
		if (p > mx) {
			mx = p;
			ind = i;
		}
	}

	ll mn = a[ind];
	for (int i = ind; i > 0; i--) {
		mn = min(mn, a[i]);
		res[i] = mn;
	}

	mn = a[ind];
	for (int i = ind; i <= n; i++) {
		mn = min(mn, a[i]);
		res[i] = mn;
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}