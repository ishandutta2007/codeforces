#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

const int Maxm = 1005;

int n, m;
int w[Maxm];
int seq[Maxm];
ll dist[Maxm][Maxm];
int lst[Maxm];
ll res;

ll getRes(int a, int b)
{
	if (a > b) return 0;
	return dist[a][b];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &seq[i]);
	for (int i = 1; i <= m; i++) {
		set <int> was;
		ll d = 0;
		for (int j = i; j <= m; j++) {
			if (was.find(seq[j]) == was.end()) {
				was.insert(seq[j]);
				d += w[seq[j]];
			}
			dist[i][j] = d;
		}
	}
	for (int i = 1; i <= m; i++) {
		res += getRes(lst[seq[i]] + 1, i - 1);
		lst[seq[i]] = i;
	}
	printf("%I64d\n", res);
	return 0;
}