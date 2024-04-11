#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

int m;
int freq[Maxl];
char str[Maxn];
int slen;

bool Check(char let)
{
	int lst = -1;
	for (int i = 0; i < slen; i++) {
		if (str[i] <= let) lst = i;
		if (i - lst >= m) return false;
	}
	return true;
}

int Get(char let)
{
	int res = 0, lst = -1;
	int was = 0;
	for (int i = 0; i < slen; i++) {
		if (str[i] < let) lst = i;
		if (str[i] == let) was = i;
		if (i - lst >= m) { res++; lst = was; }
	}
	return res;
}

int main()
{
	scanf("%d", &m);
	scanf("%s", str); slen = strlen(str);
	for (int i = 0; i < slen; i++)
		freq[str[i] - 'a']++;
	char let = 'a';
	while (!Check(let)) let++;
	int res = Get(let);
	freq[let - 'a'] = res;
	for (char ch = 'a'; ch <= let; ch++)
		while (freq[ch - 'a']--)
			printf("%c", ch);
	printf("\n");
	return 0;
}