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

vector<int> l, r;

int n, goal;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &goal);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		if (x > goal) r.pb(x - goal);
		else l.pb(goal - x);
	}
	sort(ALL(l), greater<int>());
	sort(ALL(r), greater<int>());
	LL ans = 0;
	int cnt = 0;
	while (abs(SZ(l) - SZ(r)) > cnt)
	{
		if (SZ(l) > SZ(r))
		{
			ans += l.back();
			l.pop_back();
			++cnt;
		}
		else
		{
			ans += r.back();
			r.pop_back();
			++cnt;
		}
	}
	cout << ans << endl;
	return 0;
}