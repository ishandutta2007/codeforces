#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 1000100;
int BLOCK_SIZE = 1000;

int n;
int permutation[MAX_N];
pair<int, int> keys[MAX_N];

bool cmp_keys(const int &a, const int &b) {
	return keys[a] < keys[b];
}

void solve() {
	srand(2318);
	BLOCK_SIZE += rand() % 1000;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		permutation[i] = i;

		keys[i] = make_pair(x / BLOCK_SIZE, y);
	}

	sort(permutation, permutation + n, cmp_keys);

	for (int i = 0; i < n; i++) {
		printf("%d ", permutation[i] + 1);
	}
	printf("\n");
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}