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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200100;

int n;
int a[maxn + 5];
int pos[maxn + 5];

int fen[maxn + 5];

inline void del(int x)
{
	for (int i = x + 1; i <= (n << 1); i += i & -i) ++fen[i];
	for (int i = x + n + 1; i <= (n << 1); i += i & -i) ++fen[i];
}

LL ans = 0;

inline int query(int x)
{
	int ret = 0;
	for (int i = x; i > 0; i -= i & -i) ret += fen[i];
	return ret;
}

inline void calc(int x, int y)
{
	if (x > y) y += n;
	ans += y + 1 - x - (query(y + 1) - query(x));
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), pos[i] = i;
	reverse(a, a + n);
	sort(pos, pos + n, [&](int x, int y) { return a[x] < a[y]; });
	int cur = n - 1;
	for (int i = 0; i < n; )
	{
		int j = i;
		while (j < n && a[pos[j]] == a[pos[i]]) ++j;
		sort(pos + i, pos + j, greater<int>());
		REP(k, i, j)
			if (pos[k] <= cur)
			{
				rotate(pos + i, pos + k, pos + j);
				break;
			}
		REP(k, i, j)
		{
			calc(pos[k], cur);
			del(pos[k]);
			cur = pos[k];
		}
		i = j;
	}
	cout << ans << endl;
	return 0;
}