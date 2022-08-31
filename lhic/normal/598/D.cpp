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

int n, m, k;

char arr[1200][1200];
int p[1440000];
int go[1440000];


int get(int x) {
	if (p[x] == x)
		return x;
	return p[x] = get(p[x]);
}

void add(int x, int y) {
	int g = get(x * m + y);
	++go[g];
}

void un(int x1, int y1, int x2, int y2) {
	int g1 = get(x1 * m + y1);
	int g2 = get(x2 * m + y2);
	if (g1 == g2)
		return;
	go[g1] += go[g2];
	p[g2] = g1;
}


int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf(" %s", arr[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			p[i * m + j] = i * m + j;
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m - 1; ++j) {
			if (arr[i][j] == '.') {
				if (arr[i][j + 1] == '.')
					un(i, j, i, j + 1);
				else
					add(i, j);
			}
			else {
				if (arr[i][j + 1] == '.')
					add(i, j + 1);
			}
		}
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == '.') {
				if (arr[i + 1][j] == '.')
					un(i, j, i + 1, j);
				else
					add(i, j);
			}
			else {
				if (arr[i + 1][j] == '.')
					add(i + 1, j);
			}
		}
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		int a = get(x * m + y);
		printf("%d\n", go[a]);
	}
	return 0;
}