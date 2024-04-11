#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <char, int> ci;

const int Maxn = 100005;

int n, m;
ci his[Maxn];
vector <ci> phis[Maxn];
int mtime[Maxn];
int cur, got;
vector <int> res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf(" %c %d", &his[i].first, &his[i].second);
		phis[his[i].second].push_back(ci(his[i].first, i));
	}
	for (int i = 1; i <= n; i++)
		if (phis[i].empty()) res.push_back(i);
		else {
			if (phis[i][0].first == '-') { mtime[i] += phis[i][0].second; cur++; }
			for (int j = 0; j < phis[i].size(); j++)
				if (phis[i][j].first == '+')
					if (j + 1 < phis[i].size()) mtime[i] += phis[i][j + 1].second - phis[i][j].second;
					else mtime[i] += m + 1 - phis[i][j].second;
		}
	if (cur) got++;
	for (int i = 1; i <= m; i++) {
		if (his[i].first == '-') cur--;
		else cur++;
		if (cur) got++;
	}
	for (int i = 1; i <= n; i++)
		if (!phis[i].empty() && mtime[i] == got)
			res.push_back(i);
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}