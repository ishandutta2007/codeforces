#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int Maxn = 100005;

const string allow = "AHIMOTUVWXY";

char s[Maxn];
int slen;

int main()
{
	scanf("%s", s); slen = strlen(s);
	int i, j;
	for (i = 0; i < slen; i++)
		if (allow.find(s[i]) == string::npos)
			break;
	if (i < slen) { printf("NO\n"); return 0; }
	i = 0, j = slen - 1;
	while (i < j && s[i] == s[j]) i++, j--;
	printf("%s\n", i < j? "NO": "YES");
	return 0;
}