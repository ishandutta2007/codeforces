#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Inf = 1000000000;
const int Maxn = 4005;
const int Maxk = 805;

int n, k;
int C[Maxn][Maxn];
int sum[Maxn][Maxn];
ii lin[Maxk][Maxn];
int fr[Maxk], len[Maxk];
iii pnts[Maxk][Maxn];
int dp[Maxn][Maxk];

int Check(const ii &L, int x) 
{
	if (L.second > x) return L.first;
	if (L.second == 0) return L.first + sum[x][x];
	return L.first + sum[x][x] - sum[L.second - 1][x] - sum[x][L.second - 1] + sum[L.second - 1][L.second - 1];
}

int Inter(int minl, ii a, ii b)
{
	int l = minl, r = n;
	int res = -1;
	if (Check(a, minl) <= Check(b, minl)) return minl;
	if (Check(b, n) < Check(a, n)) return -1;
	while (l <= r) {
		int m = l + r >> 1;
		if (Check(a, m) <= Check(b, m)) { res = m; r = m - 1; }
		else l = m + 1;
	}
	return res;
}

void Insert(int tk, ii L)
{
	while (len[tk] - fr[tk] && Check(L, L.second) <= Check(lin[tk][len[tk] - 1], L.second)) len[tk]--;
	while (len[tk] - fr[tk] >= 2) {
		int x = Inter(pnts[tk][fr[tk]].first, L, lin[tk][len[tk] - 2]);
		if (x == -1) return;
		if (x < pnts[tk][len[tk] - 1].first || 
			x == pnts[tk][len[tk] - 1].first && Check(L, x) <= Check(lin[tk][len[tk] - 1], x)) len[tk]--;
		else break;
	}
	if (len[tk] - fr[tk] == 0) { lin[tk][len[tk]] = L; pnts[tk][len[tk]] = iii(0, L); len[tk]++; }
	else {
		int x = Inter(pnts[tk][fr[tk]].first, L, lin[tk][len[tk] - 1]);
		if (x == -1) return;
		lin[tk][len[tk]] = L; pnts[tk][len[tk]] = iii(x, L); len[tk]++;
	}
}

int Get(int tk, int x)
{
	if (len[tk] - fr[tk] == 0) return Inf;
	if (x < pnts[tk][fr[tk]].first) return Inf;
	while (fr[tk] + 1 < len[tk] && pnts[tk][fr[tk] + 1].first <= x) fr[tk]++;
	return Check(pnts[tk][fr[tk]].second, x);
}

int main()
{
	char s[1000005];
	int slen;
	scanf("%d %d", &n, &k); gets(s);
	for (int i = 1; i <= n; i++) {
		gets(s); slen = strlen(s);
		int j = 0;
		for (int l = 0; l < slen; l++)
			if (isdigit(s[l])) {
				sum[i][++j] = j <= i? s[l] - '0': 0;
				sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
	}
	fill((int*)dp, (int*)dp + Maxn * Maxk, Inf); dp[0][0] = 0; Insert(0, ii(0, 1));
	for (int i = 1; i <= n; i++)
		for (int j = k - 1; j >= 0; j--) {
			dp[i][j + 1] = Get(j, i);
			if (dp[i][j + 1] != Inf) Insert(j + 1, ii(dp[i][j + 1], i + 1));
		}
	printf("%d\n", dp[n][k]);
	return 0;
}