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

const int maxn = 100000;

int n, m;
char s[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	LL ret = (m - 1) * n;
	REP(i, 0, n - 1)
		if (s[i] != s[i + 1])
		{
			ret += (i + 1) * (m - 1);
			ret += (n - i - 1) * (m - 1);
		}
	for (int i = 0; i < n - 1; )
	{
		int j = i + 2;
		char x = s[i + 1], y = s[i];
		if (x == y) 
		{
			++i;
			continue;
		}
		while (swap(x, y), s[j] == x) ++j;
		int tmp = j - i;
		ret -= (LL)tmp * (tmp - 1) >> 1;
		i = j - 1;
	}
	cout << ret << endl;
	return 0;
}