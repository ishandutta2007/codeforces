// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string s;
vvi adj;

void main_() {
	cin >> n >> s;
	adj = vvi(n);
	
	int x = 0;
	for (char c : s)
		x += c == '1';
	
	if (!x || x % 2) {
		cout << "NO" << endl;
		return;
	}
	
	cout << "YES" << endl;
	int f = 0;
	forn (i, n)
		if (s[i] == '0' && s[MOD(i - 1, n)] == '1') {
			forr (j, 1, n - 1) {
				if (s[MOD(i + j - 1, n)] == '0')
					adj[MOD(i + j, n)].pb(MOD(i + j - 1, n));
				else
					adj[MOD(i + j, n)].pb(i);
			}
			
			f = 1;
			break;
		}
	
	if (!f) {
		forr (i, 1, n - 1)
			adj[i].pb(0);
	}
	
	forn (u, n)
		for (int v : adj[u])
			cout << u + 1 << " " << v + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}