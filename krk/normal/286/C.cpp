#include <cstdio>
using namespace std;

const int Maxn = 1000005;

int n;
int p[Maxn], q[Maxn];
int t;
int S[Maxn], len;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	scanf("%d", &t);
	while (t--) {
		int a; scanf("%d", &a);
		q[a - 1] = true;
	}
	for (int i = n - 1; i >= 0; i--)
		if (q[i] || len == 0 || p[i] != S[len - 1]) { S[len++] = p[i]; p[i] = -p[i]; }
		else len--;
	if (len == 0) {
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("%d%c", p[i], i + 1 < n? ' ': '\n');
	} else printf("NO\n");
	return 0;
}