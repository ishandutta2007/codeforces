#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, k, w;
int acu[10][MX];
char s[MX];
int l, r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> w;
	for (int i = 1; i <= n; i++)
		cin >> s[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) 
			acu[j][i] = acu[j][i-1];
		if (s[i] == '1') acu[i%k][i]++;
	}

	while (w--) {
		cin >> l >> r;
		int tm = (r-l+1)/k;
		int d = MOD(l-1, k);
		int res = 0;

		for (int j = 0; j < k; j++)
			if (d == j) res += tm - acu[j][r] + acu[j][l-1];
			else res += acu[j][r] - acu[j][l-1];

		cout << res << endl;
	}

	return 0;
}