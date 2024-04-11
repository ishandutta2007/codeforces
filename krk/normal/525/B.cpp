#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

char str[Maxn];
int slen;
int m;
int had[Maxn];

int main()
{
	scanf("%s", str); slen = strlen(str);
	scanf("%d", &m);
	while (m--) {
		int a; scanf("%d", &a); a--;
		had[a]++;
	}
	int cur = 0;
	for (int i = 0; i <= slen - i - 1; i++) {
		cur += had[i];
		if (cur % 2) swap(str[i], str[slen - i - 1]);
	}
	printf("%s\n", str);
	return 0;
}