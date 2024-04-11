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

const int maxn = 1000100;

int n;

vector<int> fac[maxn + 5];
int cnt[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i)
		fac[j].pb(i);
	vector<int> res;
	for (int i = 1; i <= n; ++i)
		res.pb(i);
	int cur = 1;
	while (!res.empty())
	{
		int Maxp = -1;
		for (auto i : res)
			for (auto j : fac[i]) 
				if (j > cur)
				{
					++cnt[j];
					if (!~Maxp || cnt[j] > cnt[Maxp] || (cnt[j] == cnt[Maxp] && j > Maxp)) Maxp = j;
				}
		if (SZ(res) == n) memset(cnt, 0, sizeof cnt);
		else
		{
			for (auto i : res)
				for (auto j : fac[i])
				{
					--cnt[j];
				}
		}
		vector<int> nxt;
		for (auto i : res)
		{
			if (~Maxp && !(i % Maxp))
			{
				nxt.pb(i);
			}
			else printf("%d ", cur);
		}
		swap(res, nxt);
		cur = Maxp;
	}
	debug("%ld\n", clock());
	return 0;
}