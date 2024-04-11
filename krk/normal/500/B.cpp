#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 305;

int n;
int p[Maxn];
char B[Maxn][Maxn];
int cur, taken[Maxn];
vector <int> seq;
int res[Maxn];

void Take(int v, int col)
{
	if (taken[v]) return;
	taken[v] = col; seq.push_back(p[v]);
	for (int i = 0; i < n; i++)
		if (B[v][i] == '1') Take(i, col);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++)
		if (!taken[i]) {
			seq.clear();
			Take(i, ++cur);
			sort(seq.begin(), seq.end());
			int pnt = 0;
			for (int i = 0; i < n; i++)
				if (taken[i] == cur) res[i] = seq[pnt++];
		}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}