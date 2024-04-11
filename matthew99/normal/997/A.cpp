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

const int maxn = 300100;

int n, x, y;
char a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int cnt0 = 0, cnt1 = 0;
	scanf("%d%d%d%s", &n, &x, &y, a);
	REP(i, 0, n)
		if (i == 0 || a[i] != a[i - 1])
		{
			if (a[i] == '0') ++cnt0;
			else ++cnt1;
		}
	if (!cnt0) cout << 0 << endl;
	else cout << LL(cnt0 - 1) * min(x, y) + y << endl;
	return 0;
}