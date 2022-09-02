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

const int maxn = 1010;

LL find(const LL &l, const LL &r, const LL &what, const LL &res)
{
	if (((r - l) >> 1) == what && res == 0)
	{
		return (l + r) >> 1;
	}
	LL mid = (l + r) >> 1;
	map<LL, LL> now;
	map<LL, LL, greater<LL> > dis;
	dis[(r - l) >> 1] += 1;
	now[mid - l] = 1;
	while (SZ(now))
	{
		map<LL, LL> nxt;
		for (auto u : now) if (u.x)
		{ 
			dis[(u.x - 1) >> 1] += u.y;
			nxt[(u.x - 1) >> 1] += u.y;
			nxt[u.x >> 1] += u.y;
		}
		now = nxt;
	}
	LL tmp = dis[what];
	if (tmp > res) return find(l, mid - 1, what, res);
	return find(mid + 1, r, what, res - tmp);
}

LL work(LL n, LL K)
{
	if (K == 1) return 1;
	if (K == 2) return n;
	n -= 2;
	K -= 3;
	map<LL, LL> now;
	map<LL, LL, greater<LL> > dis;
	now[n] = 1;
	while (SZ(now))
	{
		map<LL, LL> nxt;
		for (auto u : now) if (u.x)
		{ 
			dis[(u.x - 1) >> 1] += u.y;
			nxt[(u.x - 1) >> 1] += u.y;
			nxt[u.x >> 1] += u.y;
		}
		now = nxt;
	}
	for (auto u : dis)
	{
		if (u.y > K)
		{
			return find(0, n - 1, u.x, K) + 2;
		}
		K -= u.y;
	}
	assert(0);
	return -1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	LL n, K;
	cin >> n >> K;
	cout << work(n, K) << endl;
	return 0;
}