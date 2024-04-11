#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int maxn = 200000;

LL a[maxn + 5];

pair<LL, LL> b[maxn + 5];
int pos[maxn + 5];
int n, m;

inline bool cmp(const int &x, const int &y)
{
	return b[x].y < b[y].y;
}

struct cmpa
{
	bool operator()(const int &x, const int &y) const
	{
		return a[x] < a[y];
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	LL lstx, lsty;
	REP(i, 0, n)
	{
		pos[i] = i;
		LL x, y;
		scanf("%I64d%I64d", &x, &y);
		if (i) b[i - 1] = mp(x - lsty, y - lstx);
		lstx = x, lsty = y;
	}
	--n;
	sort(pos, pos + n, cmp);
	multiset<int, cmpa> all;
	REP(i, 0, m)
	{
		scanf("%I64d", a + i);
		all.insert(i);
	}
	static int ans[maxn + 5];
	REP(i, 0, n)
	{
		a[m] = b[pos[i]].x;
		auto it = all.lower_bound(m);
		if (it == all.end() || a[*it] > b[pos[i]].y) EXIT("No");
		ans[pos[i]] = *it;
		all.erase(it);
	}
	printf("Yes\n");
	REP(i, 0, n) printf("%d ", ans[i] + 1);
	return 0;
}