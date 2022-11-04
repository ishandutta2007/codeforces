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
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, u, v;
vi adj[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}