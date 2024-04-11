#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n, m;
char s[5];
int a, b;
int l, r;
int res;
int tk[Maxn];
int B[Maxn][Maxn];

bool Enough(int lim)
{
	fill(tk, tk + m, 0);
	int i = 0, j = 0;
	for (int c = 0; c < a; c++) {
		if (tk[j] < lim) tk[j]++;
		else return false;
		j++;
		if (j == m) { i++; j = 0; }
	}
	int ct = 0;
	for (int j = 0; j < m; j++)
		ct += min(n - tk[j], 2 * (lim - tk[j]));
	return ct >= b;
}

void genAns(int lim)
{
	fill(tk, tk + m, 0);
	int i = 0, j = 0;
	for (int c = 0; c < a; c++) {
		tk[j]++;
		B[i][j] = 3;
		j++;
		if (j == m) { i++; j = 0; }
	}
	for (int j = 0; j < m; j++) {
		int tt = min(b, min(n - tk[j], 2 * (lim - tk[j])));
		int i = tk[j];
		while (tt--) { B[i][j] = 1 + b % 2; b--; i++; }
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%s", &s);
			int cnt = s[0] - '0' + s[1] - '0';
			if (cnt == 2) a++;
			else if (cnt == 1) b++;
		}
	l = 0, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Enough(mid)) { res = mid; r = mid - 1; }
		else l = mid + 1;
	}
	genAns(res);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%c%c%c", (B[i][j] & 2)? '1': '0', (B[i][j] & 1)? '1': '0', j + 1 < m? ' ': '\n');
	return 0;
}