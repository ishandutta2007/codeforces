#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 300005;

int n, m;
vector <int> neigh[Maxn];
int col[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	bool ch = true;
	while (ch) {
		ch = false;
		for (int i = 1; i <= n; i++) {
			int en = 0;
			for (int j = 0; j < neigh[i].size(); j++)
				if (col[i] == col[neigh[i][j]]) en++;
			if (en > 1) { col[i] = !col[i]; ch = true; }
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d", col[i]);
	printf("\n");
	return 0;
}