#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

char s[Maxn];
int slen;
int res;

int main()
{
	scanf("%s", s); slen = strlen(s);
	for (int i = 1; i < slen; i++)
		if (s[i] == s[i - 1]) {
			s[i] = 'a';
			while (s[i] == s[i - 1] || (i + 1 < slen && s[i] == s[i + 1])) s[i]++;
			i++;
		}
	printf("%s\n", s);
	return 0;
}