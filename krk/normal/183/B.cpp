#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int Maxm = 255;

int n, m;
int x[Maxm], y[Maxm];
bool calc[Maxm];
map <int, int> M[Maxm];
int res[Maxn];
int tot;

void Calc(int v)
{
	if (calc[v]) return;
	calc[v] = true;
	for (int i = 0; i < m; i++) if (y[v] < y[i]) {
		Calc(i);
		ll a = ll(x[i] - x[v]) * ll(y[v]), b = y[i] - y[v];
		ll dv = a / b; 
		if (dv * b != a) continue;
		ll ind = x[v] - dv;
		if (1 <= ind && ind <= n) {
			int cand = M[i].count(ind)? M[i][ind] + 1: 1;
			if (cand < M[v][ind]) continue;
			M[v][ind] = cand;
			res[ind] = max(res[ind], M[v][ind] + 1);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++) res[i] = 1;
	for (int i = 0; i < m; i++)
		Calc(i);
	for (int i = 1; i <= n; i++) tot += res[i];
	printf("%d\n", tot);
	return 0;
}