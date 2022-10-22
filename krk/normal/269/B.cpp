#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 5005;

int n, m;
vector <int> cur, srt;
int best[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	cur.resize(n); srt.resize(n);
	for (int i = 0; i < n; i++) {
		int s; double dum; scanf("%d %lf", &s, &dum);
		cur[i] = srt[i] = s;
	}
	sort(srt.begin(), srt.end());
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			best[i][j] = max(max(best[i - 1][j], best[i][j - 1]), best[i - 1][j - 1] + (cur[i - 1] == srt[j - 1]));
	printf("%d\n", n - best[n][n]);
	return 0;
}