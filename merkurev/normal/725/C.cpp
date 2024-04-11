#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int LEN = 27;
char str[LEN + 1];
char s[LEN + 1];
int pos[200];
char ans[2][LEN];

void test()
{
	int x = -1, y = -1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 13; j++)
			if (ans[i][j] == s[0] )
			{
				x = i;
				y = j;
			}
	if (x == -1) throw;
	for (int i = 1; i < LEN; i++)
	{
		bool fnd = false;
		for (int ni = 0; ni <= 1 && !fnd; ni++)
			for (int nj = max(0, y - 1); nj <= min(12, y + 1); nj++)
			{
				if (ans[ni][nj] == s[i] )
				{
					x = ni;
					y = nj;
					fnd = true;
					break;
				}
			}
		if (!fnd) throw;
	}
}

void solve()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 13; j++)
			ans[i][j] = '-';
	memset(pos, -1, sizeof pos);
	for (int i = 0; i < LEN; i++)
	{
		if (pos[(int)str[i] ] != -1)
		{
			if (pos[(int)str[i] ] == i - 1)
			{
				printf("Impossible\n");
				return;
			}
			int a = pos[(int)str[i] ];
			int rem = i - a - 1;
			if (a > LEN - i - 1)
			{
				reverse(str, str + LEN);
				solve();
				return;
			}
			if (rem == 25)
			{
				for (int j = 0; j < 13; j++)
					ans[0][j] = str[j];
				for (int j = 0; j < 13; j++)
					ans[1][12 - j] = str[13 + j];
			}
			else
			{
			eprintf("%s\n%s\n\n", ans[0], ans[1] );
				int y = 12 - rem / 2;
				for (int j = 0; j <= a + rem / 2; j++)
					ans[0][y - a + j] = str[j];
			eprintf("%s\n%s\n\n", ans[0], ans[1] );
				int x = 12;
				for (int j = a + rem / 2 + 1; j < i; j++)
					ans[1][x--] = str[j];
			eprintf("%s\n%s\n\n", ans[0], ans[1] );
				for (int j = i + 1; x >= 0; j++)
					ans[1][x--] = str[j];
			eprintf("%s\n%s\n\n", ans[0], ans[1] );
				for (int j = y - a - 1; j >= 0; j--)
					ans[0][j] = str[LEN - 1 - ((y - a - 1) - j)];
			eprintf("%s\n%s\n\n", ans[0], ans[1] );
			}

			test();
			printf("%s\n%s\n", ans[0], ans[1] );
			return;
		}
		pos[(int)str[i] ] = i;
	}
}


void stress()
{
	for (int a = 0; a < 26; a++)
		for (int b = a + 1; b < 27; b++)
		{
			memset(s, 0, sizeof s);
			s[a] = 'A';
			s[b] = 'A';
			int p = 0;
			for (int j = 'B'; j <= 'Z'; j++)
			{
				while (s[p] != 0)
					p++;
				s[p] = j;
			}
			eprintf("\n\n%s\n-----\n", s);
			for (int j = 0; j < LEN; j++)
				str[j] = s[j];
			solve();
		}
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

//	stress();

	scanf("%s", s);

	for (int i = 0; i < LEN; i++)
		str[i] = s[i];
	solve();

	return 0;
}