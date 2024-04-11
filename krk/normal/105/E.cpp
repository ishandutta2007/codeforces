#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 50;
const int Maxp = 3;
const int Maxm = 6 * 6 * 6;

int pw[Maxp];
int p[Maxp], m[Maxp], t[Maxp];
bool dp[Maxn][Maxn][Maxn][Maxm][8];
int res;

int Count(int p[], int val)
{
	int res = 0;
	for (int i = 0; i < Maxp; i++)
		res += p[i] == val;
	return res;
}

void Go(int p[], int st1, int st2)
{
	if (dp[p[0]][p[1]][p[2]][st1][st2]) return;
	res = max(max(res, p[0]), max(p[1], p[2]));
	dp[p[0]][p[1]][p[2]][st1][st2] = true;
	for (int i = 0; i < Maxp; i++) {
		int num = st1 / pw[i] % 6, s1 = num / 3, s2 = num % 3;
		if (s1 == 0 && Count(p, p[i]) == 1)
			for (int j = 0; j < Maxn; j++)
				if (abs(p[i] - j) <= m[i] && Count(p, j) == 0) {
					int sav = p[i]; p[i] = j; Go(p, st1 + 3 * pw[i], st2); p[i] = sav; 
				}
		if (s2 == 0 && !(st2 & 1 << i)) {
			for (int j = 0; j < Maxp; j++)
				if (!(st2 & 1 << j) && abs(p[i] - p[j]) == 1) {
					int sav = p[j]; p[j] = p[i]; Go(p, st1 + pw[i], st2 | 1 << j); p[j] = sav;
				}
			bool found = false;
			for (int j = 0; j < Maxp && !found; j++)
				found = st2 & 1 << j && abs(p[i] - p[j]) == 1;
			if (found) {
				int sav[Maxp];
				for (int j = 0; j < Maxp; j++) sav[j] = p[j];
				for (int j = 0; j < Maxn; j++) if (p[i] != j && abs(p[i] - j) <= t[i]) {
					for (int l = 0; l < Maxp; l++)
						if (l != i) p[l] = j;
					Go(p, st1 + 2 * pw[i], st2);
				}
				for (int j = 0; j < Maxp; j++) p[j] = sav[j];
			}
		}
		if (s2 == 1 && !(st2 & 1 << i))
			for (int j = 0; j < Maxp; j++)
				if (j != i && p[i] == p[j])
					for (int l = 0; l < Maxn; l++)
						if (Count(p, l) == 0 && abs(p[i] - l) <= t[i]) {
							int sav = p[j]; p[j] = l; Go(p, st1 + pw[i], st2 ^ 1 << j); p[j] = sav;
						}
	}
}

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxp; i++) pw[i] = pw[i - 1] * 6;
	for (int i = 0; i < Maxp; i++)
		scanf("%d %d %d", &p[i], &m[i], &t[i]);
	Go(p, 0, 0);
	printf("%d\n", res);
	return 0;
}