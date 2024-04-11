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

int a[4][2];

int ans;
int goal[4][2];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ans = oo;
		REP(i, 0, 4) scanf("%d%d", a[i], a[i] + 1);
		REP(rev, 0, 2)
		{
			REP(i, 0, 4) REP(j, 0, 4) if (a[i][0] < a[j][0])
			{
				int len = a[j][0] - a[i][0];
				vector<int> res;
				REP(k, 0, 4) if (k != i && k != j) res.pb(k);
				if (a[res[0]][0] != a[i][0]) swap(res[0], res[1]);
				if (a[res[0]][0] == a[i][0] && a[res[1]][0] == a[j][0])
				{
					int foo[4] = {a[i][1], a[res[0]][1] - len, a[j][1], a[res[1]][1] - len};
					int mid = (*min_element(foo, foo + 4) + *max_element(foo, foo + 4)) >> 1;
					int Max = 0;
					REP(i, 0, 4) chkmax(Max, abs(mid - foo[i]));
					if (chkmin(ans, Max))
					{
						REP(i, 0, 4) goal[i][0] = a[i][0];
						goal[i][1] = mid;
						goal[res[0]][1] = mid + len;
						goal[j][1] = mid;
						goal[res[1]][1] = mid + len;
						if (rev) REP(ii, 0, 4) swap(goal[ii][0], goal[ii][1]);
					}
				}
				REP(k, 0, 4) REP(l, 0, 2)
				{
					int coo[4][2] = {{a[i][0], a[k][1]}, {a[j][0], a[k][1] + (l ? len : -len)}};
					int pos[4] = {0, 1, 2, 3};
					do
					{
						bool failed = 0;
						int Max = 0;
						REP(i, 0, 4)
						{
							int gx = coo[i & 1][0], gy = coo[i >> 1][1];
							int ox = a[pos[i]][0], oy = a[pos[i]][1];
							if (ox != gx && oy != gy) { failed = 1; break; }
							else if (ox != gx) chkmax(Max, abs(ox - gx));
							else if (oy != gy) chkmax(Max, abs(oy - gy));
						}
						if (!failed && chkmin(ans, Max)) REP(ii, 0, 4) REP(jj, 0, 2) goal[pos[ii]][jj] = coo[ii >> (jj ^ rev) & 1][jj ^ rev];
					}while (next_permutation(pos, pos + 4));
				}
			}
			REP(i, 0, 4) swap(a[i][0], a[i][1]);
		}
		if (ans == oo) printf("-1\n");
		else
		{
			printf("%d\n", ans);
			REP(i, 0, 4) printf("%d %d\n", goal[i][0], goal[i][1]);
		}
	}
	return 0;
}