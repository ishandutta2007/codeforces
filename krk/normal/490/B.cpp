#include <cstdio>
using namespace std;

const int Maxn = 1000005;

int n;
bool was[Maxn];
bool taken[Maxn];
int nxt[Maxn], bef[Maxn];
int res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		nxt[a] = b; bef[b] = a;
		was[a] = was[b] = true;
	}
	int cur = nxt[0];
	for (int i = 1; i < n; i += 2) {
		res[i] = cur; cur = nxt[cur];
	}
	for (int i = 1; i < Maxn; i++)
		if (was[i] && i != nxt[0] && bef[i] == 0) {
			cur = i; break;
		}
	for (int i = 0; i < n; i += 2) {
		res[i] = cur; cur = nxt[cur];
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}