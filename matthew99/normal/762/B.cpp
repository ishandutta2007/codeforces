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

int a, b, c;

vector<int> u;
vector<int> v;
vector<LL> sumu, sumv;

pair<int, LL> ans;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &a, &b, &c);
	int n;
	scanf("%d", &n);
	ans = mp(0, 0LL);
	REP(i, 0, n)
	{
		int x;
		static char s[10];
		scanf("%d%s", &x, s);
		if (s[0] == 'U') u.pb(x);
		else v.pb(x);
	}
	sort(ALL(u)), sort(ALL(v));
	sumu.pb(0);
	for (auto x : u) sumu.pb(sumu.back() + x);
	sumv.pb(0);
	for (auto x : v) sumv.pb(sumv.back() + x);
	REP(i, 0, c + 1)
	{
		int needa = a + i, needb = b + c - i;
		chkmin(needa, SZ(u));
		chkmin(needb, SZ(v));
		chkmax(ans, mp(needa + needb, -sumu[needa] - sumv[needb]));
	}
	cout << ans.x << ' ' << -ans.y << endl;
	return 0;
}