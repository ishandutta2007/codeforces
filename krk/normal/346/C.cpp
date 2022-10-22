#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 2000000000;
const int Maxn = 1000005;
const int Maxs = 4194304;

int n;
vector <int> x;
int a, b, m;
bool taken[Maxn];
int R[Maxn];
int stl[Maxs], str[Maxs], mx[Maxs];
int G[Maxn];
int res;

void Create(int v, int l, int r)
{
	stl[v] = l; str[v] = r;
	if (l == r) mx[v] = l;
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		mx[v] = R[mx[2 * v]] >= R[mx[2 * v + 1]]? mx[2 * v]: mx[2 * v + 1];
	}
}

int Get(int v, int a, int b)
{
	if (stl[v] == a && str[v] == b) return mx[v];
	else {
		int m = stl[v] + str[v] >> 1;
		if (b <= m) return Get(2 * v, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, a, b);
		int c = Get(2 * v, a, m), d = Get(2 * v + 1, m + 1, b);
		return R[c] >= R[d]? c: d;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		x.push_back(num);
	}
	sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
	scanf("%d %d", &a, &b); m = a - b + 1;
	for (int i = 0; i + 1 < m; i++) R[i] = i + 1;
	for (int i = x.size() - 1; i >= 0; i--)
		for (int j = (x[i] - b % x[i]) % x[i]; j + 1 < m; j += x[i]) if (!taken[j]) {
			R[j] = max(R[j], min(m - 1, j + x[i] - 1));
			taken[j] = true;
		}
	Create(1, 0, m - 1);
	for (int i = 0; i + 1 < m; i++)
		G[i] = Get(1, i, R[i]);
	int cur = 0;
	while (cur != m - 1) { res++; cur = cur == G[cur]? R[cur]: G[cur]; }
	printf("%d\n", res);
	return 0;
}