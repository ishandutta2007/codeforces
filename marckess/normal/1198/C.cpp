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
 
const int MX = 500005;
 
void solve () {
	int n, m;
	cin >> n >> m;
	vi in(3 * n + 1), a;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (!in[u] && !in[v]) {
			a.pb(i);
			in[u] = in[v] = 1;
		}
	}

	if (a.size() >= n) {
		cout << "Matching" << endl;
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	} else {
		cout << "IndSet" << endl;
		int k = 0;
		for (int i = 1; i <= 3 * n && k < n; i++)
			if (!in[i]) {
				cout << i << " ";
				k++;
			}
		cout << endl;
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