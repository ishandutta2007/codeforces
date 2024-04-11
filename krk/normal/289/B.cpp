#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m, d;
int B[Maxn][Maxn];
vector <int> seq;
int res;

int main()
{
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &B[i][j]);
			if (B[i][j] % d != B[0][0] % d) { printf("-1\n"); return 0; }
			seq.push_back(B[i][j] / d);
		}
	sort(seq.begin(), seq.end());
	int val = seq[seq.size() / 2];
	for (int i = 0; i < seq.size(); i++)
		res += abs(seq[i] - val);
	printf("%d\n", res);
	return 0;
}