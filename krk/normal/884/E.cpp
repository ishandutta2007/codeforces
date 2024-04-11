#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <cassert>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const int Maxn = 1 << 12;
const int Maxm = 1 << 8;
const int Maxb = 64;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};
const int Maxs = (1 << 15) + 5;

int n, m;
int nd;
char let[Maxn + 2];
ull B[Maxn][Maxm];
int par[Maxs], siz[Maxs];
int res;
int cnt[Maxs];
int st[Maxs], en[Maxs];
int el[Maxs];

ull Get(char ch)
{
	if (isdigit(ch)) return ch - '0';
	return 10 + (ch - 'A');
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	nd = m / Maxb + bool(m % Maxb);
	for (int i = 0; i < n; i++) {
		scanf("%s", let);
		int cur = nd - 1, pl = m / 4 % 16; if (pl == 0) pl = 16;
		for (int j = 0; j < m / 4; j++) {
			ull num = Get(let[j]);
			if (pl == 0) { pl = 16; cur--; }
			B[i][cur] = ((B[i][cur] << ull(4)) | num);
			pl--;
		}
		assert(cur == 0 && pl == 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (B[i][j / Maxb] & ull(1) << ull(j % Maxb)) {
				res++;
				par[m + j] = m + j; siz[m + j] = 1;
				bool was = i > 0 && (B[i - 1][j / Maxb] & ull(1) << ull(j % Maxb));
				if (was) res -= unionSet(m + j, j);
				was = j > 0 && (B[i][(j - 1) / Maxb] & ull(1) << ull((j - 1) % Maxb));
				if (was) res -= unionSet(m + j - 1, m + j);
			}
		for (int j = 0; j < m; j++)
			if (B[i][j / Maxb] & ull(1) << ull(j % Maxb))
				cnt[getPar(m + j)]++;
		int cur = 0;
		for (int j = 0; j < m + m; j++) {
			st[j] = en[j] = cur;
			cur += cnt[j];
		}
		for (int j = 0; j < m; j++)
			if (B[i][j / Maxb] & ull(1) << ull(j % Maxb))
				el[en[getPar(m + j)]++] = j;
		for (int j = 0; j < m; j++)
			par[j] = j, siz[j] = 1;
		for (int j = 0; j < m + m; j++) {
			for (int k = st[j]; k + 1 < en[j]; k++)
				unionSet(el[k], el[k + 1]);
			cnt[j] = 0;
		}
	}
	printf("%d\n", res);
	return 0;
}