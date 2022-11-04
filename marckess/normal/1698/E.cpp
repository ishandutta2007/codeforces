// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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
int n, s, a[MX], b[MX], fa[MX], ffa[MX], fb[MX], ffb[MX], acu[MX];

void main_() {
	cin >> n >> s;
	
	forn (i, n + 3) {
		fa[i] = fb[i] = -1;
		ffa[i] = ffb[i] = -1;
		acu[i] = 0;
	}
		
	forr (i, 1, n) {
		cin >> a[i];
		fa[a[i]] = i;
	}
	
	forr (i, 1, n)
		ffa[fa[i]] = i;
	
	forr (i, 1, n) {
		cin >> b[i];
		if (b[i] != -1)
			fb[b[i]] = i;
	}
	
	forr (i, 1, n)
		if (fb[i] != -1)
			ffb[fb[i]] = i;
	
	//forr (i, 1, n) cout << fa[i] << " "; cout << endl;
	//forr (i, 1, n) cout << fb[i] << " "; cout << endl;
	
	ll res = 1, x = 0, y = 0;
	
	forr (i, 1, 1 + s - 1) {
		if (ffb[fa[i]] != -1) x++;
		else y++;
	}
	
	forr (i, 1, n) {
		if (i + s <= n) {
			if (ffb[fa[i + s]] != -1) x++;
			else y++;
		}
		
		if (fb[i] == -1) {
			// cout << x << " " << y << endl;
			(res *= y) %= mod;
			y--;
		} else {
			x--;
			if (ffa[fb[i]] - i > s)
				res = 0;
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