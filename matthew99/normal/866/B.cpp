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

const int maxn = 100100;

int n, S;

int s[maxn + 5], a[maxn + 5], b[maxn + 5];

LL ans = 0;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &S);
	LL cnt = 0;
	LL tot = 0;
	vector<pair<int, int> > ab;
	REP(i, 0, n)
	{
		scanf("%d%d%d", s + i, a + i, b + i);
		ab.pb(mp(b[i] - a[i], s[i]));
		tot += (LL)s[i] * a[i];
		(cnt += s[i]);
	}
	LL num = (cnt + S - 1) / S;
	ab.pb(mp(0, (LL)num * S - cnt));
	sort(ALL(ab), greater<pair<int, int> >());
	ans = 0;
	int N = SZ(ab);
	int j = 0;
	LL cur = 0;
	for (LL i = 0; i <= num; ++i)
	{
		while (j < N && cur + ab[j].y <= i * S)
		{
			tot += (LL)ab[j].x * ab[j].y;
			cur += ab[j].y;
			++j;
		}
		{
			LL tmp = tot;
			if (j < N) tmp += (LL)ab[j].x * ((LL)i * S - cur);
			chkmax(ans, tmp);
		}
		if (j == N) i = num;
		else
		{
			i = (cur + ab[j].y - 1) / S;
		}
		{
			LL tmp = tot;
			if (j < N) tmp += (LL)ab[j].x * ((LL)i * S - cur);
			chkmax(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}