#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, m, nxt[111111][26][2], cur, d;
bool flg;
char s[111111], t[111111];
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%s%s", s, t);
		n = strlen(s); m = strlen(t);
		reverse(s, s + n); reverse(t, t + m);
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					nxt[i][j][k] = -1;
				}
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < 26; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					nxt[i][j][k] = nxt[i + 1][j][k];
				}
			}
			nxt[i][s[i] - 'a'][i & 1] = i;
		}
		cur = 0; flg = 0; d = 0;
		for (int i = 0; i < m; i++)
		{
			if (nxt[cur][t[i] - 'a'][d] == -1)
			{
				flg = 1;
				break;
			}
			cur = nxt[cur][t[i] - 'a'][d] + 1;
			d ^= 1;
		}
		if (flg) printf("NO\n");
		else printf("YES\n");
	}
	return Accepted;
}