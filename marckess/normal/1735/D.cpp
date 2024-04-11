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

const int MX = 1005;
int n, k;
vi c[MX];
map<vi, int> cn, dp;

void main_() {
	cin >> n >> k;
	forn (i, n) {
		c[i] = vi(k);
		forn (j, k)
			cin >> c[i][j];
		cn[c[i]]++;
	}
	
	ll res = 0;
	forn (i, n) {
		forn (j, i) {
			vi ot(k);
			
			forn (l, k) {
				if (c[i][l] == c[j][l]) {
					ot[l] = c[i][l];
				} else {
					ot[l] = 3 - c[i][l] - c[j][l];
				}
			}
			
			res += 1ll * cn[ot] * dp[ot];
			dp[ot]++;
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}