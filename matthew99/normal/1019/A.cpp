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

const int maxn = 3010, maxm = 3010;
int cnt;

int n, m;
vector<int> all[maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	cnt = 0;
	REP(i, 0, n)
	{
		int p, c;
		scanf("%d%d", &p, &c), --p;
		if (!p) ++cnt;
		else all[p].pb(c);
	}
	REP(i, 1, m) sort(ALL(all[i]), greater<int>());

	LL ans = LLONG_MAX;
	REP(i, 1, n + 1)
	{
		vector<int> res;
		LL tmp = 0;
		int cur = cnt;
		REP(j, 1, m)
		{
			REP(k, i - 1, SZ(all[j])) tmp += all[j][k], ++cur;
			REP(k, 0, min(SZ(all[j]), i - 1)) res.pb(all[j][k]);
		}
		sort(ALL(res), greater<int>());
		while (cur < i)
		{
			tmp += res.back();
			res.pop_back();
			++cur;
		}
		chkmin(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}