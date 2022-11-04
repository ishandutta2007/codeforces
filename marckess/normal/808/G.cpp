#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, go[MX][26], f[MX], dp[111*MX];
string s, t;

#define h(i,j) ((i)*m+(j))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> t;
	n = s.size(), m = t.size();

	for (char &c : s) c -= 'a';
	for (char &c : t) c -= 'a';

	int i = 0, j = -1;
	f[0] = -1;
	while (i < m) {
		while (j >= 0 && t[i] != t[j]) j = f[j];
		i++, j++;
		f[i] = j;
	}

	i = 0;
	while (i < m) {
		for (int k = 0; k < 26; k++) {
			if (t[i] == k) go[i][k] = i+1;
			else if (f[i] != -1) go[i][k] = go[f[i]][k];
			else  go[i][k] = 0;
		}
		i++;
	}

	for (int i = n-1; i >= 0; i--)
		for (int j = 0; j < m; j++) {
			int &res = dp[h(i,j)];
			if (s[i] == '?'-'a') {
				for (int k = 0; k < 26; k++)
					if (go[j][k] == m) res = max(res, dp[h(i+1, f[m])]+1);
					else res = max(res, dp[h(i+1, go[j][k])]);
			} else {
				if (go[j][s[i]]==m) res = dp[h(i+1,f[m])] + 1;
				else res = dp[h(i+1,go[j][s[i]])];
			}
		}

	cout << dp[0] << endl;

	return 0;
}