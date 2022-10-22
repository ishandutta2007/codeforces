#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

char tmp[Maxn];
bool ok[Maxl];
int cnt;
int n;
bool tk[Maxl];

int main()
{
	fill(ok, ok + Maxl, true); cnt = Maxl;
	scanf("%d", &n);
	int i;
	for (i = 1; i < n; i++) {
		char ch; scanf(" %c", &ch);
		if (ch == '.') {
			scanf("%s", tmp);
			int slen = strlen(tmp);
			for (int j = 0; j < slen; j++)
				if (ok[tmp[j] - 'a']) { ok[tmp[j] - 'a'] = false; cnt--; }
		} else if (ch == '!') {
			scanf("%s", tmp);
			int slen = strlen(tmp);
			fill(tk, tk + Maxl, false);
			for (int j = 0; j < slen; j++)
				tk[tmp[j] - 'a'] = true;
			for (int j = 0; j < Maxl; j++)
				if (!tk[j] && ok[j]) { ok[j] = false; cnt--; }
		} else {
			char let; scanf(" %c", &let);
			if (ok[let - 'a']) { ok[let - 'a'] = false; cnt--; }
		}
		if (cnt == 1) break;
	}
	int res = 0;
	for (i++; i <= n; i++) {
		char ch; scanf(" %c", &ch);
		scanf("%s", tmp);
		if (ch == '.') ;
		else if (ch == '!') res++;
		else if (i < n) res++;
	}
	printf("%d\n", res);
	return 0;
}