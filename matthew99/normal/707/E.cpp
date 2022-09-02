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

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getchar(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getchar();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

const int maxn = 2010, maxk = 2010, maxq = 2010, maxlen = 2010;

struct data
{
	int x, y, w;

	data() { }
	data(int _x, int _y, int _w): x(_x), y(_y), w(_w) { }

};

int n, m, K;
vector<data> all[maxk + 5];

bool now[maxlen + 5];
bool sta[maxq + 5][maxlen + 5];

int N = 0;
pair<pair<int, int>, pair<int, int> > a[maxq + 5];

vector<pair<int, int> > allp[maxn + 5];
vector<data> allq[maxn + 5];

LL ans[maxq + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n), Read(m), Read(K);
	REP(i, 0, K)
	{
		int len;
		Read(len);
		REP(j, 0, len)
		{
			int x, y, w;
			Read(x), Read(y), Read(w), --x, --y;
			all[i].pb(data(x, y, w));
		}
	}
	REP(i, 0, K) now[i] = 1;
	int qn;
	Read(qn);
	REP(i, 0, qn)
	{
		static char s[100];
		scanf("%s", s);
		if (s[0] == 'S')
		{
			int x;
			Read(x), --x;
			now[x] ^= 1;
		}
		else
		{
			Read(a[N].x.x);
			Read(a[N].y.x);
			Read(a[N].x.y);
			Read(a[N].y.y);
			--a[N].x.x;
			--a[N].y.x;
			memcpy(sta[N], now, sizeof sta[N]);
			++N;
		}
	}
	REP(i, 0, K)
	{
		REP(j, 0, n + 1) allp[j].clear(), allq[j].clear();
		REP(j, 0, N) if (sta[j][i])
		{
			allq[a[j].x.x].pb(data(a[j].y.x, a[j].y.y, j << 1));
			allq[a[j].x.y].pb(data(a[j].y.x, a[j].y.y, j << 1 | 1));
		}
		for (auto u : all[i]) allp[u.x].pb(mp(u.y, u.w));
		static LL sum[maxn + 5];
		memset(sum, 0, sizeof sum);
		REP(j, 0, n + 1)
		{
			for (auto u : allq[j])
			{
				LL ret = 0;
				for (int k = u.y; k > 0; k -= k & -k) ret += sum[k];
				for (int k = u.x; k > 0; k -= k & -k) ret -= sum[k];
				if (u.w & 1) ans[u.w >> 1] += ret;
				else ans[u.w >> 1] -= ret;
			}
			for (auto u : allp[j]) 
				for (int k = u.x + 1; k <= m; k += k & -k) sum[k] += u.y;
		}
	}
	REP(i, 0, N) printf("%I64d\n", ans[i]);
	return 0;
}