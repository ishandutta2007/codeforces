#include <cstdio>
using namespace std;

const int Maxn = 305;
const int Maxm = 100005;
const int mod = 1000000007;

int n, q, t;
int a[Maxn];
int to[Maxn], from[Maxn];
int ways[Maxm][2];
int ch;

void Go(int v)
{
	ch++;
	for (int i = 0; i + a[v] <= t; i++)
		ways[i + a[v]][1] = (ways[i + a[v]][1] + (ways[i][0] + ways[i][1]) % mod) % mod;
	if (to[v]) { 
		for (int i = 0; i <= t; i++) { ways[i][0] = ways[i][1]; ways[i][1] = 0; }
		a[to[v]] += a[v]; Go(to[v]); 
	} else for (int i = 0; i <= t; i++) { ways[i][0] = (ways[i][0] + ways[i][1]) % mod; ways[i][1] = 0; }
}

int main()
{
	scanf("%d %d %d", &n, &q, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while (q--) {
		int b, c; scanf("%d %d", &b, &c);
		to[b] = c; from[c] = b;
	}
	ways[0][0] = 1;
	for (int i = 1; i <= n; i++) if (!from[i])
		Go(i);
	printf("%d\n", ch < n? 0: ways[t][0]);
	return 0;
}