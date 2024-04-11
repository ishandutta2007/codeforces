#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

#define x first
#define y second


#define N 1011

const LL M = 2e18;

int n, m, tcnt; LL K;
char s[N];

int t[N * N][26], siz[N * N], R[N];

void insert(int x) {
	int p = 0;
	for (int i = x; i <= n; i++) {
		if (t[p][s[i]]) p = t[p][s[i]];
		else {
			tcnt++;
			t[p][s[i]] = tcnt;
			p = tcnt;
		}
	}
}

void dfs(int x) {
	siz[x] = 1;
	for (int i = 0; i < 26; i++) if (t[x][i]) {
		dfs(t[x][i]);
		siz[x] += siz[t[x][i]];
	}
}

char q[N];
int len;
void getss(int x) {
	len = 0;
	int p = 0;
	while (x) {
		if (p && x == 1) break;
		if (p != 0) x --;
		for (int i = 0; i < 26; i++) {
			if (t[p][i]) {
				if (siz[t[p][i]] >= x) {
					q[len++] = i;
					p = t[p][i];
					break;
				}
				else x -= siz[t[p][i]];
			}
		}
	}
	q[len] = 0;
}

LL dp[N][N];


void upd(LL &x, LL y) {
	x = min(x + y, M);
}

LL get(int mid) {
	getss(mid);
	for (int i = 1; i <= n; i++) {
		bool flag = 0;
		for (int j = 0; j < len; j++) {
			if (i + j > n) {
				R[i] = n + 1;
				flag = 1;
				break;
			}
			else if (s[i + j] > q[j]) {
				R[i] = i + j;
				flag = 1;
				break;
			}
			else if (s[i + j] < q[j]){
				R[i] = n + 1;
				flag = 1;
				break;
			}
		}
		if (!flag) R[i] = i + len;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;
	dp[1][0] = -1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i) upd(dp[i][j], dp[i - 1][j]);
			if (dp[i][j]) {
				if (R[i + 1] <= n) {
					upd(dp[R[i + 1]][j + 1], dp[i][j]);
				}
			}
		}
	}
	for (int i = 0; i < len; i++) q[i] += 'a';
	return dp[n][m];
}

int main() {
	read(n); read(m);
	scanf("%lld", &K);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) s[i] -= 'a';
	for (int i = 1; i <= n; i++) insert(i);
	dfs(0);
	int l = 1, r = siz[0];
	while (l < r) {
		int mid = (l + r) / 2;
		LL ret = get(mid);
		if (ret < K) r = mid;
		else l = mid + 1;
	}
	getss(l);
	for (int i = 0; i < len; i++) q[i] += 'a';
	printf("%s\n", q);
}