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

map<int, int> dict;

int SG(int x)
{
	if (x == 1) return 0;
	if (dict.count(x)) return dict[x];
	int &ret = dict[x];
	set<int> to_mex;
	REP(i, 1, 30) if (x >> i)
	{
		to_mex.insert(SG((x & ((1 << i) - 1)) | (x >> i)));
	}
	ret = 0;
	while (to_mex.count(ret)) ++ret;
	return ret;
}

int n;

map<int, int> all;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(j, 0, n)
	{
		int x;
		scanf("%d", &x);
		for (int i = 2; i * i <= x; ++i)
		{
			if (!(x % i))
			{
				int cnt = 0;
				while (!(x % i)) x /= i, ++cnt;
				all[i] |= 1 << cnt;
			}
		}
		if (x > 1) all[x] |= 2;
	}
	int ans = 0;
	for (auto u : all) ans ^= SG(u.y);
	puts(ans ? "Mojtaba" : "Arpa");
	return 0;
}