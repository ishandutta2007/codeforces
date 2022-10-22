#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 405;
const int Maxl = 26;

int n, m, k;
char B[Maxn][Maxn];
int hasa[Maxn][Maxn];
vector <int> V[Maxl];
int pnt[Maxl];
ll res;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &B[i][j]); 
			hasa[i][j] = (B[i][j] == 'a') + hasa[i - 1][j] + hasa[i][j - 1] - hasa[i - 1][j - 1];
		}
	for (int i1 = 1; i1 <= n; i1++)
		for (int i2 = i1 + 1; i2 <= n; i2++) {
			for (int l = 0; l < Maxl; l++) { V[l].clear(); pnt[l] = 0; }
			for (int j = 1; j <= m; j++) if (B[i1][j] == B[i2][j]) {
				int ind = B[i1][j] - 'a';
				while (pnt[ind] < V[ind].size()) {
					int oldj = V[ind][pnt[ind]];
					if (hasa[i2][j] - hasa[i2][oldj - 1] - hasa[i1 - 1][j] + hasa[i1 - 1][oldj - 1] > k)
						pnt[ind]++;
					else break;
				}
				res += V[ind].size() - pnt[ind];
				V[ind].push_back(j);
			}
		}
	printf("%I64d\n", res);
	return 0;
}