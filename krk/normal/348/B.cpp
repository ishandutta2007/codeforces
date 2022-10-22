#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const ll lim = 100000000000000ll;
const int Maxn = 100005;

int n;
int a[Maxn];
ll sum;
vector <int> neigh[Maxn];
ll val[Maxn], k[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll mult(ll x, ll y) { return x <= lim / y? x * y: lim; }

ll lcm(ll x, ll y) { return mult(x / gcd(x, y), y); }

void Traverse(int v, int p)
{
	if (v != 1 && neigh[v].size() == 1) { val[v] = a[v]; k[v] = 1ll; }
	else {
		val[v] = lim; k[v] = 1ll;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (u == p) continue;
			Traverse(u, v);
			k[v] = lcm(k[v], k[u]);
			val[v] = min(val[v], val[u]) / k[v] * k[v];
		}
		k[v] = mult(k[v], ll(neigh[v].size() - (p > 0)));
		val[v] *= ll(neigh[v].size() - (p > 0));
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int v, u; scanf("%d %d", &v, &u);
		neigh[v].push_back(u); neigh[u].push_back(v);
	}
	Traverse(1, 0);
	printf("%I64d\n", sum - val[1]);
	return 0;
}