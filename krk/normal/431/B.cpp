#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 5;

int g[Maxn][Maxn];
vector <int> seq;
int res;

int main()
{
	for (int i = 0; i < Maxn; i++)
		for (int j = 0; j < Maxn; j++)
			scanf("%d", &g[i][j]);
	for (int i = 0; i < Maxn; i++)
		seq.push_back(i);
	do {
		int cand = 0;
		for (int s = 0; s < Maxn; s++)
			for (int i = s; i + 1 < Maxn; i += 2)
				cand += g[seq[i]][seq[i + 1]] + g[seq[i + 1]][seq[i]];
		res = max(res, cand);
	} while (next_permutation(seq.begin(), seq.end()));
	printf("%d\n", res);
	return 0;
}