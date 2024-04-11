#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
bool S;
char s[30], Ans[3][20], xx;
int pd[30], P1, P2, id, len;

void Work()
{
	FOR(i, 1, 27)
		if(pd[s[i] - 64] == 0) pd[s[i] - 64] = i;
		else
		{
			P1 = pd[s[i] - 64];
			P2 = i;
			xx = s[i];
		}
	Ans[1][13 - (P2 - P1 - 1) / 2] = xx;
	id = 1;
	len = 14 - (P2 - P1 - 1) / 2;
	if(len == 14) id = 2, len = 13;
	FOR(i, P1 + 1, 27)
		if(i != P2)
		{
			Ans[id][len] = s[i];
			if(id == 1) len ++;
			else len --;
			if(id == 1 && len == 14) id = 2, len = 13;
			if(id == 2 && len == 0) id = 1, len = 1;
		}
	FOR(i, 1, P1 - 1)
	{
		Ans[id][len] = s[i];
		if(id == 1) len ++;
		else len --;
		if(id == 1 && len == 14) id = 2, len = 13;
		if(id == 2 && len == 0) id = 1, len = 1;
	}
	FOR(i, 1, 2)
	{
		FOR(j, 1, 13)
		    printf("%c", Ans[i][j]);
		printf("\n");
	}
}
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	S = 1;
	for(int i = 1; i <= n - 1; i ++)
		if(s[i] == s[i + 1]) S = 0;
	if(S == 0) printf("Impossible");
	else Work();
	return 0;
}