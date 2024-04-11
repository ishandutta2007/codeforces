#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, m;
int deg[Maxn];
int ones, twos;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		deg[a]++; deg[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (deg[i] == 1) ones++;
		else if (deg[i] == 2) twos++;
	if (ones == 2 && twos == n - 2) printf("bus topology\n");
	else if (twos == n) printf("ring topology\n");
	else if (ones == n - 1) printf("star topology\n");
	else printf("unknown topology\n");
	return 0;
}