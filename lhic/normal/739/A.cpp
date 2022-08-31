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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 120000;

int n, m;
int a[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	int mx = n;
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		mx = min(mx, r - l + 1);
	}
	printf("%d\n", mx);
	for (int i = 0; i < n; ++i) {
		printf("%d ", i % mx);
	}
	printf("\n");
	return 0;
}