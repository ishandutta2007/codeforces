#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, k[MX], izq[MX], der[MX];
vi g[MX];

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		izq[i] = der[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		g[i].resize(k[i]);
		for (int &x : g[i]) cin >> x;

		for (int x : g[i]) {
			if (!der[x]) {
				der[x] = i;
				izq[i] = x;
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (!izq[i]) {
			for (int j = 1; j <= n; j++)
				if (!der[j]) {
					cout << "IMPROVE" << endl;
					cout << i << " " << j << endl;
					return;
				}
			}

	cout << "OPTIMAL" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}