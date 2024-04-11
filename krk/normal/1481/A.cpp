#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int px, py;
char s[Maxn];
int slen;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &px, &py);
		scanf("%s", s); slen = strlen(s);
		int U = 0, D = 0, R = 0, L = 0;
		for (int i = 0; i < slen; i++)
			if (s[i] == 'U') U++;
			else if (s[i] == 'D') D++;
			else if (s[i] == 'R') R++;
			else if (s[i] == 'L') L++;
		if (U - D > py) U -= (U - D) - py;
		if (U - D < py) D -= py - (U - D);
		if (R - L > px) R -= (R - L) - px;
		if (R - L < px) L -= px - (R - L);
		printf("%s\n", U >= 0 && D >= 0 && L >= 0 && R >= 0? "YES": "NO");
	}
    return 0;
}