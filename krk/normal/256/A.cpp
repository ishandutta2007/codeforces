#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 4005;
const int Maxm = 1000005;

int n;
vector <int> pos[Maxm];
vector <int> ind;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		pos[a].push_back(i);
	}
	for (int i = 0; i < Maxm; i++)
		if (!pos[i].empty()) ind.push_back(i);
	for (int i = 0; i < ind.size(); i++) {
		int v = ind[i];
		for (int j = 0; j < ind.size(); j++) {
			int u = ind[j];
			int cand = 0;
			int l = 0, r = 0;
			int lst = -1;
			while (l < pos[v].size() && r < pos[u].size())
				if (pos[v][l] < pos[u][r]) {
					l++;
					if (lst != 0) { cand++; lst = 0; }
				} else if (pos[v][l] > pos[u][r]) {
					r++;
					if (lst != 1) { cand++; lst = 1; }
				} else { l++; r++; cand++; }
			if (l < pos[v].size() && lst != 0) cand++;
			if (r < pos[u].size() && lst != 1) cand++;
			res = max(res, cand);
		}
	}
	printf("%d\n", res);
	return 0;
}