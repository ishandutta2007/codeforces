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


const int ALP = 4;
const int LEN = (int) 1e5 + 100;
const int SLEN = 12;
char s[LEN];
vector <int> fn[ALP][SLEN][SLEN];
char c[SLEN];


void fnadd(int i1, int i2, int i3, int pos, int x)
{
//	if (i2 == 2) eprintf("fnadd %d %d %d %d %d\n", i1, i2, i3, pos, x);
	pos++;
	int len = (int) fn[i1][i2][i3].size();
	for (; pos < len; pos = (pos | (pos - 1) ) + 1)
		fn[i1][i2][i3][pos] += x;
}

int fnsum(int i1, int i2, int i3, int pos)
{
//	eprintf("fnsum %d %d %d %d\n", i1, i2, i3, pos);
	int ans = 0;
	pos++;
	for (; pos > 0; pos = (pos & (pos - 1) ) )
		ans += fn[i1][i2][i3][pos];
//	eprintf("ans = %d\n", ans);
	return ans;
}

int getId(char ch)
{
	if (ch == 'A') return 0;
	else if (ch == 'C') return 1;
	else if (ch == 'G') return 2;
	else if (ch == 'T') return 3;
	else throw;
}

void setChar(int pos, char ch, int k)
{
	int cid = getId(ch);
	for (int mod = 1; mod < SLEN; mod++)
	{
		int rem = pos % mod;
		int fpos = pos / mod;
		fnadd(cid, mod, rem, fpos, k);
	}
}

int getCnt(int l, int r, char ch, int mod, int rem)
{
	int cid = getId(ch);
	int ans = 0;
	while (l % mod != rem) l++;
	while (r % mod != rem) r--;
	if (l > r) return ans;
	int lpos = l / mod;
	int rpos = r / mod;
	ans += fnsum(cid, mod, rem, rpos);
	ans -= fnsum(cid, mod, rem, lpos - 1);
	return ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	for (int a = 0; a < ALP; a++)
		for (int mod = 1; mod <= 10; mod++)
			for (int rem = 0; rem < mod; rem++)
				fn[a][mod][rem].resize(LEN / mod + 5);

	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		setChar(i, s[i], 1);

	int q;
	scanf("%d", &q);
	for (int it = 0; it < q; it++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x;
			scanf("%d%s", &x, c);
			x--;
			setChar(x, s[x], -1);
			setChar(x, c[0], 1);
			s[x] = c[0];
		}
		else if (t == 2)
		{
			int l, r;
			scanf("%d%d%s", &l, &r, c);
			l--;
			r--;
			int mod = strlen(c);
			int ans = 0;
			for (int i = 0; i < min(mod, r - l + 1); i++)
				ans += getCnt(l, r, c[i], mod, (l + i) % mod);
			printf("%d\n", ans);
		}
		else throw;
	}




	return 0;
}