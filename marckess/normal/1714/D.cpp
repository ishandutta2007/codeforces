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

const int MX = 105;
int n, dp[MX];
string t, s[MX];
ii res[MX];

void main_() {
	cin >> t >> n;
	forn (i, n)
		cin >> s[i];
	
	forn (i, t.size()) {
		dp[i] = 1e9;
		
		forn (j, n) {
			for (int ini = i; ini >= 0 && ini + (int)s[j].size() - 1 >= i; ini--)
				if (ini + s[j].size() <= t.size()) {
					string aux = t.substr(ini, s[j].size());
					
					if (aux == s[j]) {
						int d = (ini ? dp[ini - 1] : 0) + 1;
						
						if (d < dp[i]) {
							res[i] = {j, ini};
							dp[i] = d;
						}
					}
				}
		}
	}
	
	int u = (int)t.size() - 1;
	if (dp[u] == 1e9) cout << -1 << endl;
	else {
		cout << dp[u] << endl;
		while (u >= 0) {
			cout << res[u].fi + 1 << " " << res[u].se + 1 << endl;
			u = res[u].se - 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}