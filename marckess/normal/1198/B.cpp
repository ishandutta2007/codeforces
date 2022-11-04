#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 200005;
int n, a[MX], q, op, x[MX], l[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	forn(i, n) cin >> a[i];
	cin >> q;

	forn(i, q) {
		cin >> op;
		if (op - 2) {
			int p, x;
			cin >> p >> x;
			a[p-1] = x;
			l[p-1] = i;
		}
		else cin >> x[i]; 
	}

	forn(i, q) x[q-i-1] = max(x[q-i-1], x[q-i]);

	forn(i, n) cout << max(a[i], x[l[i]]) << " ";
	cout << endl;

	return 0;
}