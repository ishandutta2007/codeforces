#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const int N = 1e5 + 5, M = 2e5 + 5;

int n, m, a[N], b[N], t1, t2, A[N], B[N], tot;

LL in[N], out[N], C[M];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		out[u] += w, in[v] += w;	
	}
	for (int i = 1; i <= n; i++) {
		if (out[i] > in[i]) a[++t1] = i;
		else if (in[i] > out[i]) b[++t2] = i; 
	}
	for (int j = 1, i = 1; j <= t2; j++) {
		LL nd = in[b[j]] - out[b[j]];
		while (nd) {
			LL w = out[a[i]] - in[a[i]];
			LL pw = min(w, nd);
			nd -= pw;
			w -= pw;
			++tot, A[tot] = a[i], B[tot] = b[j], C[tot] = pw;
			if (w) out[a[i]] -= pw;
			else i++;
		}
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d %d %lld\n", A[i], B[i], C[i]);
	return 0;
}