#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 23;
const int Inf = 1000000000;

int bits[1 << Maxn];
int n;
int a[Maxn];
vector <int> chec[Maxn];
int best[2][1 << Maxn];
bool cur;
int res;

int main()
{
	for (int i = 0; i < 1 << Maxn; i++) {
		int j = i;
		while (j) { bits[i] += j & 1; j >>= 1; }
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			for (int k = j; k < i; k++)
				if (a[j] + a[k] == a[i]) chec[i].push_back(1 << j | 1 << k);
	best[cur][0] = Inf; best[cur][1] = 1;
	for (int i = 1; i < n; i++) {
		fill(best[!cur], best[!cur] + (1 << i + 1), Inf);
		for (int j = 0; j < 1 << i; j++) {
			bool check = false;
			for (int k = 0; k < chec[i].size() && !check; k++)
				check = (j & chec[i][k]) == chec[i][k];
			if (!check) continue;
			int nj = j | 1 << i;
			if (max(best[cur][j], bits[nj]) < best[!cur][nj])
				best[!cur][nj] = max(best[cur][j], bits[nj]);
			for (int k = 0; k < i; k++) if (j & 1 << k)
				if (max(best[cur][j], bits[nj ^ 1 << k]) < best[!cur][nj ^ 1 << k])
					best[!cur][nj ^ 1 << k] = max(best[cur][j], bits[nj ^ 1 << k]);
		}
		cur = !cur;
	}
	res = Inf;
	for (int i = 0; i < 1 << n; i++)
		res = min(res, best[cur][i]);
	printf("%d\n", res == Inf? -1: res);
	return 0;
}