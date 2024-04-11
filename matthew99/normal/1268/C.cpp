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

const int maxn = 200100;

int n;
int a[maxn + 5], b[maxn + 5];

int fen[maxn + 5];

LL fenl[maxn + 5];
LL fenr[maxn + 5];

LL sum[maxn + 5];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), --a[i], b[a[i]] = i;
	LL ans = 0;
	set<int> l, r;
	LL tmp = 0;
	REP(i, 0, n)
	{
		int cnt = 0;
		for (int j = b[i] + 1; j <= n; j += j & -j)
			cnt += fen[j];
		ans += cnt;
		for (int j = b[i] + 1; j > 0; j -= j & -j)
			++fen[j];
		for (int j = b[i] + 1; j > 0; j -= j & -j)
			fenl[j] += b[i] + 1;
		for (int j = b[i] + 1; j <= n; j += j & -j)
			fenr[j] -= b[i];
		if (!r.empty() && b[i] >= *r.begin()) r.insert(b[i]);
		else l.insert(b[i]);
		if (SZ(r) > SZ(l))
		{
			l.insert(*r.begin());
			r.erase(r.begin());
		}
		else if (SZ(l) > SZ(r))
		{
			r.insert(*--l.end());
			l.erase(--l.end());
		}
		tmp += (i >> 1) + 1;
		LL ret = ans;
		if (i > 0)
		{
			int x = SZ(r) >= SZ(l) ? *r.begin() : *--l.end();
			for (int j = x + (!(i & 1)); j > 0; j -= j & -j)
				ret += fenr[j];
			for (int j = x + 1; j <= n; j += j & -j)
				ret += fenl[j];
			ret -= tmp;
		}
		printf("%lld ", ret);
	}
	return 0;
}