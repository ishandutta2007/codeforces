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

const int maxn = 200100;

int n, m, K;
int a[maxn + 5];

int pos[maxn + 5];

int cnt[maxn + 5];

vector<int> common, va, vb;

int cntall[maxn + 5];
int cnta[maxn + 5], cntb[maxn + 5];

LL sumall[maxn + 5];
LL suma[maxn + 5], sumb[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, n) scanf("%d", a + i), pos[i] = i;
	sort(pos, pos + n, [&](int x, int y) { return a[x] < a[y]; });
	int len;
	scanf("%d", &len);
	REP(i, 0, len)
	{
		int x;
		scanf("%d", &x), --x;
		cnt[x] |= 1;
	}
	scanf("%d", &len);
	REP(i, 0, len)
	{
		int x;
		scanf("%d", &x), --x;
		cnt[x] |= 2;
	}
	REP(i, 0, n) 
	{
		suma[i + 1] = suma[i];
		sumb[i + 1] = sumb[i];
		sumall[i + 1] = sumall[i];
		cnta[i + 1] = cnta[i];
		cntb[i + 1] = cntb[i];
		cntall[i + 1] = cntall[i];
		if (cnt[pos[i]] == 3) common.pb(pos[i]);
		else
		{
			sumall[i + 1] += a[pos[i]];
			++cntall[i + 1];
			if (cnt[pos[i]] == 1) 
			{
				suma[i + 1] += a[pos[i]];
				++cnta[i + 1];
				va.pb(i + 1);
			}
			if (cnt[pos[i]] == 2) 
			{
				sumb[i + 1] += a[pos[i]];
				++cntb[i + 1];
				vb.pb(i + 1);
			}
		}
	}
	LL ans = LLONG_MAX;
	LL now = 0;
	REP(i, 0, SZ(common) + 1)
	{
		if (i > m) break;
		int need_all = m - i;
		int need_each = K - i;
		if (need_each <= min(SZ(va), SZ(vb)) && (max(0, need_each) << 1) <= need_all)
		{
			int l = 0, r = n + 1;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				int tmp = cntall[mid];
				tmp += max(0, need_each - cnta[mid]);
				tmp += max(0, need_each - cntb[mid]);
				if (tmp >= need_all) r = mid;
				else l = mid + 1;
			}
			if (l <= n)
			{
				LL tmp = now + sumall[l];
				if (need_each > 0)
				{
					if (va[need_each - 1] > l) tmp += suma[va[need_each - 1]] - suma[l];
					if (vb[need_each - 1] > l) tmp += sumb[vb[need_each - 1]] - sumb[l];
				}
				chkmin(ans, tmp);
			}
		}
		if (i < SZ(common)) now += a[common[i]];
	}
	if (ans >= LLONG_MAX) printf("-1\n");
	else cout << ans << endl;
	return 0;
}