#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxm = 1000005;

int n;
vector <int> pos[Maxm];
int res = Maxm, li, ri;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		pos[a].push_back(i);
	}
	int r = 0;
	for (int i = 0; i < Maxm; i++)
		r = max(r, (int)pos[i].size());
	for (int i = 0; i < Maxm; i++)
		if (pos[i].size() == r) {
			int cand = pos[i].back() - pos[i][0] + 1;
			if (cand < res) { res = cand; li = pos[i][0]; ri = pos[i].back(); }
		}
	printf("%d %d\n", li, ri);
	return 0;
}