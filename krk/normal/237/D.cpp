#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
map <ii, int> id;
vector <int> neigh[Maxn];

int main()
{
	scanf("%d", &n);
	printf("%d\n", n - 1);
	for (int i = 1; i <= n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		printf("2 %d %d\n", a, b);
		id[ii(a, b)] = id[ii(b, a)] = i;
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < neigh[i].size(); j++)
			printf("%d %d\n", id[ii(i, neigh[i][0])], id[ii(i, neigh[i][j])]);
	return 0;
}