#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 300000;


int n, m;
char s[MAXN];
char t[MAXN];

int lstt[30];
int lsts[30];
int nxs[MAXN];
int nxt[MAXN];

const ll P = 239171;
const ll M1 = 1000000007;
const ll M2 = 1000000009;

int fl[MAXN];
ll pw1[MAXN];
ll pw2[MAXN];
int tt[26];
int go[26];

int main() {
	scanf("%d%d", &n, &m);
	pw1[0] = 1;
	pw2[0] = 1;
	for (int i = 1; i <= m; ++i)
		pw1[i] = (pw1[i - 1] * P) % M1, pw2[i] = (pw2[i - 1] * P) % M2;
	scanf(" %s", s);
	scanf(" %s", t);
	for (int i = 0; i < 26; ++i)
		tt[i] = -1;
	for (int i = 0; i < m; ++i)
		tt[t[i] - 'a'] = i;
	for (int i = 0; i < 26; ++i)
		lstt[i] = -1;
	for (int i = 0; i < 26; ++i)
		lsts[i] = -1;
	for (int i = 0; i < m; ++i)
		nxt[i] = n;
	for (int i = 0; i < n; ++i)
		nxs[i] = n;
	for (int i = 0; i < m; ++i) {
		if (lstt[t[i] - 'a'] != -1)
			nxt[lstt[t[i] - 'a']] = i - lstt[t[i] - 'a'];
		lstt[t[i] - 'a'] = i;
	}
	ll hst1 = 0;
	ll hst2 = 0;
	ll hss1 = 0;
	ll hss2 = 0;
	for (int i = 0; i < m; ++i) {
		hst1 = (hst1 * P + nxt[i]) % M1;
		hst2 = (hst2 * P + nxt[i]) % M2;
	}

	int now = 0;
	for (int i = 0; i < n; ++i) {
		hss1 = (hss1 * P) % M1;
		hss2 = (hss2 * P) % M2;
		if (i - now >= m) {
			hss1 = (hss1 + M1 * M1 - nxs[now] * pw1[m]) % M1;
			hss2 = (hss2 + M2 * M2 - nxs[now] * pw2[m]) % M2;
			++now;
		}
		hss1 = (hss1 + nxs[i]) % M1;
		hss2 = (hss2 + nxs[i]) % M2;
		if (lsts[s[i] - 'a'] >= now) {
			int k = lsts[s[i] - 'a'];
			nxs[k] = i - k;
			hss1 = (hss1 + M1 * M1 - n * pw1[i - k] + nxs[k] * pw1[i - k]) % M1;
			hss2 = (hss2 + M2 * M2 - n * pw2[i - k] + nxs[k] * pw2[i - k]) % M2;
		}
		lsts[s[i] - 'a'] = i;
		if (i >= m - 1 && hss1 == hst1 && hss2 == hst2)
			fl[i - m + 1] = 1;
		else
			fl[i - m + 1] = 0;
	}

	for (int i = 0; i <= n - m; ++i) {
		if (!fl[i])
			continue;
		for (int j = 0; j < 26; ++j)
			go[j] = -1;
		for (int j = 0; j < 26; ++j) {
			if (tt[j] == -1)
				continue;
			int gg = s[i + tt[j]] - 'a';
			if (go[j] != -1 && go[j] != gg) {
				fl[i] = 0;
				break;
			}
			if (go[gg] != -1 && go[gg] != j) {
				fl[i] = 0;
				break;
			}
			go[j] = gg;
			go[gg] = j;
		}
	}
	int cnt = 0;
	for (int i = 0; i <= n - m; ++i)
		if (fl[i])
			++cnt;
	printf("%d\n", cnt);
	for (int i = 0; i <= n - m; ++i)
		if (fl[i])
			printf("%d ", i + 1);

	return 0;
}