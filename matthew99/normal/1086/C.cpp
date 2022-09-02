#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxl = 3001000;

int n, m;
int p[26], invp[26];

char a[maxl + 5], b[maxl + 5], c[maxl + 5];

inline bool work0()
{
	memset(p, -1, sizeof p);
	memset(invp, -1, sizeof invp);
	bool flag = 0;
	REP(i, 0, n)
	{
		int ca = a[i] - 'a';
		int cb = b[i] - 'a';
		int cc = c[i] - 'a';
		if (~p[ca])
		{
			if (!flag)
			{
				if (p[ca] > cb) flag = 1;
				else if (p[ca] < cb) return 0;
			}
			if (p[ca] < cc)
			{
				if (!flag) return 0;
				else return 1;
			}
			else if (p[ca] > cc) return 0;
		}
		else if (!flag)
		{
			bool found = 0;
			REP(j, cb + 1, cc + 1) 
			{
				if (!~invp[j])
				{
					found = 1;
					p[ca] = j;
					invp[j] = ca;
					flag = 1;
					if (j < cc) return 1;
				}
			}
			if (!found)
			{
				if (~invp[cb]) return 0;
				if (cb < cc) return 0;
				p[ca] = cb;
				invp[cb] = ca;
			}
		}
		else
		{
			bool found = 0;
			REP(j, 0, cc + 1) 
			{
				if (!~invp[j])
				{
					found = 1;
					p[ca] = j;
					invp[j] = ca;
					if (j < cc) return 1;
				}
			}
			if (!found) return 0;
		}
	}
	return 1;
}

inline bool work1()
{
	memset(p, -1, sizeof p);
	memset(invp, -1, sizeof invp);
	bool flag = 0;
	REP(i, 0, n)
	{
		int ca = a[i] - 'a';
		int cb = b[i] - 'a';
		int cc = c[i] - 'a';
		if (~p[ca])
		{
			if (!flag)
			{
				if (p[ca] < cc) flag = 1;
				else if (p[ca] > cc) return 0;
			}
			if (p[ca] > cb)
			{
				if (!flag) return 0;
				else return 1;
			}
			else if (p[ca] < cb) return 0;
		}
		else if (!flag)
		{
			bool found = 0;
			for (int j = cc - 1; j >= cb; --j)
			{
				if (!~invp[j])
				{
					found = 1;
					p[ca] = j;
					invp[j] = ca;
					flag = 1;
					if (j > cb) return 1;
				}
			}
			if (!found)
			{
				if (~invp[cc]) return 0;
				if (cb < cc) return 0;
				p[ca] = cc;
				invp[cc] = ca;
			}
		}
		else
		{
			bool found = 0;
			for (int j = m - 1; j >= cb; --j)
			{
				if (!~invp[j])
				{
					found = 1;
					p[ca] = j;
					invp[j] = ca;
					if (j > cb) return 1;
				}
			}
			if (!found) return 0;
		}
	}
	return 1;
}


int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int _T;
	scanf("%d", &_T);
	while (_T--)
	{
		scanf("%d", &m);
		scanf("%s%s%s", a, b, c);
		n = strlen(a);
		if (!work0() && !work1()) puts("NO");
		else
		{
			int j = 0;
			REP(i, 0, m) if (!~p[i]) 
			{
				while (~invp[j]) ++j;
				p[i] = j, invp[j] = i;
			}
			puts("YES");
			REP(i, 0, m) putchar('a' + p[i]);
			printf("\n");
		}
	}
	return 0;
}