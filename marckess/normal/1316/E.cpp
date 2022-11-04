#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 100002;
int n, p, k, a[MX], s[MX][7], q[MX];
ll mem[MX][1 << 7];

ll dp (int _, int mk) {
	int cn = __builtin_popcount(mk);
	int i = q[_];

	if (_ == n) {
		if (cn == p) return 0;
		return -1e9;
	}

	ll &res = mem[_][mk];
	if (res != -1) return res;

	if (_ - cn < k) res = dp(_ + 1, mk) + a[i];
	else res = dp(_ + 1, mk);

	for (int j = 0; j < p; j++)
		if (!(mk & (1 << j)))
			res = max(res, dp(_ + 1, mk | (1 << j)) + s[i][j]);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> p >> k;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			cin >> s[i][j];

	iota(q, q + n, 0);
	sort(q, q + n, [&] (int i, int j) {
		return a[i] > a[j];
	});

	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0) << endl;

	return 0;
}