#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

void no() {
	printf("No\n");
	exit(0);
}

const int MAXN = 120000;

vector<int> eds[MAXN];
int was[MAXN];

int dfs(int v) {
	was[v] = 1;
	int c[6];
	c[0] = c[1] = c[2] = c[3] = c[4] = c[5] = 0;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (was[u])
			continue;
		++c[dfs(u)];
	}
	if (c[5])
		no();
	if (c[4]) {
		if (c[4] > 1)
			no();
		if (c[1] + c[2] + c[3] > 0)
			no();
		if (c[0] > 1)
			no();
		if (c[0] == 0)
			return 4;
		else
			return 5;
	}
	if (c[2] + 2 * c[3] > 2)
		no();
	if (c[3]) {
		if (c[1])
			no();
		if (c[0] > 2)
			no();
		if (c[0] <= 1)
			return 4;
		else
			return 5;
	}
	else {
		if (c[2]) {
			if (c[2] == 2)
				return 3;
			if (c[2] == 1)
				return 2;
		}
		else {
			if (c[1])
				return 2;
			else if (c[0] <= 1)
				return 0;
			else if (c[0] == 2)
				return 1;
			else
				return 2;
		}
	}
	return 5;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs(0);
	cout << "Yes\n";
	return 0;
}