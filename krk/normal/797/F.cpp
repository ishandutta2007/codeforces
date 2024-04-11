#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;
typedef pair <int, int> ii;

const int Maxn = 5005;
const int Maxm = 10015;
const int nil = 5005;
const ll Inf = 4000000000000000000ll;

ll add[Maxm];
lli seq[Maxm];
int seqa, seqb;
int n, m;
int x[Maxn];
ii p[Maxn];
int cur;
ll dp[2][Maxm];

int main()
{
	for (int i = 0; i < Maxm; i++)
		add[i] = abs(i - nil);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	sort(x, x + n);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	p[m++] = ii(1000000007, 0);
	sort(p, p + m);
	fill((ll*)dp, (ll*)dp + 2 * Maxm, Inf);
	dp[cur][nil] = 0;
	int lst = -1000000000;
	int pnt = 0;
	for (int i = 0; i < m; i++) {
		while (pnt < n && x[pnt] <= p[i].first) {
			for (int j = 0; j + 1 < Maxm; j++)
				dp[cur][j] = dp[cur][j + 1] + add[j + 1] * ll(x[pnt] - lst);
			dp[cur][Maxm - 1] = Inf;
			lst = x[pnt];
			pnt++;
		}
		seqa = seqb = 0;
		for (int j = 0; j < Maxm; j++) {
			dp[cur][j] += add[j] * ll(p[i].first - lst);
			while (seqa < seqb && seq[seqb - 1].first >= dp[cur][j]) seqb--;
			seq[seqb++] = lli(dp[cur][j], j);
			while (seq[seqa].second < j - p[i].second) seqa++;
			dp[!cur][j] = seq[seqa].first; 
			dp[cur][j] = Inf;
		}
		lst = p[i].first;
		cur = !cur;
	}
	if (dp[cur][nil] >= Inf) printf("-1\n");
	else printf("%I64d\n", dp[cur][nil]);
	return 0;
}