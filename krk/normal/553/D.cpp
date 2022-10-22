#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

struct frac {
	ll a, b;
	frac(ll a = 0, ll b = 0): a(a), b(b) {}
	bool operator <(const frac &f) const {
		return a * f.b > f.a * b;
	}
	bool operator !=(const frac &f) const {
		return a * f.b != f.a * b;
	}
};

typedef pair <frac, int> fi;

int n, m, k;
int forb[Maxn];
vector <int> neigh[Maxn];
frac cur[Maxn];
priority_queue <fi> Q;
int col, el[Maxn];
frac b(-1, 1);
int bi;
vector <int> res;

void Eliminate(int v)
{
	el[v] = ++col; cur[v] = frac(-1, 1);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (cur[u].a > 0) {
			cur[u].a--;
			Q.push(fi(cur[u], u));
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &forb[i]);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		cur[i] = frac(neigh[i].size(), neigh[i].size());
		Q.push(fi(cur[i], i));
	}
	for (int i = 0; i < k; i++)
		Eliminate(forb[i]);
	while (!Q.empty()) {
		while (!Q.empty() && (cur[Q.top().second] != Q.top().first))
			Q.pop();
		if (Q.empty()) continue;
		frac f = Q.top().first; int ind = Q.top().second;
		if (f < b) { b = f; bi = col; }
		Eliminate(ind);
	}
	for (int i = 1; i <= n; i++)
		if (bi < el[i]) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}