#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 4;
const int Inf = 1000000000;

int lft[Maxn]; 
int res = Inf;
int wth[Maxn];

void Add(int tmp[], int twos[], int has, int l, int r)
{
	for (int i = l; i <= r; i++)
		while (has && twos[i]) { tmp[i] *= 2; has--; twos[i]--; }
}

bool Solve(int &res, int tmp[])
{
	int twos[Maxn];
	for (int i = 0; i < Maxn; i++) {
		tmp[i] = lft[i]; twos[i] = 0;
		while (tmp[i] % 2 == 0) { tmp[i] /= 2; twos[i]++; }
	}
	if (ll(tmp[0]) * tmp[1] != ll(tmp[2]) * tmp[3])
		return false;
	int a = twos[0] + twos[1];
	int b = twos[2] + twos[3];
	int mn = min(a, b), mx = max(a, b);
	res = mx - mn;
	Add(tmp, twos, mn, 0, 1); Add(tmp, twos, mn, 2, 3);
	return true;
}

void Gen(int lvl, int cur)
{
	if (lvl == Maxn) {
		int tmp[Maxn];
		int add;
		if (Solve(add, tmp)) {
			cur += add;
			if (cur < res) {
				res = cur;
				for (int i = 0; i < Maxn; i++)
					wth[i] = tmp[i];
			}
		}
	} else {
		Gen(lvl + 1, cur);
		int i;
		for (i = 1; lft[lvl] % 3 == 0; i++) {
			lft[lvl] /= 3; lft[lvl] *= 2;
			Gen(lvl + 1, cur + i);
		}
		while (i > 1) {
			lft[lvl] /= 2; lft[lvl] *= 3;
			i--;
		}
	}
}

int main()
{
	for (int i = 0; i < Maxn; i++)
		scanf("%d", &lft[i]);
	Gen(0, 0);
	if (res == Inf) printf("-1\n");
	else {
		printf("%d\n", res);
		printf("%d %d\n", wth[0], wth[1]);
		printf("%d %d\n", wth[2], wth[3]);
	}
	return 0;
}