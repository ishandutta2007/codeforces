#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef tuple <int, int, int> piii;

const int maxn = 1e3 + 10, base = 131;
int n,m;
map <int, piii> mp[4];
int f[maxn],lst[maxn];
piii op[maxn];
char s[maxn][maxn];

#define num(c) ((c) - 'a' + 1)

void print(int x) {
	if (!x) return;
	print(lst[x]);
	int id, l, r;
	tie(id, l, r) = op[x];
	printf("%d %d %d\n", l, r, id);
}

void work() {
	scanf("%d%d", &n, &m);
	mp[2].clear(), mp[3].clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j < m; ++j)
			mp[2].insert(make_pair(
				num(s[i][j]) * base + num(s[i][j + 1]),
				make_tuple(i, j, j + 1)));
		for (int j = 1; j < m - 1; ++j)
			mp[3].insert(make_pair(
				num(s[i][j]) * base * base + num(s[i][j + 1]) * base + num(s[i][j + 2]),
				make_tuple(i, j, j + 2)));
	}
	scanf("%s", s[0] + 1);
	f[0] = 1;
	for (int i = 1; i <= m; ++i) {
		f[i] = 0;
		for (int j = 2; j < 4; ++j)
			if (i >= j && f[i - j]) {
				int val = 0;
				if (j == 2) val = num(s[0][i - 1]) * base + num(s[0][i]);
				else val = num(s[0][i - 2]) * base * base + num(s[0][i - 1]) * base + num(s[0][i]);
				auto it = mp[j].find(val);
				if (it == mp[j].end()) continue;
				lst[i] = i - j;
				op[i] = it -> second;
				f[i] = 1;
				break;
			}
	}
	if (!f[m]) { printf("-1\n"); return; }
	int cnt = 0;
	for (int i = m; i; i = lst[i]) cnt++;
	printf("%d\n", cnt);
	print(m);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}