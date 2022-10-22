#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxl = 26;

int T;
int n;
char str[Maxn];

int Solve(int l, int r, char ch)
{
	if (l == r) return str[l] != ch;
	int m = l + r >> 1;
	int res1 = 0, res2 = 0;
	for (int i = l; i <= m; i++)
		res1 += str[i] != ch;
	res1 += Solve(m + 1, r, ch + 1);
	for (int i = m + 1; i <= r; i++)
		res2 += str[i] != ch;
	res2 += Solve(l, m, ch + 1);
	return min(res1, res2);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		printf("%d\n", Solve(0, n - 1, 'a'));
	}
    return 0;
}