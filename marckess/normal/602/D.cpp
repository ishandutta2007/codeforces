#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, q, l, r, a[100005], h[100005];
ll izq[100005], der[100005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	for (int i = 1; i < n; i++)
		a[i] = abs(h[i] - h[i+1]);

	stack<ii> mn;
	mn.emplace(0, 1e9);
	for (int i = 1; i < n; i++) {
		while (mn.top().se <= a[i])
			mn.pop();
		izq[i] = mn.top().fi + 1;
		mn.emplace(i, a[i]);
	}

	while (mn.size())
		mn.pop();
	mn.emplace(n, 1e9);
	for (int i = n - 1; i; i--) {
		while (mn.top().se < a[i])
			mn.pop();
		der[i] = mn.top().fi - 1;
		mn.emplace(i, a[i]);
	}

	while (q--) {
		ll res = 0;
		cin >> l >> r;

		for (int i = l; i < r; i++) {
			ll x = i - max(ll(l), izq[i]);
			ll y = min(ll(r-1), der[i]) - i;

			res += a[i] * (x * y + x + y + 1);
		}

		cout << res << endl;
	}

	return 0;
}