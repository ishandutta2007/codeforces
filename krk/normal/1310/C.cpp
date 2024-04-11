#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll lim = 2000000000000000000ll;
const int Maxn = 1005;

char s[Maxn];
int slen;
int rnk[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];

int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

bool Less(const int &a, const int &b) { return s[a] < s[b]; }

void buildSA()
{
	for (int i = 0; i < slen; i++)
		cur[i] = i;
	sort(cur, cur + slen, Less);
	for (int i = 0; i < slen; i++) {
		dif1[i] = i == 0 || s[cur[i - 1]] != s[cur[i]];
		dif2[i] = false;
	}
	for (int h = 1; h < slen; h <<= 1) {
		int buck = 0;
		for (int i = 0, j; i < slen; i = j) {
			j = i + 1;
			while (j < slen && !dif1[j]) j++;
			nxt[i] = j;
			buck++;
		}
		if (buck == slen) break;
		for (int i = 0; i < slen; i = nxt[i]) {
			cnt[i] = 0;
			for (int j = i; j < nxt[i]; j++)
				rnk[cur[j]] = i;
		}
		cnt[rnk[slen - h]]++; dif2[rnk[slen - h]] = true;
		for (int i = 0; i < slen; i = nxt[i]) {
			for (int j = i; j < nxt[i]; j++) {
				int s = cur[j] - h;
				if (s >= 0) {
					int head = rnk[s];
					rnk[s] = head + cnt[head]++;
					dif2[rnk[s]] = true;
				}
			}
			for (int j = i; j < nxt[i]; j++) {
				int s = cur[j] - h;
				if (s >= 0 && dif2[rnk[s]])
					for (int k = rnk[s] + 1; !dif1[k] && dif2[k]; k++) dif2[k] = false;
			}
		}
		for (int i = 0; i < slen; i++) {
			cur[rnk[i]] = i;
			dif1[i] |= dif2[i];
		}
	}
}

void calcLCP()
{
	bef[cur[0]] = -1;
	for (int i = 1; i < slen; i++) bef[cur[i]] = cur[i - 1];
	int l = 0;
	for (int i = 0; i < slen; i++) if (bef[i] != -1) {
		while (bef[i] + l < slen && i + l < slen && s[bef[i] + l] == s[i + l]) l++;
		plcp[i] = l;
		l = max(l - 1, 0);
	}
	for (int i = 0; i < slen; i++)
		lcp[i] = plcp[cur[i]];
}

int n, m;
ll k;
ll dp[Maxn][Maxn];
int mn[Maxn][Maxn];

ii getString(int ind)
{
	for (int i = 0; i < n; i++) {
		int sub = n - cur[i] - lcp[i];
		if (ind < sub) return ii(i, lcp[i] + ind);
		ind -= sub;
	}
	return ii(-1, -1);
}

ll Get(int ind)
{
	ii my = getString(ind);
	fill((ll*)dp, (ll*)dp + Maxn * Maxn, 0ll);
	dp[0][0] = 1; dp[0][1] = -1;
	for (int i = 0; i < m; i++) {
		ll cur = 0;
		for (int j = 0; j < n; j++) {
			cur = min(cur + dp[i][j], lim);
			if (rnk[j] >= my.first) {
				int myind = min(my.second, mn[my.first][rnk[j]]);
				int nj = j + myind + 1;
				dp[i + 1][nj] = min(dp[i + 1][nj] + cur, lim);
			}
		}
	}
	ll cur = 0;
	for (int j = 0; j <= n; j++)
		cur = min(cur + dp[m][j], lim);
	return cur;
}

int main()
{
	scanf("%d %d %I64d", &n, &m, &k);
	scanf("%s", s);
	slen = n;
	buildSA();
	for (int i = 0; i < n; i++)
		rnk[cur[i]] = i;
	calcLCP();
	int all = 0;
	for (int i = 0; i < n; i++)
		all += n - cur[i] - lcp[i];
	for (int i = 0; i < n; i++) {
		mn[i][i] = n - cur[i];
		for (int j = i + 1; j < n; j++)
			mn[i][j] = min(mn[i][j - 1], lcp[j]);
	}
	int lef = 0, rig = all - 1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Get(mid) >= k) lef = mid + 1;
		else rig = mid - 1;
	}
	ii my = getString(rig);
	for (int i = 0; i <= my.second; i++)
		printf("%c", s[cur[my.first] + i]);
	printf("\n");
    return 0;
}