#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n;
vector <int> neigh[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (neigh[i].size() > 0) {
			int cnt = 0;
			for (int j = 0; j < neigh[i].size(); j++) {
				int u = neigh[i][j];
				cnt += neigh[u].size() == 0;
			}
			if (cnt < 3) { printf("No\n"); return 0; }
		}
	printf("Yes\n");
	return 0;
}