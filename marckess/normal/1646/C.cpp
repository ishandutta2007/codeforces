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

ll n, fac[15];

void main_() {
	cin >> n;
	
	int res = 1e9;
	
	forn (mk, (1 << 15)) {
		ll sum = 0;
		
		forn (i, 15)
			if (mk & (1 << i))
				sum += fac[i];
		
		ll d = n - sum;
		
		if (d < 0) continue;
		if ((d & 1) && (mk & 1)) continue;
		if ((d & 2) && (mk & 2)) continue;
		
		res = min(res, __builtin_popcount(mk) + __builtin_popcountll(d));
	}
	
	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = 1;
	for (int i = 1; i < 15; i++)
		fac[i] = fac[i - 1] * i;
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}