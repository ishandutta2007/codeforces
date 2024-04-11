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
typedef double ld;

using namespace std;

int n, m;
int a[400000];
int b[400000];


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
	}
	sort(a, a + n);
	for (int i = 0; i < m; ++i) {
		int x = upper_bound(a, a + n, b[i]) - a;
		printf("%d ", x);
	}

	return 0;
}