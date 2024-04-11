#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int MD = 51123987;

typedef long long LL;

const int NONE = 3;

const int N = 150;

int dp[151][51][51][51];
int next[N + 1][3];

int cnt[51][51][51];

char s[N + 1];
int c[3];
int fc[3];

int bn[51][51];

int count(int a, int b, int c, int fa, int fb, int fc) {
	if (fa < a || fb < b || fc < c)
		return 0;
	if ((!a && fa) || (!b && fb) || (!c && fc))
		return 0;
	if (!a || !b || !c)
		return 1;
	return (((bn[fa - 1][a - 1] * LL(bn[fb - 1][b - 1])) % MD) * LL(bn[fc - 1][c - 1])) % MD;
}

int n;

int main() {
	for (int i = 0; i <= 50; ++i) {
		bn[i][0] = 1;
		for (int k = 1; k <= i; ++k)
			bn[i][k] = (bn[i - 1][k - 1] + bn[i - 1][k]) % MD;
	}
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i] - 'a';
	next[n][0] = next[n][1] = next[n][2] = -1;
	next[n][s[n]] = n;
	for (int i = n - 1; i >= 1; --i) {
		for (int j = 0; j < 3; ++j)
			next[i][j] = next[i + 1][j];
		next[i][s[i]] = i;
	}
	for (c[0] = 0; c[0] <= 50; ++c[0]) {
		for (c[1] = 0; c[1] <= 50; ++c[1]) {
			for (c[2] = 0; c[2] <= 50; ++c[2]) {
				int res = 0;
				fc[0] = fc[1] = fc[2] = n / 3;
				if (n % 3 == 2) {
					++fc[0];
					++fc[1];
					++fc[2];
				}
				res = 0;
				if (n % 3) {
					for (int j = 0; j < 3; ++j) {
						if (n % 3 == 1) {
							++fc[j];
							res = (res + count(c[0], c[1], c[2], fc[0], fc[1], fc[2]));
							--fc[j];
						} else {
							--fc[j];
							res = (res + count(c[0], c[1], c[2], fc[0], fc[1], fc[2]));
							++fc[j];
						}
					}
				} else
					res = count(c[0], c[1], c[2], fc[0], fc[1], fc[2]);
				cnt[c[0]][c[1]][c[2]] = res;
			}
		}
	}
	s[0] = -1;
	int res = 0;
	dp[0][0][0][0] = 1;
	for (int len = 0; len <= n; ++len) {
		for (c[0] = 0; c[0] <= len && c[0] <= 50; ++c[0]) {
			for (c[1] = 0; c[1] <= len - c[0] && c[1] <= 50; ++c[1]) {
				for (c[2] = 0; c[2] <= len - c[0] - c[1] && c[2] <= 50; ++c[2]) {
					int cv = dp[len][c[0]][c[1]][c[2]];
					if (cv == 0)
						continue;
					res = (res + cnt[c[0]][c[1]][c[2]] * LL(cv)) % MD;
					for (int j = 0; j < 3; ++j) {
						if (s[len] != j && c[j] < 50 && len < n && next[len + 1][j] != -1) {
							++c[j];
							dp[next[len + 1][j]][c[0]][c[1]][c[2]] = (dp[next[len + 1][j]][c[0]][c[1]][c[2]] + cv) % MD;
							--c[j];
						}
					}
				}
			}
		}
	}
	printf("%d\n", res);
}