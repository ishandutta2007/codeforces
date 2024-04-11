
// Problem : C. Divan and bitwise operations
// Contest : Codeforces - Codeforces Round #757 (Div. 2)
// URL : https://codeforces.com/contest/1614/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int MX = 200005, mod = 1000000007;
int n, m, l[MX], r[MX], x[MX], to[MX], a[MX], cn[MX];
ll pot[MX];

void main_() {
	cin >> n >> m;
	
	forn (i, m) {
		cin >> l[i] >> r[i] >> x[i];
		l[i]--, r[i]--;
	}
	
	forn (i, n)
		a[i] = 0;
	
	forn (j, 30) {
		memset(to, -1, sizeof(to));
		int mx = -1;
		cn[j] = 0;
		
		forn (i, m)
			if (~x[i] & (1 << j))
				to[l[i]] = max(to[l[i]], r[i]);
		
		forn (i, n) {
			mx = max(mx, to[i]);
			
			if (mx < i) {
				a[i] |= 1 << j;
				cn[j]++;
			}
		}
	}
	
	ll res = 0;
	forn (j, 30)
		if (cn[j])
			(res += (1ll << j) * (pot[cn[j] - 1] * pot[n - cn[j]] % mod)) %= mod;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	pot[0] = 1;
	forr (i, 1, MX - 1)
		pot[i] = pot[i - 1] * 2 % mod;
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}