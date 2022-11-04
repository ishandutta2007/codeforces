#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, w[MX], l[MX], dp1[MX], dp2[MX];

bool win (ll a, ll b) {
	int g = 0;

	while (1) {
		if (!g && b % 2)
			return (b - a) % 2;

		ll nex = b / 2;
		if (nex < a) {
			if (g) return 1;
			return (b - a) % 2;
		}

		b = nex;
		g = 1 - g;
	}
}

bool lose (ll a, ll b) {
	int g = 1;

	while (1) {
		if (!g && b % 2)
			return (b - a) % 2;

		ll nex = b / 2;
		if (nex < a) {
			if (g) return 1;
			return (b - a) % 2;
		}

		b = nex;
		g = 1 - g;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) {
		ll a, b;
		cin >> a >> b;
		w[i] = win(a, b);
		l[i] = lose(a, b);
	}

	dp2[n] = 1;

	for (int i = n - 1; i >= 0; i--) {
		if (w[i] && l[i]) {
			dp1[i] = 1;
			dp2[i] = 1;
		} else if (w[i]) {
			dp1[i] = 1 - dp1[i + 1];
			dp2[i] = 1 - dp2[i + 1];
		} else if (l[i]) {
			dp1[i] = dp1[i + 1];
			dp2[i] = dp2[i + 1];
		} else {
			dp1[i] = 0;
			dp2[i] = 0;
		}
	}

	cout << dp1[0] << " " << dp2[0] << endl;

	return 0;
}