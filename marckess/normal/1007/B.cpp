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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int a, b, c, cn[8], tot[8];
vi divi[MX];

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	ll res = 1;
	for (int i = n; i > n - k; i--)
		res *= i;
	for (int i = 1; i <= k; i++)
		res /= i;
	return res;
}

void solve () {
	cin >> a >> b >> c;
	memset(cn, 0, sizeof(cn));
	
	for (int x : divi[a]) {
		int k = 0;
		if (a % x == 0) k |= 1;
		if (b % x == 0) k |= 2;
		if (c % x == 0) k |= 4;
		cn[k]++; 
	}
	for (int x : divi[b]) {
		int k = 0;
		if (a % x == 0) k |= 1;
		if (b % x == 0) k |= 2;
		if (c % x == 0) k |= 4;
		cn[k]++; 
	}
	for (int x : divi[c]) {
		int k = 0;
		if (a % x == 0) k |= 1;
		if (b % x == 0) k |= 2;
		if (c % x == 0) k |= 4;
		cn[k]++; 
	}
	
	for (int i = 1; i < 8; i++)
		cn[i] /= __builtin_popcount(i);
	
	ll res = 0;
	for (int i = 1; i < 8; i++)
		for (int j = i; j < 8; j++)
			for (int k = j; k < 8; k++) {
				int f = 0;
				
				vi v = {1, 2, 4};
				do f |= (v[0] & i) && (v[1] & j) && (v[2] & k);
				while (next_permutation(all(v)));
				
				if (f) {
					memset(tot, 0, sizeof(tot));
					
					tot[i]++;
					tot[j]++;
					tot[k]++;
					
					ll g = 1;
					for (int l = 1; l < 8; l++)
						if (tot[l])
							g *= comb(cn[l] + tot[l] - 1, tot[l]);
					res += g;
				}
			}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 1; i < MX; i++)
		for (int j = i; j < MX; j += i)
			divi[j].pb(i);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}