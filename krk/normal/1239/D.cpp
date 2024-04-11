#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

int T;
int n, m;
vector <int> neigh[Maxn], rneigh[Maxn];
bool mark[Maxn];

void printYes(const vector <int> &A, const vector <int> &B)
{
	printf("Yes\n");
	printf("%d %d\n", int(A.size()), int(B.size()));
	for (int i = 0; i < A.size(); i++)
		printf("%d%c", A[i], i + 1 < A.size()? ' ': '\n');
	for (int i = 0; i < B.size(); i++)
		printf("%d%c", B[i], i + 1 < B.size()? ' ': '\n');
}

void printNo() { printf("No\n"); }

bool Solve(vector <int> neigh[], vector <int> &A, vector <int> &B)
{
	fill(mark + 1, mark + n + 1, false); mark[1] = true;
	A.clear(); A.push_back(1);
	for (int i = 0; i < A.size(); i++) {
		int v = A[i];
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (!mark[u]) {
				mark[u] = true; A.push_back(u);
			}
		}
	}
	sort(A.begin(), A.end());
	B.clear();
	for (int i = 1; i <= n; i++) if (!mark[i])
		B.push_back(i);
	return !B.empty();
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			rneigh[i].clear();
		}
		while (m--) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].push_back(b);
			rneigh[b].push_back(a);
		}
		vector <int> A, B;
		if (Solve(neigh, A, B))
			printYes(A, B);
		else if (Solve(rneigh, B, A))
			printYes(A, B);
		else printNo();
	}
	return 0;
}