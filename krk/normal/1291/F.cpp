#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n, k;
bool el[Maxn];

bool Ask(int x)
{
	printf("? %d\n", x); fflush(stdout);
	char res; scanf(" %c", &res);
	return res == 'Y';
}

void Reset()
{
	printf("R\n"); fflush(stdout);
}

void Print(int d)
{
	printf("! %d\n", d); fflush(stdout);
}

void Solve(int l, int r)
{
	int siz = r - l + 1;
	if (siz == k / 2) {
		Reset();
		for (int i = l; i <= r; i++)
			if (Ask(i)) el[i] = true;
		return;
	}
	int m = l + r >> 1;
	Solve(l, m);
	Solve(m + 1, r);
	for (int i = l; i <= m; i += k / 2) {
		Reset();
		for (int j = m + 1; j <= r; j += k / 2) {
			for (int a = i; a < i + k / 2; a++)
				Ask(a);
			for (int b = j; b < j + k / 2; b++)
				if (Ask(b)) el[b] = true;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	if (k == 1)
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				Ask(i);
				if (Ask(j)) el[j] = true;
			}
	else Solve(1, n);
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += !el[i];
	Print(res);
    return 0;
}