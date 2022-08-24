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

int n, m;
int ed[500][500];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		ed[a][b] = 1;
		ed[b][a] = 1;
	}
	if (ed[0][n - 1] == 1) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ed[i][j] ^= 1;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (ed[i][j] == 0)
				ed[i][j] = 10000;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (ed[i][j] > ed[i][k] + ed[k][j])
					ed[i][j] = ed[i][k] + ed[k][j];
	if (ed[0][n - 1] >= 10000)
		cout << -1 << "\n";
	else
		cout << ed[0][n - 1];
	return 0;
}