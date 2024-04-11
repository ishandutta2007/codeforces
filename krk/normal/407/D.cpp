#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 405;
const int Maxm = 2048;

int n, m;
int B[Maxn][Maxn];
vector <ii> seq[Maxn];
short mnR[Maxn][Maxn][Maxn];
int mx[Maxn][Maxn];
int res;

void Update(int ind, int l, int id, int r)
{
	mnR[ind][l][id] = min(mnR[ind][l][id], short(r));
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &B[i][j]);
			seq[j].push_back(ii(B[i][j], i));
		}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			for (int l = 0; l <= i; l++)
				mnR[i][j][l] = n;
		sort(seq[i].begin(), seq[i].end());
		for (int j = 0; j + 1 < seq[i].size(); j++)
			if (seq[i][j].first == seq[i][j + 1].first)
				Update(i, seq[i][j].second, i, seq[i][j + 1].second);
		for (int j = 0; j < i; j++) {
			int a = 0, b = 0;
			while (a < seq[j].size() && b < seq[i].size()) {
				if (seq[j][a].first == seq[i][b].first)
					Update(i, min(seq[j][a].second, seq[i][b].second), j, max(seq[j][a].second, seq[i][b].second));
				if (seq[j][a] <= seq[i][b]) a++;
				else b++;
			}
		}
	}
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			mx[j][i] = -1;
	for (int i1 = n - 1; i1 >= 0; i1--) {
		for (int j = 0; j < m; j++)
			for (int id = j; id >= 0; id--)
				for (int r = mnR[j][i1][id]; r < n && id > mx[j][r]; r++)
					mx[j][r] = id;
		for (int i2 = i1; i2 < n; i2++) {
			int cur = 0;
			for (int j = 0; j < m; j++) {
				cur = max(cur, mx[j][i2] + 1);
				res = max(res, (i2 - i1 + 1) * (j - cur + 1));
			}
		}
	}
	printf("%d\n", res);
	return 0;
}