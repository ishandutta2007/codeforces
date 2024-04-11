#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 500005;

int n, k;
char s[Maxn];
int slen;

int Solve(char a, char b)
{
	int res = 0;
	for (int i = 0; i < slen; i++)
		if (i % 2 == 0) res += s[i] != a;
		else res += s[i] != b;
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s); slen = strlen(s);
	if (k == 2) {
		int a = Solve('A', 'B'), b = Solve('B', 'A');
		printf("%d\n", min(a, b));
		for (int i = 0; i < slen; i++)
			if (i % 2 == 0 && a <= b || i % 2 && a > b)
				printf("A");
			else printf("B");
		printf("\n");
	} else {
		int res = 0;
		for (int i = 1; i < slen; i++)
			if (s[i] == s[i - 1]) {
				res++;
				char col = 'A';
				while (s[i] == col || i + 1 < slen && s[i + 1] == col) col++;
				s[i] = col;
			}
		printf("%d\n", res);
		printf("%s\n", s);
	}
	return 0;
}