#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 10005;

int n;
vector <int> neigh[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < neigh[i].size(); j++)
			res += neigh[neigh[i][j]].size() - 1;
	res /= 2;
	printf("%d\n", res);
	return 0;
}