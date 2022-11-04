
// Problem : E. Playoff Restoration
// Contest : Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1569/problem/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int mod = 998244353;
int k;
ll A, h, pot[33];
vi res;

map<int, vi> mp[33], mp2[33];

void f (vi a, int z, ll acu, map<int, vi> mp[33]) {
	if (a.size() == 1) {
		res[a[0]] = z / 2 + 1;
		mp[a[0]][acu] = res;
		return;
	}
	
	int lim = 1 << (a.size() / 2);
	
	forn (mk, lim) {
		vi b;
		ll x = acu;
		
		forn (i, a.size() / 2)
			if (mk & (1 << i)) {
				b.pb(a[2 * i]);
				res[a[2 * i + 1]] = z / 2 + 1;
				(x += a[2 * i + 1] * pot[z / 2 + 1]) %= mod;
			} else {
				b.pb(a[2 * i + 1]);
				res[a[2 * i]] = z / 2 + 1;
				(x += a[2 * i] * pot[z / 2 + 1]) %= mod;
			}
		
		f(b, z / 2, x, mp);
	}
}

void main_() {
	cin >> k >> A >> h;
	
	pot[0] = 1;
	for (int i = 1; i < 33; i++)
		pot[i] = pot[i - 1] * A % mod;
	
	res = vi((1 << k) + 1);
	
	int n = 1 << k;
	
	vi a, b;
	for (int i = 1; i <= n; i++) {
		if (i <= n / 2) a.pb(i);
		else b.pb(i);
	}
	
	f(a, n, 0, mp);
	f(b, n, 0, mp2);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if ((i <= n / 2) == (j <= n / 2))
				continue;
			
			if (!mp[i].size())
				forn (i, 33)
					swap(mp[i], mp2[i]);
		
			for (auto it = mp[i].begin(); it != mp[i].end(); it++) {
				auto exp = MOD(h - it->fi - i * pot[1], mod);
				exp = MOD(exp - j * pot[2], mod);
				
				if (mp2[j].count(exp)) {
					vi res = it->se;
					res[i] = 1;
					
					if (i <= n / 2) {
						for (int l = n / 2 + 1; l <= n; l++)
							res[l] = mp2[j][exp][l];
					} else {
						for (int l = 1; l <= n / 2; l++)
							res[l] = mp2[j][exp][l];
					}
					
					for (int i = 1; i <= n; i++)
						cout << res[i] << " ";
					cout << endl;
					return;
				}
			}
		}
	
	cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		main_();
	
	return 0;
}