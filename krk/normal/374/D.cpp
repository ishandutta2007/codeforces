#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 4194304;

int n, m;
int a[Maxn];
int has[Maxm];
int seq[Maxn], len;

void Create(int v, int l, int r)
{
	has[v] = r - l + 1;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

int getInd(int v, int l, int r, int need)
{
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		if (need <= has[2 * v]) return getInd(2 * v, l, m, need);
		else return getInd(2 * v + 1, m + 1, r, need - has[2 * v]);
	}
}

void Erase(int v, int l, int r, int need)
{
	has[v]--;
	if (l < r) {
		int m = l + r >> 1;
		if (need <= has[2 * v]) Erase(2 * v, l, m, need);
		else Erase(2 * v + 1, m + 1, r, need - has[2 * v]);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	for (int f = 0; f < n; f++) {
		int op; scanf("%d", &op);
		if (op == -1) {
			int ind = upper_bound(a, a + m, len) - a;
			for (int i = ind - 1; i >= 0; i--) {
				Erase(1, 1, n, a[i]); len--;
			}
		} else {
			len++;
			seq[getInd(1, 1, n, len)] = op;
		}
	}
	if (len == 0) printf("Poor stack!");
	else for (int i = 1; i <= len; i++)
			printf("%d", seq[getInd(1, 1, n, i)]);
	printf("\n");
	return 0;
}