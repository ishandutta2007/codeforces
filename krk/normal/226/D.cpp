#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 105;

int n, m;
int a[Maxn][Maxn];
int rows[Maxn], cols[Maxn];
bool rtak[Maxn], ctak[Maxn];
priority_queue <iii> Q;
vector <int> res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			rows[i] += a[i][j]; cols[j] += a[i][j];
		}
	for (int i = 1; i <= n; i++) Q.push(iii(-rows[i], ii(1, i)));
	for (int j = 1; j <= m; j++) Q.push(iii(-cols[j], ii(2, j)));
	while (!Q.empty()) {
		int sum = -Q.top().first; ii v = Q.top().second; Q.pop();
		if (sum >= 0) break;
		if (v.first == 1) {
			if (sum != rows[v.second]) continue;
			rtak[v.second] = !rtak[v.second];
			rows[v.second] = -sum; Q.push(iii(-rows[v.second], v));
			for (int j = 1; j <= m; j++) {
				a[v.second][j] = -a[v.second][j];
				if (a[v.second][j]) { cols[j] += 2 * a[v.second][j]; Q.push(iii(-cols[j], ii(2, j))); }
			}
		} else {
			if (sum != cols[v.second]) continue;
			ctak[v.second] = !ctak[v.second];
			cols[v.second] = -sum; Q.push(iii(-cols[v.second], v));
			for (int i = 1; i <= n; i++) {
				a[i][v.second] = -a[i][v.second];
				if (a[i][v.second]) { rows[i] += 2 * a[i][v.second]; Q.push(iii(-rows[i], ii(1, i))); }
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (rtak[i]) res.push_back(i);
	printf("%d", res.size());
	for (int i = 0; i < res.size(); i++)
		printf(" %d", res[i]);
	printf("\n");
	res.clear();
	for (int j = 1; j <= m; j++)
		if (ctak[j]) res.push_back(j);
	printf("%d", res.size());
	for (int i = 0; i < res.size(); i++)
		printf(" %d", res[i]);
	printf("\n");
	return 0;
}