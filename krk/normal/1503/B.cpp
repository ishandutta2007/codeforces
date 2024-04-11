#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n;
vector <ii> need[3];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if ((i + j) % 2 == 0) need[1].push_back(ii(i, j));
			else need[2].push_back(ii(i, j));
	for (int i = 0; i < n * n; i++) {
		int b; scanf("%d", &b);
		if (b != 1 && !need[1].empty()) { printf("1 %d %d\n", need[1].back().first, need[1].back().second); need[1].pop_back(); }
		else if (b != 2 && !need[2].empty()) { printf("2 %d %d\n", need[2].back().first, need[2].back().second); need[2].pop_back(); }
		else if (!need[1].empty()) { printf("3 %d %d\n", need[1].back().first, need[1].back().second); need[1].pop_back(); }
		else if (!need[2].empty()) { printf("3 %d %d\n", need[2].back().first, need[2].back().second); need[2].pop_back(); }
		fflush(stdout);
	}
    return 0;
}