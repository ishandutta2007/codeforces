#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int k, n, maxb, t;
int b[Maxn];
int pos[Maxn];
int seq[Maxn], len;

int main()
{
	scanf("%d %d %d %d", &k, &n, &maxb, &t); t = min(t, min(n, maxb));
	while (k--) {
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		fill(pos + 1, pos + maxb + 1, 0);
		len = 0;
		for (int i = 0; i < t; i++)
			for (int j = 0; j < n; j++) {
				while (pos[b[j]] < len && b[j] > seq[pos[b[j]]]) pos[b[j]]++;
				if (pos[b[j]] == len) len++;
				seq[pos[b[j]]] = b[j];
			}
		printf("%d\n", len);
	}
	return 0;
}