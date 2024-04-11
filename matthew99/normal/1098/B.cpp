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

inline int c2i(const char &c)
{
	if (c == 'A') return 0;
	if (c == 'G') return 1;
	if (c == 'C') return 2;
	if (c == 'T') return 3;
	return -1;
}

inline char i2c(const int x)
{
	if (x == 0) return 'A';
	if (x == 1) return 'G';
	if (x == 2) return 'C';
	if (x == 3) return 'T';
	return -1;
}

const int maxn = 300100;

int n, m;
vector<int> a[maxn + 5];
vector<int> ans[maxn + 5];
int ans_flip = -1;
int Max = -1;

inline void transpose(vector<int> *b)
{
	vector<int> c[maxn + 5];
	REP(i, 0, m) c[i].resize(n);
	REP(i, 0, n) REP(j, 0, m)
		c[j][i] = b[i][j];
	REP(i, 0, n) b[i].clear();
	REP(i, 0, m) b[i] = c[i];
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char ss[maxn + 5];
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
	{
		scanf("%s", ss);
		REP(j, 0, m)
			a[i].pb(c2i(ss[j]));
	}
	Max = -1;
	REP(flip, 0, 2)
	{
		static vector<int> tmp[maxn + 5];
		REP(i, 0, n) tmp[i].resize(m);
		REP(a00, 0, 4) REP(a01, a00 + 1, 4) 
			REP(a10, 0, 4) if (a10 != a00 && a10 != a01)
			{
				REP(a11, a10 + 1, 4)
					if (a11 != a00 && a11 != a01)
					{
						int t[2][2];
						t[0][0] = a00;
						t[0][1] = a01;
						t[1][0] = a10;
						t[1][1] = a11;
						int total = 0;
						REP(i, 0, n)
						{
							int bestj = -1;
							int Maxj = -1;
							REP(j, 0, 2)
							{
								int cnt = 0;
								REP(k, 0, m)
								{
									int x = t[i & 1][(k ^ j) & 1];
									if (x == a[i][k]) ++cnt;
								}
								if (chkmax(Maxj, cnt)) bestj = j;
							}
							total += Maxj;
							REP(k, 0, m) tmp[i][k] = t[i & 1][(k ^ bestj) & 1];
						}
						if (chkmax(Max, total))
						{
							ans_flip = flip;
							REP(i, 0, n) ans[i] = tmp[i];
						}
					}
			}
		transpose(a);
		swap(n, m);
	}
	if (ans_flip) swap(n, m), transpose(ans), swap(n, m);
	REP(i, 0, n)
	{
		REP(j, 0, m)
			putchar(i2c(ans[i][j]));
		printf("\n");
	}
	return 0;
}