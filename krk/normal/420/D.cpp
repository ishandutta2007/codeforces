#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxe = 2 * Maxn;
const int Maxm = 8388608;

int n, m;
int cup[Maxn];
bool taken[Maxn];
int seq[Maxe];
int L, R;
int pl[Maxm];

void Create(int v, int l, int r)
{
	if (l == r) { if (l > Maxn) pl[v] = 1; }
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		pl[v] = pl[2 * v] + pl[2 * v + 1];
	}
}

int getInd(int v, int l, int r, int need)
{
	if (l == r) { pl[v] = 0; return l; }
	else {
		int res;
		int m = l + r >> 1;
		if (need <= pl[2 * v]) res = getInd(2 * v, l, m, need);
		else res = getInd(2 * v + 1, m + 1, r, need - pl[2 * v]);
		pl[v] = pl[2 * v] + pl[2 * v + 1];
		return res;
	}
}

void addPos(int v, int l, int r, int x)
{
	if (l == r) pl[v] = 1;
	else {
		int m = l + r >> 1;
		if (x <= m) addPos(2 * v, l, m, x);
		else addPos(2 * v + 1, m + 1, r, x);
		pl[v] = pl[2 * v] + pl[2 * v + 1];
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cup[i] = -1;
		seq[Maxn + i] = i;
	}
	L = Maxn - m + 1; R = Maxn + n;
	Create(1, L, R);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d %d", &x, &y);
		int ind = getInd(1, L, R, y);
		if (cup[seq[ind]] != -1 && cup[seq[ind]] != x ||
			cup[seq[ind]] == -1 && taken[x]) {
			printf("-1\n"); return 0;
		}
		cup[seq[ind]] = x; taken[x] = true;
		seq[Maxn - i] = seq[ind]; addPos(1, L, R, Maxn - i);
	}
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		if (cup[i] == -1) {
			while (taken[cur]) cur++;
			cup[i] = cur++;
		}
		printf("%d%c", cup[i], i + 1 <= n? ' ': '\n');
	}
	return 0;
}