#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int n, k;
vector <int> D[Maxn];
int pnt[Maxn];
vector <ii> res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int d; scanf("%d", &d);
		D[d].push_back(i);
	}
	if (D[0].size() != 1) { printf("-1\n"); return 0; }
	for (int i = 0; i < Maxn; i++) {
		if (i && pnt[i] < D[i].size()) { printf("-1\n"); return 0; }
		for (int j = 0; j < D[i].size(); j++) {
			int v = D[i][j], lft = i == 0? k: k - 1;
			while (pnt[i + 1] < D[i + 1].size() && lft) {
				int u = D[i + 1][pnt[i + 1]++];
				res.push_back(ii(v, u)); lft--;
			}
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}