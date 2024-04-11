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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], q[MX], res[MX], k;
ll mem[MX];

ll dp (int i) {
	if (i + 1 == n || i == n) return 0;
	if (i > n) return -1e18;
	ll &res = mem[i];
	if (res != -1)
		return res;
	return res = max(
		dp(i + 1),
		dp(i + 3) + a[q[i+1]] - a[q[i]]
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		q[i] = i;
	}

	sort(q+1, q+n+1, [&] (int i, int j) {
		return a[i] < a[j];
	});

	memset(mem, -1, sizeof(mem));
	ll k = a[q[n]] - a[q[1]] - dp(3);

	int x = 3, cn = 1;
	while (x + 1 < n) {
		if (dp(x + 1) < dp(x + 3) + a[q[x+1]] - a[q[x]]) {
			res[q[x+1]] = 1;
			cn++;
			x += 3;
		} else {
			x++;
		}
	}

	res[q[1]] = 1;
	for (int i = 2; i <= n; i++)
		res[q[i]] += res[q[i-1]];

	cout << k << " " << cn << endl;
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}