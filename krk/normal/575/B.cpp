#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod = 1000000007;
const int d2 = 500000004;
const int Maxn = 100005;
const int Maxk = 20;
const int Maxm = 1000005;

int pow2[Maxm];
int n;
int a[Maxn], b[Maxn], val[Maxn];
vector <ii> neigh[Maxn];
int L[Maxn], P[Maxn][Maxk], T[Maxn];
int was0[Maxn], was1[Maxn];
int res;

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == P[v][0]) continue;
		L[u.first] = L[v] + 1; P[u.first][0] = v;
		if (val[u.second] == 2) T[u.first] = 2;
		else T[u.first] = a[u.second] == u.first? 0: 1;
		Traverse(u.first);
	}
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxk - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) a = P[a][i];
	if (a == b) return a;
	for (int i = Maxk - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

void Traverse2(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (u == P[v][0]) continue;
		Traverse2(u);
		was0[v] += was0[u]; was1[v] += was1[u];
	}
	if (P[v][0])
		if (T[v] == 0) res = (res + (pow2[was1[v]] - 1 + mod) % mod) % mod;
		else if (T[v] == 1) res = (res + (pow2[was0[v]] - 1 + mod) % mod) % mod;
}

int main()
{
	pow2[0] = 1;
	for (int i = 1; i < Maxm; i++)
		pow2[i] = ll(2) * pow2[i - 1] % mod;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a[i], &b[i], &val[i]);
		if (val[i] == 0) val[i] = 2;
		neigh[a[i]].push_back(ii(b[i], i));
		neigh[b[i]].push_back(ii(a[i], i));
	}
	Traverse(1);
	for (int j = 1; j < Maxk; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	int cur = 1;
	int k; scanf("%d", &k);
	while (k--) {
		int s; scanf("%d", &s);
		int lca = getLCA(cur, s);
		was0[cur]++; was0[lca]--;
		was1[s]++; was1[lca]--;
		cur = s;
	}
	Traverse2(1);
	printf("%d\n", res);
	return 0;
}