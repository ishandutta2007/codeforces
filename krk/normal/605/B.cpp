#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int n, m;
iii E[Maxn];
int P[Maxn], cur = 2;
int nxt = 2;
ii res[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &E[i].first.first, &E[i].first.second); 
		E[i].first.second = -E[i].first.second;
		E[i].second = i;
	}
	sort(E, E + m);
	for (int i = 0; i < m; i++)
		if (E[i].first.second != 0) {
			P[nxt] = nxt + 1; cur = 2; 
			res[E[i].second] = ii(1, nxt);
			nxt++;
		} else {
			while (cur < nxt && P[cur] >= nxt) cur++;
			if (cur >= nxt) { printf("-1\n"); return 0; }
			res[E[i].second] = ii(cur, P[cur]); P[cur]++;
		}
	for (int i = 0; i < m; i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}