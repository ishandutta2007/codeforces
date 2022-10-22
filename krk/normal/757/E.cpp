#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxb = 30;
const int Maxn = 1000005;

int inv[Maxb];
int has[Maxn][Maxb], acc[Maxn][Maxb];
int mx[Maxn], cnt[Maxn];
int q;
int r, n;
int dv[Maxb];
int dlen;

int Inv(int a)
{
	int res = 1;
	int p = mod - 2;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Solve(int lvl)
{
	if (lvl >= dlen) return 1;
	int res = Solve(lvl + 1);
	return ll(res) * (ll(acc[r][dv[lvl] - 1]) * 2 + ll(has[r][dv[lvl]])) % mod;
}

int main() 
{
	for (int i = 1; i < Maxb; i++)
		inv[i] = Inv(i);
	for (int i = 1; i < Maxn; i++) {
		has[i][0] = 1;
		for (int j = 1; j < Maxb; j++)
			has[i][j] = ll(has[i][j - 1]) * (i + j - 1) % mod * inv[j] % mod;
		acc[i][0] = has[i][0];
		for (int j = 1; j < Maxb; j++)
			acc[i][j] = (acc[i][j - 1] + has[i][j]) % mod;
	}
	mx[1] = 1;
	for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
		for (int j = i; j < Maxn; j += i) {
			mx[j] = i; cnt[j]++;
		}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &r, &n);
		if (r == 0) printf("%d\n", (1 << cnt[n]));
		else {
			dlen = 0;
			int cur = n;
			while (cur > 1) {
				int val = mx[cur];
				int got = 0;
				while (cur % val == 0) { cur /= val; got++; }
				dv[dlen++] = got;
			}
			printf("%d\n", Solve(0));
		}
	}
    return 0;
}