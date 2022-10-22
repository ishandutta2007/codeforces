#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

const int Maxn = 100005;

int n;
char s[Maxn];
int slen;
set <char> has[Maxn];

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s); slen = strlen(s);
		for (int i = 0; i < slen; i++)
			if (s[i] != '?') has[i].insert(s[i]);
	}
	for (int i = 0; i < slen; i++)
		if (has[i].empty()) printf("a");
		else if (has[i].size() == 1) printf("%c", *has[i].begin());
		else printf("?");
	printf("\n");
	return 0;
}