#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10000005;
int n, k, bs[MX], ant[200005], dp[200005][21], aux[25];
map<vi, int> st;

void solve () {
	cin >> n >> k;
	st.clear();
	
	forn (i, n) {
		int a;
		cin >> a;
		vi v;
		
		while (a > 1) {
			int p = bs[a], pw = 0;
			while (a % p == 0) {
				a /= p;
				pw ^= 1;
			}
			if (pw) v.pb(p);
		}
	
		sort(all(v));
		if (st.count(v)) {
			ant[i] = st[v];
		} else {
			ant[i] = -1;
		}
		st[v] = i;
	}
	
	int m = 1;
	aux[0] = -1;
	
	forn (i, n) {
		if (ant[i] != -1) {
			aux[m] = ant[i];
			m++;
			
			sort(aux, aux + m, greater<int>());
			m = min(m, k + 1);
		}
		
		for (int j = 0; j <= k; j++) {
			dp[i][j] = 1e9;
			
			for (int l = 0; l < min(m, j + 1); l++) {
				if (aux[l] == -1)
					dp[i][j] = 1;
				else
					dp[i][j] = min(dp[i][j], dp[aux[l]][j - l] + 1);
			}
		}
	}
	
	cout << dp[n - 1][k] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}