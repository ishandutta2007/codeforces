#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n;
ll c[510][7];

ll comb (ll n, ll k) {
	if (n == k || k == 0) return 1;
	if (c[n][k] == -1) c[n][k] = comb(n-1, k) + comb(n-1, k-1);
	return c[n][k];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(c, -1, sizeof(c));

	cin >> n;

	cout << comb(n+2, 3) * comb(n+4, 5) << endl;

	return 0;
}