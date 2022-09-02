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

const int maxn = 100100, maxm = 100100, maxabs = 100100;

int lim[3], n, m, K;

int lim1d[3][2];
int lim2d[3][4][maxabs + 5];

struct data
{
	int x, y, z;
	int id;

	data(int _x = 0, int _y = 0, int _z = 0, int _id = -1): x(_x), y(_y), z(_z), id(_id) { }

	friend bool operator<(const data &x, const data &y) { return x.x < y.x; }
};

vector<data> lim3d[8];
vector<data> q3d[8];

int good[3][2];

int ans[maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 0, 3) scanf("%d", lim + i);
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, 3)
		REP(j, 0, 2)
		{
			if (j & 1) lim1d[i][j] = oo, good[i][j] = -oo;
			else lim1d[i][j] = -oo, good[i][j] = oo;
		}
	REP(i, 0, 3)
		REP(j, 0, 4)
		{
			if (j >> 1 & 1) REP(k, 0, maxabs) lim2d[i][j][k] = oo;
			else REP(k, 0, maxabs) lim2d[i][j][k] = -oo;
		}
	int a[3];
	REP(i, 0, n)
	{
		REP(j, 0, 3) 
		{
			scanf("%d", a + j);
			REP(k, 0, 2) 
				if (k) chkmax(good[j][k], a[j]);
				else chkmin(good[j][k], a[j]);
		}
	}
	REP(i, 0, m)
	{
		REP(j, 0, 3) 
		{
			scanf("%d", a + j);
		}
		static int ty[3];
		int cnt = 0;
		REP(j, 0, 3)
		{
			if (a[j] < good[j][0]) ty[j] = -1;
			if (good[j][0] <= a[j] && a[j] <= good[j][1]) ty[j] = 0;
			if (good[j][1] < a[j]) ty[j] = 1;
			if (!ty[j]) ++cnt;
		}
		if (cnt == 3)
		{
			puts("INCORRECT");
			return 0;
		}
		if (cnt == 2)
		{
			REP(j, 0, 3) if (ty[j])
			{
				if (ty[j] == -1) chkmax(lim1d[j][0], a[j]);
				else chkmin(lim1d[j][1], a[j]);
			}
		}
		if (cnt == 1)
		{
			REP(j, 0, 3) if (!ty[j])
			{
				int tmp = 0;
				REP(k, 0, 2)
				{
					if (ty[(j + k + 1) % 3] == 1) tmp |= 1 << k;
				}
				if (ty[(j + 2) % 3] == 1) chkmin(lim2d[j][tmp][a[(j + 1) % 3]], a[(j + 2) % 3]);
				else chkmax(lim2d[j][tmp][a[(j + 1) % 3]], a[(j + 2) % 3]);
			}
		}
		if (cnt == 0)
		{
			int tmp = 0;
			REP(j, 0, 3)
			{
				if (ty[j] == 1) tmp |= 1 << j;
			}
			lim3d[tmp].pb(data(a[0], a[1], a[2]));
		}
	}
	REP(i, 0, 3) REP(j, 0, 4)
	{
		if (j & 1)
		{
			REP(k, 0, maxabs - 1)
			{
				if (j >> 1) chkmin(lim2d[i][j][k + 1], lim2d[i][j][k]);
				else chkmax(lim2d[i][j][k + 1], lim2d[i][j][k]);
			}
		}
		else
		{
			for (int k = maxabs - 1; k >= 1; --k)
			{
				if (j >> 1) chkmin(lim2d[i][j][k - 1], lim2d[i][j][k]);
				else chkmax(lim2d[i][j][k - 1], lim2d[i][j][k]);
			}
		}
	}
	puts("CORRECT");
	REP(i, 0, K)
	{
		ans[i] = 0;
		REP(j, 0, 3) scanf("%d", a + j);
		bool open = 1;
		REP(j, 0, 3)
		{
			if (a[j] < good[j][0] || a[j] > good[j][1])
			{
				open = 0;
				break;
			}
		}
		if (open) 
		{
			ans[i] = 1;
			continue;
		}
		bool closed = 0;
		REP(j, 0, 3) if (a[j] <= lim1d[j][0] || a[j] >= lim1d[j][1]) closed = 1;
		REP(j, 0, 3) REP(k, 0, 4) 
		{
			if (k >> 1)
			{
				if (a[(j + 2) % 3] >= lim2d[j][k][a[(j + 1) % 3]]) closed = 1;
			}
			else
			{
				if (a[(j + 2) % 3] <= lim2d[j][k][a[(j + 1) % 3]]) closed = 1;
			}
		}
		if (closed) ans[i] = -1;
		else
		{
			int tmp = 0;
			bool flag = 0;
			REP(j, 0, 3)
			{
				if (good[j][0] <= a[j] && a[j] <= good[j][1]) flag = 1;
				if (good[j][1] < a[j]) tmp |= 1 << j;
			}
			if (!flag) q3d[tmp].pb(data(a[0], a[1], a[2], i));
		}
	}

	REP(i, 0, 8)
	{
		sort(ALL(lim3d[i]));
		sort(ALL(q3d[i]));
		if (!(i & 1))
		{
			reverse(ALL(lim3d[i]));
			reverse(ALL(q3d[i]));
		}

		static int fen[maxabs + 5];
		if (i >> 2 & 1) memset(fen, oo, sizeof fen);
		else memset(fen, -oo, sizeof fen);

		int k = 0;
		REP(j, 0, SZ(q3d[i]))
		{
			while (k < SZ(lim3d[i]))
			{
				if (i & 1)
				{
					if (lim3d[i][k].x > q3d[i][j].x) break;
				}
				else
				{
					if (lim3d[i][k].x < q3d[i][j].x) break;
				}
				if (i >> 1 & 1)
				{
					for (int l = lim3d[i][k].y; l < maxabs; l += l & -l)
					{
						if (i >> 2 & 1) chkmin(fen[l], lim3d[i][k].z);
						else chkmax(fen[l], lim3d[i][k].z);
					}
				}
				else
				{
					for (int l = lim3d[i][k].y; l > 0; l -= l & -l)
						if (i >> 2 & 1) chkmin(fen[l], lim3d[i][k].z);
						else chkmax(fen[l], lim3d[i][k].z);
				}
				++k;
			}
			int ret = (i >> 2 & 1) ? oo : -oo;
			if (i >> 1 & 1)
			{
				for (int l = q3d[i][j].y; l > 0; l -= l & -l)
					if (i >> 2 & 1) chkmin(ret, fen[l]);
					else chkmax(ret, fen[l]);
			}
			else
			{
				for (int l = q3d[i][j].y; l < maxabs; l += l & -l)
					if (i >> 2 & 1) chkmin(ret, fen[l]);
					else chkmax(ret, fen[l]);
			}
			if (i >> 2 & 1)
			{
				if (ret <= q3d[i][j].z) ans[q3d[i][j].id] = -1;
			}
			else
			{
				if (ret >= q3d[i][j].z) ans[q3d[i][j].id] = -1;
			}
		}
	}

	REP(i, 0, K)
	{
		if (ans[i] == 1) puts("OPEN");
		else if (ans[i] == 0) puts("UNKNOWN");
		else if (ans[i] == -1) puts("CLOSED");
	}

	return 0;
}