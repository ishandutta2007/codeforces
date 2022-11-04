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

int n;
ll res;
vi v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	forn (i, n) {
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;

		if (a1 + b1 >= a2 + b2) {
			v.pb(a1 + b1);
			v.pb(a2 + b2);
			res += a1 + a2;
		} else if (a1 > b2) {
			res += a1 - b2;
		} else if (b1 > a2) {
			res += a2 - b1;
		}
	}

	sort(all(v), greater<int>());

	for (int i = 1; i < v.size(); i += 2)
		res -= v[i];

	cout << res << endl;
	
	return 0;
}