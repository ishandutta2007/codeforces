#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

char str[Maxn];
int slen;
char best[Maxn];
vector <char> V;

int main()
{
	scanf("%s", str);
	slen = strlen(str);
	best[slen] = 'z';
	for (int i = slen - 1; i >= 0; i--)
		best[i] = min(str[i], best[i + 1]);
	int cur = 0;
	while (!V.empty() || cur < slen)
		if (V.empty() || best[cur] < V.back()) V.push_back(str[cur++]);
		else { printf("%c", V.back()); V.pop_back(); }
	printf("\n");
	return 0;
}