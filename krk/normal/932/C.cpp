#include <bits/stdc++.h>
using namespace std;

int n, a, b;

const int Maxn = 1000005;

int P[Maxn];
int cur;

void Write(int len)
{
	for (int i = 0; i < len; i++) {
		int ni = (i + 1) % len;
		P[cur + i] = cur + ni;
	}
	cur += len;
}

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i * a <= n; i++) {
		int j = (n - i * a) / b;
		if (i * a + j * b == n) {
			for (int z = 0; z < i; z++)
				Write(a);
			for (int z = 0; z < j; z++)
				Write(b);
			for (int i = 0; i < n; i++)
				printf("%d%c", P[i] + 1, i + 1 < n? ' ': '\n');
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}