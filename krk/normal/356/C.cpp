#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;
const int Maxd = 5;

int dig[Maxd];
int n, s;
int res = Inf;

int Solve1()
{
	int tmp[Maxd];
	for (int i = 0; i < Maxd; i++)
		tmp[i] = dig[i];
	n = tmp[1] + tmp[2] + tmp[3] + tmp[4];
	int res = Inf;
	for (int i = 0; 4 * n >= s; i++) {
		if (s >= 3 * n) res = min(res, i + 2 * tmp[1] + tmp[2]);
		if (3 * (n - tmp[1]) <= s && s <= 4 * (n - tmp[1]) && tmp[1] <= tmp[3]) res = min(res, i + tmp[1] + tmp[2]);
		if (tmp[1] && tmp[3] && 3 * (n - 1) <= s && s <= 4 * (n - 1))
			res = min(res, i + 1 + 2 * (tmp[1] - 1) + tmp[2]);
		if (tmp[1] && tmp[2]) { tmp[1]--; tmp[2]--; tmp[3]++; }
		else if (tmp[1] >= 2) { tmp[1] -= 2; tmp[2]++; }
		else if (tmp[1] && tmp[3]) { tmp[1]--; tmp[3]--; tmp[4]++; }
		else if (tmp[2] >= 2) { tmp[2] -= 2; tmp[1]++; tmp[3]++; }
		else if (tmp[2] && tmp[3]) { tmp[2]--; tmp[3]--; tmp[1]++; tmp[4]++; }
		else break;
		n = tmp[1] + tmp[2] + tmp[3] + tmp[4];
	}
	return res;
}

int Solve2()
{
	int tmp[Maxd];
	for (int i = 0; i < Maxd; i++)
		tmp[i] = dig[i];
	n = tmp[1] + tmp[2] + tmp[3] + tmp[4];
	int res = Inf;
	for (int i = 0; 4 * n >= s; i++) {
		if (s >= 3 * n) res = min(res, i + 2 * tmp[1] + tmp[2]);
		if (tmp[1] && tmp[2]) { tmp[1]--; tmp[2]--; tmp[3]++; }
		else if (tmp[1] && tmp[3]) { tmp[1]--; tmp[3]--; tmp[4]++; }
		else if (tmp[1] >= 2) { tmp[1] -= 2; tmp[2]++; }
		else if (tmp[2] >= 2) { tmp[2] -= 2; tmp[1]++; tmp[3]++; }
		else if (tmp[2] && tmp[3]) { tmp[2]--; tmp[3]--; tmp[1]++; tmp[4]++; }
		else break;
		n = tmp[1] + tmp[2] + tmp[3] + tmp[4];
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		dig[a]++; s += a;
	}
	res = Solve1(); //in(Solve1(), Solve2());
	printf("%d\n", res == Inf? -1: res);
	return 0;
}