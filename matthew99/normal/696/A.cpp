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

const int maxq = 1000;

int qn;

map<LL, LL> delta;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty;
		LL a, b;
		cin >> ty >> a >> b;
		vector<LL> path;
		while (a != b)
		{
			if (a < b) swap(a, b);
			path.pb(a), a >>= 1;
		}
		if (ty == 1)
		{
			int w;
			cin >> w;
			for (auto u : path) delta[u] += w;
		}
		else 
		{
			LL ans = 0;
			for (auto u : path) ans += delta[u];
			cout << ans << endl;
		}
	}
	return 0;
}