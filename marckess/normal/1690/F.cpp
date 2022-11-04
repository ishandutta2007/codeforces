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

const int MX = 205;
int n, p[MX], vis[MX];
string s;

void main_() {
	cin >> n >> s;
	s = " " + s;
	forr (i, 1, n)
		cin >> p[i];
	
	memset(vis, 0, sizeof(vis));
	ll res = 1;
	forr (i, 1, n) {
		if (vis[i])
			continue;
		
		string t;
		int u = i;
		while (!vis[u]) {
			vis[u] = 1;
			t.pb(s[u]);
			u = p[u];
		}
		
		forr (d, 1, t.size()) {
			if (t.size() % d)
				continue;
			
			int f = 1;
			forn (i, t.size())
				f &= t[i] == t[i % d];
			
			if (f) {
				res = res / __gcd(res, 1ll * d) * d;
				break;
			}
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}