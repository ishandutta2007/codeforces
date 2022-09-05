#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e6 + 5;

queue <int> can;
vector <int> fuck[N], pos[N];
pii r[N];
int a[N], s[N], nxt[N], ans[N], tmp1[N], tmp2[N], st[N], lim[N], f[N], used[N];
int T, n, tot, top;

void solve(int *a, int *b, int n) {
	for (int i = 0; i <= n * 2; i++) pos[i].clear();
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1];
		if (a[i]) {
			++s[i];
			pos[i - s[i - 1] * 2 + n].push_back(i);
		}
	}
	for (int i = 0; i <= n * 2; i++) reverse(pos[i].begin(), pos[i].end());
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			if (top >= 2 && st[top - 1] == a[i]) --top;
			else {
				if (used[a[i]]) {
					printf("no\n");
					exit(0);
				}
				used[a[i]] = 1;
				st[++top] = a[i], lim[top] = lim[top - 1];
			}
			pos[i - s[i - 1] * 2 + n].pop_back();
			continue;
		}
		if (!pos[i - s[i] * 2 + n].empty() && pos[i - s[i] * 2 + n].back() < lim[top]) {
			int res = pos[i - s[i] * 2 + n].back();
			if (used[a[res]]) {
				printf("no\n");
				exit(0);
			}
			used[a[res]] = 1;
			ans[b[i]] = a[res];
			st[++top] = a[res]; lim[top] = res;
		} else if (top >= 2) {
			--top;
			ans[b[i]] = st[top];
		} else {
			if (can.empty()) {
				printf("no\n");
				exit(0);
			}
			int res = can.front();
			can.pop();
			ans[b[i]] = res;
			st[++top] = res; lim[top] = lim[top - 1];
		}
		// fprintf(stderr, "set %d %d\n", b[i], ans[b[i]]);
		// for (int j = 1; j <= ::n; j++) print(ans[j], j == ::n ? '\n' : ' ');
	}
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	read(n);
	n = n * 2 - 1;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		if (a[i] != 0) ans[i] = a[i], used[a[i]] = 1;
		nxt[i] = i + 1;
		f[i] = i;
	}
	tot = 0;
	for (int i = 1; i <= n / 2 + 1; i++) if (!used[i]) can.push(i);
	if (a[1] && a[n]) {
		if (a[1] != a[n]) {
			puts("no");
			return 0;
		}
	} else if (a[1] || a[n]) {
		a[1] = a[n] = a[1] + a[n];
	} else {
		if (can.empty()) {
			puts("no");
			return 0;
		}
		a[1] = a[n] = can.front(); can.pop();
	}
	ans[1] = a[1]; ans[n] = a[n];
	for (int i = 1; i <= n; i++) if (a[i]) fuck[a[i]].push_back(i);
	for (int i = 1; i <= n / 2 + 1; i++) {
		for (int j = 1; j < (int)fuck[i].size(); j++) {
			r[++tot] = make_pair(fuck[i][j] - fuck[i][j - 1], fuck[i][j - 1]);
		}
	}
	memset(used, 0, sizeof(used));
	sort(r + 1, r + tot + 1);
	for (int i = 1; i <= tot; i++) {
		int len = 0, now = nxt[r[i].second];
		while (now != r[i].first + r[i].second) {
			++len;
			tmp1[len] = a[now];
			tmp2[len] = now;
			now = nxt[now];
		}
		nxt[find(r[i].second)] = nxt[now];
		f[now] = find(r[i].second);
		st[top = 1] = a[r[i].second]; lim[1] = len + 1;
		if (len % 2 == 0) {
			// fprintf(stderr, "l = %d, r = %d\n", r[i].second, r[i].first + r[i].second);
			printf("no\n");
			return 0;
		}
		solve(tmp1, tmp2, len);
	}
	puts("yes");
	for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}