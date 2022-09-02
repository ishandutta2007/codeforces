#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const char sim[] = "SIMILAR";

const int maxn = 1010, maxm = maxn * maxn;

typedef bitset<(maxn << 1) + 5> Int;

int n, m0, m1;
pair<int, int> edA[maxm + 5], edB[maxm + 5];

Int A[(maxn << 1) + 5], B[(maxn << 1) + 5];
Int odd;

inline int get(int x)
{
	if (x < 0) 
	{
		x = -x, --x;
		return x << 1;
	}
	--x;
	return x << 1 | 1;
}

inline bool check(const Int &x) { return (((x & odd) >> 1) & x).none(); }

Int ban;
int ans[maxn + 5];

inline void find(Int *f)
{
	REP(i, 0, n)
	{
		if (ban[i << 1] || (f[i << 1] & ban).any() || !check(f[i << 1])) ans[i] = 1;
		else ans[i] = 0;
		ban[i << 1 | (!ans[i])] = 1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m0, &m1);
	REP(i, 0, n) odd[i << 1 | 1] = 1;
	REP(i, 0, m0)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u = get(u), v = get(v);
		A[u ^ 1][v] = 1;
		A[v ^ 1][u] = 1;
		edA[i] = mp(u, v);
	}
	REP(i, 0, n << 1) A[i][i] = B[i][i] = 1;
	REP(i, 0, m1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u = get(u), v = get(v);
		B[u ^ 1][v] = 1;
		B[v ^ 1][u] = 1;
		edB[i] = mp(u, v);
	}
	REP(i, 0, n << 1) REP(j, 0, n << 1) if (A[j][i]) A[j] |= A[i];
	REP(i, 0, n << 1) REP(j, 0, n << 1) if (B[j][i]) B[j] |= B[i];
	bool canA = 1, canB = 1;
	REP(i, 0, n) if (A[i << 1][i << 1 | 1] && A[i << 1 | 1][i << 1]) { canA = 0; break; }
	REP(i, 0, n) if (B[i << 1][i << 1 | 1] && B[i << 1 | 1][i << 1]) { canB = 0; break; }
	if (!canA && !canB) puts(sim);
	else if (canA ^ canB)
	{
		if (canA) find(A);
		else find(B);
		REP(i, 0, n) printf("%d ", ans[i]);
		printf("\n");
	}
	else
	{
		REP(i, 0, m0)
		{
			int u = edA[i].x ^ 1, v = edA[i].y ^ 1;
			if (check(B[u] | B[v]))
			{
				ban[u ^ 1] = ban[v ^ 1] = 1;
				find(B);
				REP(i, 0, n) printf("%d ", ans[i]);
				printf("\n");
				return 0;
			}
		}
		REP(i, 0, m1)
		{
			int u = edB[i].x ^ 1, v = edB[i].y ^ 1;
			if (check(A[u] | A[v]))
			{
				ban[u ^ 1] = ban[v ^ 1] = 1;
				find(A);
				REP(i, 0, n) printf("%d ", ans[i]);
				printf("\n");
				return 0;
			}
		}
		puts(sim);
	}
	return 0;
}