#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, p;
char s[Maxn];
int pos[Maxn], plen;
int res;

int F(char a, char b)
{
	int res = max(a, b) - min(a, b);
	return min(res, 26 - res);
}

int main()
{
	scanf("%d %d", &n, &p); p--;
	scanf("%s", s);
	for (int i = 0; i < n - i - 1; i++)
		if (s[i] != s[n - i - 1]) {
			res += F(s[i], s[n - i - 1]);
			pos[plen++] = i;
		}
	if (plen == 0) printf("0\n");
	else {
		if (p > n - p - 1) p = n - p - 1;
		if (p < pos[0]) res += pos[plen - 1] - p;
		else if (pos[plen - 1] < p) res += p - pos[0];
		else {
			int a = p - pos[0], b = pos[plen - 1] - p;
			res += 2 * min(a, b) + max(a, b);
		}
		printf("%d\n", res);
	}
	return 0;
}