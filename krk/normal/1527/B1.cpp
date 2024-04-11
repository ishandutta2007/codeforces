#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
int n;
char str[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		int one = 0, two = 0;
		for (int i = 0; i <= n - 1 - i; i++) if (str[i] == '0')
			if (i < n - 1 - i)
				two++;
			else if (i == n - 1 - i)
				one++;
		if (one)
			if (two) printf("ALICE\n");
			else printf("BOB\n");
		else if (two) printf("BOB\n");
			else printf("DRAW\n");
	}
    return 0;
}