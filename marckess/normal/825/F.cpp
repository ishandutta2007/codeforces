#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 8005;
int n, dp[MX], b[MX];
string s;

void kmp (int ini) {
	int i = ini, j = ini-1; b[ini] = ini-1;
	while (i < n) {
		while (j >= ini && s[i] != s[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}
}

int dig (int n) {
	int res = 0;
	while (n) res++, n /= 10;
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	for (int i = n-1; i >= 0; i--) {
		kmp(i);
		dp[i] = 1e9;

		for (int j = i+1; j <= n; j++) {
			int d = j - i - (b[j] - i);
			if ((j - i) % d)
				dp[i] = min(dp[i], j - i + 1 + dp[j]);
			else
				dp[i] = min(dp[i], dig((j - i) / d) + d + dp[j]);
		}
	}

	cout << dp[0] << endl;

	return 0;
}