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

const int maxn = 100100;

int n, K, m;
int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &K, &m);
	REP(i, 0, n) scanf("%d", a + i);
	vector<pair<int, int> > tmp;
	REP(i, 0, n)
	{
		int num = 0;
		if (SZ(tmp) && a[i] == tmp.back().x) num = tmp.back().y; 
		tmp.pb(mp(a[i], num + 1));
		if (num + 1 == K) REP(j, 0, K) tmp.pop_back();
	}
	n = SZ(tmp);
	REP(i, 0, n) a[i] = tmp[i].x;
	LL ans = (LL)n * m;
	int l = 0, r = n - 1;
	while (1)
	{
		if (a[l] == a[r])
		{
			int cnt = 0;
			int tmpl = l, tmpr = r;
			while (cnt < K && tmpl <= tmpr && a[tmpl] == a[l]) ++tmpl, ++cnt; 
			while (cnt < K && tmpr >= tmpl && a[tmpr] == a[r]) --tmpr, ++cnt; 
			if (tmpl > tmpr)
			{
				tmpr = l, tmpl = r;
				LL len = LL(r - l + 1) * m;
				ans -= len / K * K;
				if (!(len % K))
				{
					--tmpr;
					++tmpl;
					while (tmpr >= 0 && tmpl < n)
					{
						if (a[tmpr] == a[tmpl])
						{
							int cur = a[tmpr];
							cnt = 0;
							while (cnt < K && tmpr >= 0 && a[tmpr] == cur) --tmpr, ++cnt;
							while (cnt < K && tmpl < n && a[tmpl] == cur) ++tmpl, ++cnt;
							if (cnt >= K) ans -= K;
							else break;
						}
					}
				}
				break;
			}
			else
			{
				if (cnt >= K)
				{
					ans -= (LL)K * (m - 1);
					l = tmpl, r = tmpr;
				} 
				else break;
			}
		}
		else break;
	}
	cout << ans << endl;
	return 0;
}