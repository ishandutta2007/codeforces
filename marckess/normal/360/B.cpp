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

const int MX = 2005;
int n, k, dp[MX], a[MX];

inline int techo (int a, int b) {
	return (a + b - 1) / b;
}

bool esPos (int m) {
	for (int i = n-1; i >= 0; i--) {
		dp[i] = n-i-1;
		for (int j = i+1; j < n; j++)
			if (techo(abs(a[i]-a[j]), j-i) <= m)
				dp[i] = min(dp[i], dp[j]+j-i-1);
	}

	for (int i = 0; i < n; i++)
		if (i + dp[i] <= k)
			return 1;
	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	int i = 0, j = 2e9+5, rep = 33;
	while (rep--) {
		int m = (ll(i)+j)/2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << j << endl;

	return 0;
}