#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 100005;

char s[Maxn];
int slen;
int st;
int thas;
int lst;
int res[Maxn];

int main()
{
	scanf("%s", s); slen = strlen(s);
	for (int i = 0; i < slen; i++)
		if (s[i] == '(') st++;
		else {
			st--;
			if (st < 0) { printf("-1\n"); return 0; }
			if (s[i] == '#') { lst = i; res[thas]++; thas++; }
		}
	res[thas - 1] += st;
	st = 0;
	int cur = 0;
	for (int i = 0; i < slen; i++)
		if (s[i] == '(') st++;
		else if (s[i] == ')') {
			st--;
			if (st < 0) { printf("-1\n"); return 0; }
		} else {
			st -= res[cur]; cur++;
			if (st < 0) { printf("-1\n"); return 0; }
		}
	for (int i = 0; i < thas; i++)
		printf("%d\n", res[i]);
	return 0;
}