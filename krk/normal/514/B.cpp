#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1005;

int n, X0, Y0;
int X[Maxn], Y[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];
int res;

void Fill(int v)
{
	if (tk[v]) return;
	tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		Fill(neigh[v][i]);
}

int main()
{
	scanf("%d %d %d", &n, &X0, &Y0);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &X[i], &Y[i]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			int ax = X[i] - X0, ay = Y[i] - Y0;
			int bx = X[j] - X0, by = Y[j] - Y0;
			if (ax * by - ay * bx == 0) { neigh[i].push_back(j); neigh[j].push_back(i); }
		}
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		res++; Fill(i);
	}
	printf("%d\n", res);
	return 0;
}