#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000000;

int n;
char a[maxn + 5], b[maxn + 5];
int nxt[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%*d");
	scanf("%s%s", a, b);
	n = strlen(a);
	REP(i, 0, n)
	{
		if (a[i] == 'N') a[i] = 'S';
		else if (a[i] == 'S') a[i] = 'N';
		else if (a[i] == 'E') a[i] = 'W';
		else if (a[i] == 'W') a[i] = 'E';
	}
	reverse(b, b + n);
	nxt[0] = 0, nxt[1] = 0;
	int i = 1, j = 0;
	while (i < n)
	{
		while (j && b[i] != b[j]) j = nxt[j];
		if (b[i] == b[j]) ++j;
		++i;
		nxt[i] = j;
	}
	int cur = 0;
	REP(i, 0, n)
	{
		while (cur && a[i] != b[cur]) cur = nxt[cur];
		if (a[i] == b[cur]) ++cur;
	}
	puts(cur ? "NO" : "YES");
	return 0;
}