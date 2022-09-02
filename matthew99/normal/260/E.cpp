#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int maxn = 100000;

int n;
pair<int, int> a[maxn + 5];

bool ok[2][maxn + 5];
pair<int, int> len[300][maxn + 5];
int yyt[2][maxn + 5];

void work(const bool &kind)
{
	vector<int> v;
	REP(i, 0, n) v.pb(kind ? a[i].y : a[i].x);
	sort(ALL(v));
	REP(i, 0, n) yyt[kind][i + 1] = v[i], ok[kind][i + 1] = (i == n - 1 || v[i] != v[i + 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
	REP(i, 0, 2) work(i);
	sort(a, a + n);
	REP(i, 0, n) a[i].y = upper_bound(yyt[1] + 1, yyt[1] + n + 1, a[i].y) - yyt[1] - 2;
	int aa[12];
	REP(i, 0, 9)
		scanf("%d", aa + i);
	int cnt = 0;
	static int id[maxn + 5], val[300];
	memset(id, -1, sizeof id);
	aa[9] = 0;
	aa[10] = 0;
	aa[11] = 0;
	REP(i, 0, 12)
		REP(j, 0, i)
			REP(k, 0, j)
				REP(l, 0, k)
				{
					if (id[aa[i] + aa[j] + aa[k] + aa[l]] == -1) val[id[aa[i] + aa[j] + aa[k] + aa[l]] = cnt++] = aa[i] + aa[j] + aa[k] + aa[l];
				}
	REP(L, 0, cnt)
	{
		int totl = 0, totr = 0;
		int l = n - 1, r = n - 1;
		if (!val[L]) len[L][0] = mp(0, n);
		static int sum[maxn + 5];
		memset(sum, 0, sizeof sum);
		for (int i = 0; i < n; ++i)
		{
			const int &tmp = a[i].y;
			++sum[tmp];
			totl += tmp <= l;
			totr += tmp <= r;
			while (totl - sum[l] >= val[L]) totl -= sum[l--];
			while (totr > val[L]) totr -= sum[r--];
			len[L][i + 1] = mp(l + 1, r + 1);
		}
	}
	int pos[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	REP(i, 0, 362880)
	{
		int b[9];
		REP(i, 0, 9) b[i] = aa[pos[i]];
		next_permutation(pos, pos + 9);
		int up = b[0] + b[1] + b[2], down = n - (b[6] + b[7] + b[8]), left = b[0] + b[3] + b[6], right = n - (b[2] + b[5] + b[8]);
		if (!ok[0][up] || !ok[0][down] || !ok[1][left] || !ok[1][right]) continue;
		if (left < len[id[b[0]]][up].x || left > len[id[b[0]]][up].y) continue;
		if (right < len[id[b[0] + b[1]]][up].x || right > len[id[b[0] + b[1]]][up].y) continue;
		if (left < len[id[b[0] + b[3]]][down].x || left > len[id[b[0] + b[3]]][down].y) continue;
		if (right < len[id[b[0] + b[1] + b[3] + b[4]]][down].x || right > len[id[b[0] + b[1] + b[3] + b[4]]][down].y) continue;
		printf("%lf %lf\n%lf %lf\n", yyt[0][up] + 0.5, yyt[0][down] + 0.5, yyt[1][left] + 0.5, yyt[1][right] + 0.5);
		return 0;
	}
	printf("-1\n");
	return 0;
}