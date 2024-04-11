#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int n;
int par[Maxn], dist[Maxn];
int res;

void Get(int v, int &p, int &d)
{
	if (par[v] == v) { p = par[v]; d = dist[v]; }
	else { 
		Get(par[v], p, d);
		par[v] = p; d = (dist[v] + d) % mod;
		dist[v] = d;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		par[i] = i; dist[i] = 0;
		int k; scanf("%d", &k);
		while (k--) {
			int v, x; scanf("%d %d", &v, &x);
			int rp, rd; Get(v, rp, rd);
			int edge = (ll(x) + ll(rd) + ll(mod)) % ll(mod);
			res = (res + edge) % mod;
			par[rp] = i; dist[rp] = edge;
		}
	}
	printf("%d\n", res);
	return 0;
}