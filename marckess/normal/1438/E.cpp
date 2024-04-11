#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, LG = 35;
int n, a[MX], b[MX];
ll res, acu[MX];
vi pos[MX];

ll sum (int i, int j) {
	if (i > j) return -1;
	if (i) return acu[j] - acu[i - 1];
	return acu[j];
}

bool valid (int i, int j) {
	return a[i] < a[j] && (a[i] ^ a[j]) == sum(i + 1, j - 1);
}

int msb (ll n) {
	ll x;
	forn (j, 60) if (n & (1ll << j)) x = j;
	return x;
}

void solve () {
	forn (i, LG) pos[i].clear();
	
	forn (i, n) {
		pos[b[i] = msb(a[i])].pb(i);
		acu[i] = a[i];
		if (i) acu[i] += acu[i - 1];
	}
	
	forn (i, n)
		for (int j = b[i]; j < LG; j++) {
			int k = lower_bound(acu, acu + n, acu[i] + (1ll << j)) - acu;
			if (j == b[i]) k = i;
			int l = upper_bound(all(pos[j]), k) - pos[j].begin();
			
			if (l < pos[j].size())
				res += valid(i, pos[j][l]);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];
	
	solve();
	reverse(a, a + n);
	solve();
	
	cout << res << endl;
	
	return 0;
}