#include <iostream>
#include <cstring>
using namespace std;


char s[100500];
char c[100500];
char st[100500];
int pf[100500];
bool isEnter[50500];

int len;
int lft[11][50500];
int rght[11][50500];


void calcPf()
{
	int len = strlen(c);
	
	int sWin = 0, eWin = 0;
	for (int i = 1; i < len; i++)
	{
		int curpf = 0;
		if (eWin > i)
		{
			curpf = pf[i - sWin]; 
		}
		curpf = min(curpf, eWin - i);
		curpf = max(0, curpf);

		while (c[i + curpf] == c[curpf] )
			curpf++;
		if (i + curpf > eWin)
		{
			eWin = i + curpf;
			sWin = i;
		}
		pf[i] = curpf;
	}
}

int cnt[50500];
bool good[2005][2005];

void castRule(int rule)
{
	memset(isEnter, false, sizeof isEnter);

	int a, b;
	scanf("%s %d %d", st, &a, &b);
	int curLen = strlen(st);

	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
			c[j - i] = s[j];
		c[len - i] = '$';
		for (int j = 0; j < curLen; j++)
			c[j + len - i + 1] = st[j];
		c[curLen + len - i + 1] = 0;
		
		calcPf();

		for (int j = 0; j < len; j++)
			cnt[j] = 0;
		for (int j = 0; j < curLen; j++)
			cnt[pf[j + len - i + 1] ]++;

		int curCnt = curLen;
		for (int j = i; j <= len; j++)
		{

			if (curCnt < a || curCnt > b)
				good[i][j] = false;

			curCnt -= cnt[j - i];
		}
	}
}

int nxt[2000500][26];
bool isFin[2000500];
int lst = 1;

int prevpos = 0;

int addStr(int l, int r)
{
	int curpos = 0;
	if (prevpos != 0)
	{
		curpos = prevpos;
		l = r - 1;
	}
	for (int i = l; i < r; i++)
	{
		char ch = s[i] - 'a';
		if (nxt[curpos][ch] == 0)
		{
			nxt[curpos][ch] = lst++;
		}
		curpos = nxt[curpos][ch];
	}
	prevpos = curpos;

	if (isFin[curpos] )
		return 0;
	isFin[curpos] = true;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 0; i < 2005; i++)
		for (int j = 0; j < 2005; j++)
			good[i][j] = true;
	scanf("%s", s);
	len = strlen(s);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		castRule(i);
	}

	long long ans = 0;
	for (int i = 0; i < len; i++)
	{
		prevpos = 0;
		for (int j = i + 1; j <= len; j++)
			if (good[i][j] )
			{
				ans += addStr(i, j);
			}
	}
	printf("%I64d\n", ans);

	return 0;
}