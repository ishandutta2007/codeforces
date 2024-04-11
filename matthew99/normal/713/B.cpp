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

vector<int> ask;

int in[8];

inline int get_val()
{
	int ret = 0;
#ifdef matthew99
	if (ask[0] <= in[0] && in[2] <= ask[2] && ask[1] <= in[1] && in[3] <= ask[3]) ++ret;
	if (ask[0] <= in[4] && in[6] <= ask[2] && ask[1] <= in[5] && in[7] <= ask[3]) ++ret;
#else
	scanf("%d", &ret);
#endif
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
#ifdef matthew99
	REP(i, 0, 8) scanf("%d", in + i);
#endif
	int ret[8];
	REP(i, 0, 8)
	{
		int lo, hi;
		lo = 1, hi = n;
		while (lo < hi)
		{
			int mid = lo + hi;
			if (i % 4 >= 2) ++mid;
			mid >>= 1;
			printf("? ");
			if (i < 2) printf("1 1 %d %d\n", mid, n), ask = {1, 1, mid, n};
			else if (i < 4) printf("%d %d %d %d\n", mid, 1, n, n), ask = {mid, 1, n, n};
			else if (i < 6) printf("1 1 %d %d\n", n, mid), ask = {1, 1, n, mid};
			else printf("%d %d %d %d\n", 1, mid, n, n), ask = {1, mid, n, n};
			fflush(stdout);
			int val = get_val();
			if (i % 4 == 0)
			{
				if (val < 2) lo = mid + 1;
				else hi = mid;
			}
			if (i % 4 == 1)
			{
				if (val < 1) lo = mid + 1;
				else hi = mid;
			}
			if (i % 4 == 2)
			{
				if (val < 2) hi = mid - 1;
				else lo = mid;
			}
			if (i % 4 == 3)
			{
				if (val < 1) hi = mid - 1;
				else lo = mid;
			}
		}
		ret[i] = lo;
	}
	int X[4] = {ret[0], ret[1], ret[2], ret[3]};
	int Y[4] = {ret[4], ret[5], ret[6], ret[7]};
	sort(X, X + 4);
	sort(Y, Y + 4);
	bool can[4][4][4][4];
	memset(can, 0, sizeof can);
	REP(i, 0, 4) REP(j, 0, 4) REP(k, i + 1, 4) REP(l, j + 1, 4)
	{
		printf("? %d %d %d %d\n", X[i], Y[j], X[k], Y[l]), ask = {X[i], Y[j], X[k], Y[l]};
		fflush(stdout);
		can[i][j][k][l] = get_val() == 1;
	}
	bool ok[4][4][4][4];
	memset(ok, 0, sizeof ok);
	REP(i, 0, 4) REP(j, 0, 4) REP(k, i + 1, 4) REP(l, j + 1, 4) if (can[i][j][k][l])
	{
		ok[i][j][k][l] = 1;
		REP(_i, 0, 4) REP(_j, 0, 4) REP(_k, _i + 1, 4) REP(_l, _j + 1, 4) if (can[_i][_j][_k][_l])
		{
			if (X[i] <= X[_i] && X[_k] <= X[k] && Y[j] <= Y[_j] && Y[_l] <= Y[l])
			{
				if (X[i] != X[_i]) ok[i][j][k][l] = 0;
				if (Y[j] != Y[_j]) ok[i][j][k][l] = 0;
				if (X[k] != X[_k]) ok[i][j][k][l] = 0;
				if (Y[l] != Y[_l]) ok[i][j][k][l] = 0;
			}
		}
	}
	int ans[8] = {0};
	REP(i, 0, 4) REP(j, 0, 4) REP(k, i + 1, 4) REP(l, j + 1, 4) if (ok[i][j][k][l])
		REP(_i, i + 1, 4) REP(_j, 0, 4) REP(_k, _i + 1, 4) REP(_l, _j + 1, 4) if (ok[_i][_j][_k][_l])
		{
			if (X[max(i, _i)] > X[min(k, _k)] || Y[max(j, _j)] > Y[min(l, _l)])
			{
				if (vector<int>{X[i], Y[j], X[k], Y[l]} < vector<int>{X[_i], Y[_j], X[_k], Y[_l]})
				{
					ans[0] = X[i];
					ans[1] = Y[j];
					ans[2] = X[k];
					ans[3] = Y[l];
					ans[4] = X[_i];
					ans[5] = Y[_j];
					ans[6] = X[_k];
					ans[7] = Y[_l];
				}
			}
		}
#ifdef matthew99
	REP(i, 0, 8) debug("%d ", ans[i]);
	debug("\n");
	REP(i, 0, 8) if (ans[i] != in[i]) rotate(ans, ans + 4, ans + 8);
	REP(i, 0, 8) assert(ans[i] == in[i]);
#endif
	printf("!");
	REP(i, 0, 8) printf(" %d", ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}