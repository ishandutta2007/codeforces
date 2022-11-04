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

const int MX = 200005, SQ = 320;
int n, a[MX], mx, ind, cn[MX], res, dp[2 * MX];
vi pos[MX], izq, der;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		mx = max(mx, ++cn[a[i]]);
		if (cn[a[i]] == mx) ind = a[i];
		
		pos[a[i]].pb(i);
	}
	
	izq.pb(1);
	for (int i : pos[ind]) {
		izq.pb(i + 1);
		der.pb(i - 1);
	}
	der.pb(n);
	
	for (int i = 1; i <= n; i++)
		if (i - ind && cn[i])
			if (cn[i] < SQ) {
				int ini = 0;
				
				forn (j, cn[i]) {
					int it = upper_bound(all(izq), pos[i][j]) - izq.begin();
					it--;
					
					for (int k = max(ini, it - cn[i]); k <= it; k++)
						for (int l = 1, x = j; l <= cn[i] && k + l <= mx; l++) {
							while (x < pos[i].size() && pos[i][x] <= der[k + l])
								x++;
							
							if (l == x - j)
								res = max(res, der[k + l] - izq[k] + 1);
						}
					
					ini = it + 1;	
				}
			} else {
				int acu = 0, mx = 0, mn = 0;
				dp[MX] = 0;
				
				for (int j = 1; j <= n; j++) {
					if (a[j] == i) acu++;
					if (a[j] == ind) acu--;
					
					if (dp[acu + MX] != -1) res = max(res, j - dp[acu + MX]);
					else dp[acu + MX] = j;
					
					mn = min(mx, acu);
					mx = max(mx, acu);
				}
				
				for (int j = mn + MX; j <= mx + MX; j++)
					dp[j] = -1;
			}
	
	cout << res << endl;
	
	return 0;
}