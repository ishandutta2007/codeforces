#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 505;
const int Maxl = 3000006;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 0, 1};
const int dx[Maxd] = {0, -1, 1, 0};
const char let[Maxd] = {'U', 'L', 'R', 'D'};

int n, x0, y0;
int A[Maxn][Maxn];
int L[Maxn], R[Maxn], B[Maxn], T[Maxn];
bool taken[Maxn][Maxn];
char res[Maxl];
int rlen;

void turnOn(int y, int x)
{
	A[y][x] = 1;
	L[y] = min(L[y], x); R[y] = max(R[y], x);
	T[x] = min(T[x], y); B[x] = max(B[x], y);
}

void turnOff(int y, int x)
{
	A[y][x] = 0;
	if (L[y] == x)
		do L[y]++;
		while (L[y] <= n && !A[y][L[y]]);
	if (R[y] == x)
		do R[y]--;
		while (R[y] > 0 && !A[y][R[y]]);
	if (T[x] == y)
		do T[x]++;
		while (T[x] <= n && !A[T[x]][x]);
	if (B[x] == y)
		do B[x]--;
		while (B[x] > 0 && !A[B[x]][x]);
}

void Traverse(int y, int x)
{
	if (!A[y][x]) { res[rlen++] = '1'; turnOn(y, x); }
	taken[y][x] = true;
	if (L[y] < x && !taken[y][x - 1]) { res[rlen++] = 'L'; Traverse(y, x - 1); res[rlen++] = 'R'; }
	if (x < R[y] && !taken[y][x + 1]) { res[rlen++] = 'R'; Traverse(y, x + 1); res[rlen++] = 'L'; }
	if (T[x] < y && !taken[y - 1][x]) { res[rlen++] = 'U'; Traverse(y - 1, x); res[rlen++] = 'D'; }
	if (y < B[x] && !taken[y + 1][x]) { res[rlen++] = 'D'; Traverse(y + 1, x); res[rlen++] = 'U'; }
	res[rlen++] = '2'; turnOff(y, x);
}

bool Ok()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (A[i][j]) return false;
	return true;
}

int main()
{
	scanf("%d %d %d", &n, &x0, &y0);
	for (int i = 1; i <= n; i++) {
		L[i] = n + 1; R[i] = 0;
		T[i] = n + 1; B[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j] == 1) turnOn(i, j);
		}
	Traverse(x0, y0);
	if (Ok()) {
		printf("YES\n");
		res[rlen] = '\0'; printf("%s\n", res);
	} else printf("NO\n");
	return 0;
}