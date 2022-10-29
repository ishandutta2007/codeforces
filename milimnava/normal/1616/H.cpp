#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

const int N = 150005;

int trie[N * 35][2], cnt[N * 35], pw[N];
int n, xx, tot = 1, ans;

int solve(int l, int r, int b) {
	if (!l || !r || b == -1) {
		if (l == r) return pw[cnt[l]] - 1;
		return pw[cnt[l] + cnt[r]] - 1;
	}
	int ans;
	if ((xx >> b) & 1) {
		ans = solve(trie[l][0], trie[r][1], b - 1);
		if (l != r) {
			int tmp = solve(trie[l][1], trie[r][0], b - 1);
			ans = (1ll * (ans + 1) * (tmp + 1) - 1) % mod;
		}
	} else {
		ans = solve(trie[l][0], trie[r][0], b - 1);
		ans = (ans + solve(trie[l][1], trie[r][1], b - 1)) % mod;
		if (l != r) {
			ans = (ans + 1ll * (pw[cnt[trie[l][0]]] - 1) * (pw[cnt[trie[l][1]]] - 1)) % mod;
			ans = (ans + 1ll * (pw[cnt[trie[r][0]]] - 1) * (pw[cnt[trie[r][1]]] - 1)) % mod;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> xx;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		int now = 1; ++cnt[1];
		for (int j = 29; j >= 0; j--) {
			int son = (x >> j) & 1;
			if (!trie[now][son]) trie[now][son] = ++tot;
			now = trie[now][son]; ++cnt[now];
		}
	}
	cout << (solve(1, 1, 29) + mod) % mod << endl;
	return 0;
}