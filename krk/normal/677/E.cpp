#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;
typedef long long ll;

const ld magic = log(3.0l) / log(2.0l);

const int Maxn = 1005;
const int Maxm = 2015;
const int Maxd = 4;
const int mod = 1000000007;

int n;
char B[Maxn][Maxn];
int row[Maxd][Maxn][Maxn], col[Maxd][Maxn][Maxn];
int diag1[Maxd][Maxm][Maxn], diag2[Maxd][Maxm][Maxn];
int got[Maxd];
ii res;
bool found;

void getSimple(int r, int c, int m)
{
	for (int i = 0; i < Maxd; i++)
		got[i] = row[i][r][c + m] - row[i][r][c - m - 1] + col[i][r + m][c] - col[i][r - m - 1][c];
	got[B[r][c] - '0']--;
}

void getComplex(int r, int c, int m)
{
	for (int i = 0; i < Maxd; i++)
		got[i] = diag1[i][r + c][r + m] - diag1[i][r + c][r - m - 1] + diag2[i][r - c + Maxn][r + m] - diag2[i][r - c + Maxn][r - m - 1];
	got[B[r][c] - '0']--;
}

void Propose(ii cand)
{
	if (!found) { found = true; res = cand; }
	else {
		if (cand.first <= res.first && cand.second <= res.second) return;
		if (res.first <= cand.first && res.second <= cand.second) { res = cand; return; }
		if (cand.first > res.first) {
			int x = cand.first - res.first, y = res.second - cand.second;
			if (x > y * magic) res = cand;
		} else {
			int x = res.first - cand.first, y = cand.second - res.second;
			if (x < y * magic) res = cand;
		}
	}
}

int getRes()
{
	if (!found) return 0;
	int got = 1;
	while (res.first--) got = ll(got) * 2 % mod;
	while (res.second--) got = ll(got) * 3 % mod;
	return got;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char ch; scanf(" %c", &ch);
			B[i][j] = ch;
			for (int l = 0; l < Maxd; l++) {
				row[l][i][j] = row[l][i][j - 1] + (ch - '0' == l);
				col[l][i][j] = col[l][i - 1][j] + (ch - '0' == l);
				diag1[l][i + j][i] = diag1[l][i + j][i - 1] + (ch - '0' == l);
				diag2[l][i - j + Maxn][i] = diag2[l][i - j + Maxn][i - 1] + (ch - '0' == l);
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (B[i][j] != '0') {
			int l = 0, r = n;
			int my;
			while (l <= r) {
				int m = l + r >> 1;
				if (i - m >= 1 && i + m <= n && j - m >= 1 && j + m <= n) {
					getSimple(i, j, m);
					if (got[0] == 0) { my = m; l = m + 1; }
					else r = m - 1;
				} else r = m - 1;
			}
			getSimple(i, j, my);
			Propose(ii(got[2], got[3]));
			l = 0, r = n;
			while (l <= r) {
				int m = l + r >> 1;
				if (i - m >= 1 && i + m <= n && j - m >= 1 && j + m <= n) {
					getComplex(i, j, m);
					if (got[0] == 0) { my = m; l = m + 1; }
					else r = m - 1;
				} else r = m - 1;
			}
			getComplex(i, j, my);
			Propose(ii(got[2], got[3]));
		}
	printf("%d\n", getRes());
	return 0;
}