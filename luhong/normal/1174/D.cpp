#include <cstdio>
#define MN 1010000

int s[MN];
bool ok[MN];

int main()
{
	int n, x; scanf("%d%d", &n, &x);
	ok[0] = ok[x] = 1; 
	int tot = 0;
	for(int i = 1; i < (1 << n); i++)
		if(!ok[i]) s[++tot] = i, ok[i] = ok[x ^ i] = 1;
	printf("%d\n", tot);
	for(int i = 1; i <= tot; i++) printf("%d ", s[i] ^ s[i - 1]);
}