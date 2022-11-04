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

const int MX = 200005, mod = 998244353;
int n, m, k, q, x[MX], y[MX];

void main_() {
	cin >> n >> m >> k >> q;
	forn (i, q)
		cin >> x[i] >> y[i];
	
	set<int> sx, sy;
	
	int cn = 0;
	for (int i = q - 1; i >= 0; i--) {
		int f = 0;
		if (!sx.count(x[i]) && sy.size() != m)
			f = 1;
		if (!sy.count(y[i]) && sx.size() != n)
			f = 1;
		cn += f;
		
		sx.insert(x[i]);
		sy.insert(y[i]);
	}
	
	ll res = 1;
	forn (i, cn)
		(res *= k) %= mod;
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