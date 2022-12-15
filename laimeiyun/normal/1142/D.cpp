#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 222222

char s[N];
int n, st[N][22];
LL answer;

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = n - 1; i >= 0; i--)
	{
		int d = s[i] - '0';
		for (int j = 0; j <= 10; j++)
		{
			if (j <= d)
				st[i][j] = 0;
			else
				st[i][j] = st[i + 1][(j * (j - 1) / 2 + d + 10) % 11] + 1;
		}

		if (d != 0)
			answer += st[i + 1][d] + 1;
	}
	printf("%lld\n", answer);
}