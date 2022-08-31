#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1000010;

char s[MAXN * 2];
int bl[MAXN * 2];
int dd[MAXN * 2];
int aa[MAXN];
int c[MAXN];
int newc[MAXN];
int p[MAXN];
int newp[MAXN];
int mx = -MAXN;
int cnt[MAXN];
int n;

int nm(int x) {
	return (x < 0 ? x + n : (x >= n ? x - n : x));
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	memcpy(s + n, s, sizeof(s[0]) * n);
	bl[0] = 0;
	for (int i = 0; i < 2 * n; ++i)
		bl[i + 1] = bl[i] + (s[i] == '(' ? 1 : -1);

	int l = 0;
	int r = 0;
	for (int i = 0; i <= n; ++i) {
		while (r - l > 0 && dd[r - 1] > bl[i])
			--r;
		dd[r++] = bl[i];
	}

	for (int i = 0; i < n; ++i) {
		aa[i] = dd[l] - bl[i];
		mx = max(mx, aa[i]);
		if (dd[l] == bl[i])
			++l;
		while (r - l > 0 && dd[r - 1] > bl[i + n + 1])
			--r;
		dd[r++] = bl[i + n + 1];
	}

	for (int i = 0; i < n; ++i)
		c[i] = (s[i] == '(' ? 0 : 1);

	for (int i = 0; i < n; ++i)
		++cnt[c[i] + 1];
	for (int i = 0; i < n; ++i)
		cnt[i + 1] += cnt[i];

	for (int i = 0; i < n; ++i)
		p[cnt[c[i]]++] = i;

	for (int k = 0; (1 << k) < n; ++k) {
		int sh = (1 << k);
		for (int i = 0; i < n; ++i)
			p[i] = nm(p[i] - sh);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i)
			++cnt[c[i] + 1];
		for (int i = 0; i < n; ++i)
			cnt[i + 1] += cnt[i];
		for (int i = 0; i < n; ++i)
			newp[cnt[c[p[i]]]++] = p[i];
		memcpy(p, newp, sizeof(newp));
		newc[p[0]] = 0;
		for (int i = 1; i < n; ++i) {
			if (c[p[i]] == c[p[i - 1]] && c[nm(p[i] + sh)] == c[nm(p[i - 1] + sh)])
				newc[p[i]] = newc[p[i - 1]];
			else
				newc[p[i]] = newc[p[i - 1]] + 1;
		}
		memcpy(c, newc, sizeof(newc));
	}



	int bst = -1;
	for (int i = 0; i < n; ++i)
		if (aa[i] == mx && (bst == -1 || c[i] < c[bst]))
			bst = i;

	mx = -mx;
	mx = max(mx, 0);

	for (int i = 0; i < mx; ++i)
		printf("(");
	for (int i = bst; i < bst + n; ++i)
		printf("%c", s[i]);

	int k = bl[n] + mx;
	for (int i = 0; i < k; ++i)
		printf(")");
	return 0;
}