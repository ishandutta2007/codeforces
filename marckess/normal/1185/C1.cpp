#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, t[MX], cn[105], res[MX], acu, s, p;

void solve (int m, int ind) {
	acu = 0, s = 0;
	memset(cn, 0, sizeof(cn));
	p = 100;

	for (int i = 0; i < n; i++) {
		if (t[i] == ind) res[i] = acu;

		if (t[i] > p) {
			acu++;
		} else {
			s += t[i];
			cn[t[i]]++;

			while (s > m) {
				while (!cn[p]) p--;
				cn[p]--;
				s -= p;
				acu++;
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn(i, n) cin >> t[i];
	for (int i = 1, lim = *max_element(t, t+n); i <= lim; i++)
		solve(m - i, i);
	forn(i, n) cout << res[i] << " ";
	cout << endl;

	return 0;
}