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

const int max0 = 1000000;

const int maxn = 1000;

unordered_multiset<int> S;

int a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	int cnt = 0;
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		if (!a[i]) ++cnt;
		S.insert(a[i]);
	}
	int ans = 0;
	REP(i, 0, n) if (i == n - 1 || a[i] != a[i + 1]) REP(j, 0, n) if (j == i - 1 || j == n - 1 || a[j] != a[j + 1]) if (i != j)
	{
		vector<int> all;
		int u = a[i], v = a[j];
		all.pb(u), all.pb(v);
		S.erase(S.find(u));
		S.erase(S.find(v));
		int tmp = 2;
		while (1)
		{
			if (!u && !v) break;
			int nxt = u + v;
			if (!S.count(nxt)) break;
			++tmp;
			all.pb(nxt);
			u = v, v = nxt;
			S.erase(S.find(nxt));
		}
		if (!u && !v)
		{
			tmp += cnt;
			for (auto x : all) if (!x) --tmp;
		}
		chkmax(ans, tmp);
		for (auto x : all) S.insert(x);
	}
	printf("%d\n", ans);
	return 0;
}