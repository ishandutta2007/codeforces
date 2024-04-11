#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 20;

int n;
int s[Maxn];
int par[Maxn], siz[Maxn];
int m;
int A[Maxn], B[Maxn], C[Maxn];
vector <ii> neigh[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	return true;
}

void Add(int ind, int a, int b, int c)
{
	if (A[ind] == a && B[ind] == b) C[ind] += c;
	else C[ind] -= c;
}

int Solve(int v, int p = 0)
{
	int cnt = s[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		int add = Solve(u.first, v);
		Add(u.second, v, u.first, add);
		cnt += add;
	}
	return cnt;
}

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		sum += s[i];
	}
	if (sum != 0) { printf("Impossible\n"); return 0; }
	printf("Possible\n");
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &A[i], &B[i]);
		if (unionSet(A[i], B[i])) {
			neigh[A[i]].push_back(ii(B[i], i));
			neigh[B[i]].push_back(ii(A[i], i));
		}
	}
	Solve(1);
	for (int i = 1; i <= m; i++)
		printf("%d\n", C[i]);
	return 0;
}