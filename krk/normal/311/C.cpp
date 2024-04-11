#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, int> li;

const ll Inf = 2000000000000000000ll;
const int Maxn = 100005;
const int Maxk = 10005;
const int Maxo = 22;

ll h;
int n, m, k;
ll a[Maxn];
int c[Maxn];
ll dist[Maxk];
ll jump[Maxo];
int jlen;
bool tk[Maxn];
priority_queue <ii> GQ;

void Insert(ll x, bool first = false)
{
	if (!first) jump[jlen++] = x;
	fill(dist, dist + k, Inf); dist[0] = 0;
	priority_queue <li> Q; Q.push(li(dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second; ll d = -Q.top().first; Q.pop();
		if (d != dist[v]) continue;
		for (int i = 0; i < jlen; i++) {
			int u = (ll(v) + jump[i]) % k;
			if (d + jump[i] < dist[u]) {
				dist[u] = d + jump[i]; Q.push(li(-dist[u], u));
			}
		}
	}
	for (int i = 0; i < n; i++) if (!tk[i]) {
		int md = a[i] % k;
		if (a[i] >= dist[md]) { tk[i] = true; GQ.push(ii(c[i], -i)); }
	}
}

void Dec(int x, int y)
{
	if (y == 0) return;
	x--; c[x] -= y;
	if (tk[x]) GQ.push(ii(c[x], -x));
}

int Get()
{
	while (!GQ.empty()) {
		int v = -GQ.top().second, val = GQ.top().first; GQ.pop();
		if (c[v] == val) return val;
	}
	return 0;
}

int main()
{
	scanf("%I64d %d %d %d", &h, &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%I64d %d", &a[i], &c[i]);
		a[i]--;
	}
	Insert(k, true);
	while (m--) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			ll x; scanf("%I64d", &x);
			Insert(x);
		} else if (typ == 2) {
			int x, y; scanf("%d %d", &x, &y);
			Dec(x, y);
		} else if (typ == 3) printf("%d\n", Get());
	}
	return 0;
}