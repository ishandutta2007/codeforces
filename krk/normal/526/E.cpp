#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 2000005;

int n, q, N;
int a[Maxn];
ll b;
int nxt[Maxn], need[Maxn];
int res;

void pushMore(int v, int lim)
{
	if (nxt[v] < lim) {
		pushMore(nxt[v], lim);
		need[v] += need[nxt[v]];
		nxt[v] = nxt[nxt[v]];
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[n + i] = a[i];
	}
	N = 2 * n;
	while (q--) {
		scanf("%I64d", &b);
		ll sum = 0;
		int r = N - 1;
		for (int i = N - 1; i >= 0; i--) {
			sum += a[i];
			while (sum > b) sum -= a[r--];
			nxt[i] = r + 1; need[i] = 1;
		}
		res = Maxn;
		for (int i = 0; i < n; i++) {
			pushMore(i, i + n);
			res = min(res, need[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}