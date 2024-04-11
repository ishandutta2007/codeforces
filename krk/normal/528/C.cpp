#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
int A[Maxn], B[Maxn];
bool nA;
vector <ii> res;
int tk[Maxn];

void Add(int a, int b)
{
	A[a] = (A[a] + 1) % 2; B[b] = (B[b] + 1) % 2;
	res.push_back(ii(a, b));
}

void Traverse(int v, int p = 0)
{
	tk[v] = 1;
	bool sav = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i]; 
		if (tk[u] == 0) Traverse(u, v);
		else if (tk[u] == 1) {
				if (!sav || p != u) Add(v, u);
				if (p == u) sav = false;
			}
	}
	if (p)
		if (A[v] && B[v]) {
			if (nA) Add(p, v);
			else Add(v, p);
			nA = !nA;
		} else if (!A[v] && !B[v]) {
			if (nA) Add(v, p);
			else Add(p, v);
			nA = !nA;
		} else if (A[v]) Add(v, p);
			   else Add(p, v);
	tk[v] = 2;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		if (a == b) Add(a, b);
		else {
			neigh[a].push_back(b); neigh[b].push_back(a);
		}
	}
	Traverse(1);
	if (A[1] && B[1]) Add(1, 1);
	for (int i = 1, j = 1; i <= n && j <= n; ) {
		while (i <= n && !A[i]) i++;
		while (j <= n && !B[j]) j++;
		if (i <= n && j <= n) Add(i, j);
	}
	for (int i = 1; i <= n; i++) {
		if (A[i]) Add(i, 1);
		if (B[i]) Add(1, i);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}