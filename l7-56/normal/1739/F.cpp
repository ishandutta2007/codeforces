// LUOGU_RID: 90748305
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

#define in(x, y) (((x) >> (y)) & 1)
const int maxn = 4010;
int n, tot = 1, trie[maxn][12], fail[maxn], sum[maxn], dp[1 << 12][maxn];
pii pre[1 << 12][maxn];

void ins(string s, int val) {
	int u = 1;
	for (char ch : s) {
		int c = ch - 'a';
		if (!trie[u][c]) trie[u][c] = ++tot;
		u = trie[u][c];
	}
	sum[u] += val;
}

void build() {
	queue <int> q;
	for (int i = 0; i < 12; ++i)
		if (trie[1][i]) q.push(trie[1][i]), fail[trie[1][i]] = 1;
		else trie[1][i] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		sum[u] += sum[fail[u]];
		for (int i = 0; i < 12; ++i)
			if (trie[u][i]) q.push(trie[u][i]), fail[trie[u][i]] = trie[fail[u]][i];
			else trie[u][i] = trie[fail[u]][i];
	}
}

void solve(string s, int val) {
	char t[40]; int used[12]; memset(used, 0, sizeof used);
	int l = 20, r = 20, p = 20; t[20] = s[0], used[s[0] - 'a'] = 1;
	for (int i = 1; i < (int) s.size(); ++i) {
		char ch = s[i];
		if (!used[ch - 'a']) {
			if (p == l) --l, --p, t[p] = ch;
			else if (p == r) ++r, ++p, t[p] = ch;
			else return;
			used[ch - 'a'] = 1;
		}
		else {
			if (p < r && t[p + 1] == ch) ++p;
			else if (p > l && t[p - 1] == ch) --p;
			else return;
		}
	}
	s = "";
	for (int i = l; i <= r; ++i) s += t[i];
	// cout << s << endl;
	ins(s, val), reverse(begin(s), end(s)), ins(s, val);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int c; string s;
		cin >> c >> s;
		solve(s, c);
	}
	build();
	memset(dp, 0xaf, sizeof dp);
	dp[0][1] = 0;
	for (int s = 0; s < (1 << 12); ++s)
		for (int i = 1; i <= tot; ++i) {
			for (int c = 0; c < 12; ++c) if (!in(s, c)) {
				int ns = s | (1 << c), ni = trie[i][c], val = dp[s][i] + sum[ni];
				if (dp[ns][ni] < val) dp[ns][ni] = val, pre[ns][ni] = {c, i};
			}
		}
	int s = (1 << 12) - 1, i = 1;
	for (int j = 1; j <= tot; ++j)
		if (dp[s][i] < dp[s][j]) i = j;
	string ans;
	while (s) {
		int c = pre[s][i].fir;
		ans += char(c + 'a'), i = pre[s][i].sec, s ^= 1 << c;
	}
	cout << ans << endl;
	return 0;
}