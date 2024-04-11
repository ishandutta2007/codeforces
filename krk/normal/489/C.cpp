#include <cstdio>
using namespace std;

const int Maxn = 105;

int n, s;
char mn[Maxn], mx[Maxn];

bool Possible(int m, int s, bool tk = true)
{
	int mn = tk? 0: 1;
	int mx = 9 * m;
	return mn <= s && s <= mx;
}

void genMin(int lvl, int s)
{
	if (lvl < n) {
		int from = lvl? 0: 1;
		for (int i = from; i <= 9; i++)
			if (Possible(n - lvl - 1, s - i)) {
				mn[lvl] = '0' + i; genMin(lvl + 1, s - i); break;
			}
	}
}

void genMax(int lvl, int s)
{
	if (lvl < n) {
		int to = lvl? 0: 1;
		for (int i = 9; i >= to; i--)
			if (Possible(n - lvl - 1, s - i)) {
				mx[lvl] = '0' + i; genMax(lvl + 1, s - i); break;
			}
	}
}

int main()
{
	scanf("%d %d", &n, &s);
	if (n == 1 && s == 0) { printf("0 0\n"); return 0; }
	if (Possible(n, s, false)) {
		genMin(0, s); mn[n] = '\0';
		genMax(0, s); mx[n] = '\0';
		printf("%s %s\n", mn, mx);
	} else printf("-1 -1\n");
	return 0;
}