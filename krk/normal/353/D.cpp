#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

char s[Maxn];
int len;
int tot;
int res;

int main()
{
	scanf("%s", s); len = strlen(s);
	int nil = 0;
	while (nil < len && s[nil] == 'F') nil++;
	for (int i = nil; i < len; i++)
		tot += s[i] == 'F';
	int cur = nil;
	for (int i = nil; i < len; i++)
		if (s[i] == 'F') {
			res = max(res, i - cur + tot - (cur - nil + 1));
			cur++;
		}
	printf("%d\n", res);
	return 0;
}