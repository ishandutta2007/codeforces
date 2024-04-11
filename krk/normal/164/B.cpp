#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 2000005;
const int Inf = 1000000000;

int la, lb;
int a[Maxn];
int b[Maxn];
int pos[Maxn];
int tpos[Maxn];
int res;

int getNxt(int val, int p)
{
	if (pos[val] >= p) return pos[val];
	if (pos[val] + lb >= p) return pos[val] + lb;
	return Maxn; 
}

int main()
{
	scanf("%d %d", &la, &lb);
	for (int i = 0; i < la; i++) {
		scanf("%d", &a[i]); a[la + i] = a[i];
	}
	fill(pos, pos + Maxn, Inf);
	for (int i = 0; i < lb; i++) {
		scanf("%d", &b[i]); b[lb + i] = b[i];
		pos[b[i]] = i;
	}
	fill(tpos, tpos + 2 * la, Inf);
	int j = -1;
	for (int i = 0; i < 2 * la; i++) if (getNxt(a[i], -1) < Inf) {
		tpos[i] = getNxt(a[i], -1);
		for (int k = i + 1; k < 2 * la; k++)
			if (getNxt(a[k], tpos[k - 1] + 1) < tpos[k])
				tpos[k] = getNxt(a[k], tpos[k - 1] + 1);
			else break;
		if (j < i) j = i;
		while (j < 2 * la && j - i + 1 <= la && tpos[j] - tpos[i] + 1 <= lb) j++;
		res = max(res, j - i);
	}
	printf("%d\n", res);
	return 0;
}