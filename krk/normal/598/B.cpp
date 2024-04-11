#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 10005;

char str[Maxn], oth[Maxn];
int slen;
int m;

int main()
{
	scanf("%s", str + 1); slen = strlen(str + 1);
	scanf("%d", &m);
	while (m--) {
		int l, r, k; scanf("%d %d %d", &l, &r, &k);
		for (int i = 1; i < l; i++)
			oth[i] = str[i];
		k %= r - l + 1;
		int cur = l;
		for (int i = r + 1 - k; i <= r; i++)
			oth[cur++] = str[i];
		for (int i = l; i <= r - k; i++)
			oth[cur++] = str[i];
		for (int i = r + 1; i <= slen; i++)
			oth[i] = str[i];
		for (int i = 1; i <= slen; i++)
			str[i] = oth[i];
	}
	printf("%s\n", str + 1);
	return 0;
}