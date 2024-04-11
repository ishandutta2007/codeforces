#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)
struct Node {
	int x, v, y;
	bool operator < (const Node &a) const {
		return x < a.x;
	}
};
#define N 16

int n;
LL s[N];
vector <int> a[N];
vector <Node >st[1 << N];
map <int, int> bel;
vector <Node> ans;
bool dp[1 << N];
int fr[1 << N];
void dfs(int x) {
	if (x == fr[x]) {
		for (auto v : st[x]) ans.push_back(v);
		return;
	}
	dfs(fr[x]);
	dfs(x ^ fr[x]);
}

int main() {
	read(n);
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		int x; read(x);
		while (x--) {
			int y;
			read(y);
			s[i] += y;
			a[i].push_back(y);
			bel[y] = i;
		}
		sum += s[i];
	}
	if (sum % n) return puts("No") * 0;
	sum /= n;
	for (int i = 0; i < n; i++) {
		if (s[i] == sum) {
			st[1 << i] = {{i, a[i][0], i}};
			continue;
		}
		for (int j = 0; j < (int)a[i].size(); j++) {
			int x = i, y = a[i][j], state = 1 << i;
			vector < Node > now;
			int fir(y);
			LL r = sum - (s[x] - y);
			while (true) {
				if (abs(r) < 0x7fffffff && bel.count(int(r))) {
					int k = bel[int(r)];
					if (fir == r) {
						now.push_back({i, fir, x});
						r = 0;
						break;
					}
					else if (!(state >> k & 1)) {
						state |= 1 << k;
						now.push_back({k, int(r), x});
						x = k;
						r = sum - (s[x] - r);
					}
					else {
						r = -1;
						break;
					}
				}else {
					r = -1;
					break;
				}
			}
			if (r != -1) {
				if (st[state].empty()) {
					st[state] = now;
				}
			}
		}
	}
	dp[0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		if (st[i].size()) dp[i] = 1, fr[i] = i;
	}
	for (int i = 1; i < (1 << n); i++) {
		if (!dp[i]) for (int j = i; j; j = (j - 1) & i) {
			if (dp[i ^ j] && dp[j]) {
				dp[i] = 1;
				fr[i] = j;
			}
		}
	}
	if (!dp[(1 << n) - 1]) return puts("No"), 0;
	puts("Yes");
	int x = (1 << n) - 1;
	dfs(x);
	sort(ans.begin(), ans.end());
	for (auto v : ans) {
		printf("%d %d\n", v.v, v.y + 1);
	}
}