#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxm = 200005;

int n, m;
iii ali[Maxm];
bool taken[Maxm];
vector <int> res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &ali[i].first.first, &ali[i].first.second);
		ali[i].second = i + 1;
	}
	sort(ali, ali + m);
	priority_queue <ii> Q;
	int cur = 0;
	for (int i = 0, j; i < m; i = j) {
		j = i;
		if (ali[i].first.first > cur) cur = ali[i].first.first;
		while (j < m && ali[j].first.first <= cur) { Q.push(ii(ali[j].first.first + ali[j].first.second, ali[j].second)); j++; }
		if (Q.top().first > cur) {
			cur = Q.top().first; taken[Q.top().second] = true; Q.pop();
		}
	}
	for (int i = 1; i <= m; i++)
		if (!taken[i]) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}