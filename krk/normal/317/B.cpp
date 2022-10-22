#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200;
const int nil = 100;
const int Maxm = Maxn * Maxn;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n;
int B[Maxn][Maxn];
bool w[Maxn][Maxn];
iii V[2][Maxm];
int len[2];
bool cur;
int t;

int main()
{
	scanf("%d", &n);
	B[nil][nil] = n; V[cur][len[cur]++] = iii(ii(nil, nil), 0);
	bool ch = true;
	while (ch) {
		ch = false;
		len[!cur] = 0;
		for (int i = 0; i < len[cur]; i++) {
			int r = V[cur][i].first.first, c = V[cur][i].first.second;
			if (w[r][c]) continue;
			w[r][c] = true;
			int has = B[r][c] / 4; B[r][c] %= 4;
			if (has) {
				ch = true;
				for (int i = 0; i < Maxd; i++)
					V[!cur][len[!cur]++] = iii(ii(r + dy[i], c + dx[i]), has);
			}
		}
		for (int i = 0; i < len[cur]; i++) {
			int r = V[cur][i].first.first, c = V[cur][i].first.second;
			w[r][c] = false;
		}
		for (int i = 0; i < len[!cur]; i++) {
			int r = V[!cur][i].first.first, c = V[!cur][i].first.second;
			B[r][c] += V[!cur][i].second;
		}
		cur = !cur;
	}
	scanf("%d", &t);
	while (t--) {
		int x, y; scanf("%d %d", &x, &y); x += nil; y += nil;
		if (0 <= x && x < Maxn && 0 <= y && y < Maxn) printf("%d\n", B[x][y]);
		else printf("0\n");
	}
	return 0;
}