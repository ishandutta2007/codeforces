#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;

	// Replace numbers -- a_i = x if it must be added to b at step x, and -1 otherwise
	// If on both sides of x we have a -1, just multiply the result by 2, delete one of them -- the outcome is the same
	// If only one side has a -1, we must delete it, so let's do that
	
	vector<int> as(n, -1), ind(n, -1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ind[a - 1] = i;
	}

	vector<int> ord(k);
	for (int j = 0 ; j < k; ++j) {
		cin >> ord[j];
		--ord[j];
		as[ind[ord[j]]] = j;
	}

	vector<int> nxt(n+2, -1);
	vector<int> pre(n+2, -1);
	for (int i = 1; i <= n; ++i) {
		nxt[i] = i+1;
		pre[i] = i-1;
	}
	pre[0] = 0;
	nxt[n+1] = n+1;

	ll res = 1;
	for (int i = 0; i < k; ++i) {
		int j = ind[ord[i]];
		
		int a = pre[j+1];
		int b = nxt[j+1];

		bool le = !(a == 0 || as[a-1] > i);
		bool ri = !(b == n+1 || as[b-1] > i);

		res = (res * (le + ri)) % MOD;
		if (le) {
			nxt[pre[a]] = nxt[a];
			pre[nxt[a]] = pre[a];
		} else if (ri) {
			nxt[pre[b]] = nxt[b];
			pre[nxt[b]] = pre[b];
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}