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

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

int n, m;
vector <iii> E;

bool Prime(int x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	int add = 0;
	while (!Prime(n - 1 + add)) add++;
	for (int i = 1; i + 1 <= n; i++)
		if (i + 1 == n) E.push_back(iii(ii(i, i + 1), 1 + add));
		else E.push_back(iii(ii(i, i + 1), 1));
	for (int i = 1; i <= n && E.size() < m; i++)
		for (int j = i + 2; j <= n && E.size() < m; j++)
			E.push_back(iii(ii(i, j), 1000000000));
	printf("%d %d\n", n - 1 + add, n - 1 + add);
	for (int i = 0; i < E.size(); i++)
		printf("%d %d %d\n", E[i].first.first, E[i].first.second, E[i].second);
	return 0;
}