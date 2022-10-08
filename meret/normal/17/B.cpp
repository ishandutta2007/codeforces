#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1000;
const int M = 10001;

bool got[N + 1];

struct Edge {
	int a, b, c;
};

bool operator < (Edge a, Edge b) {
	return a.c < b.c;
}

Edge e[M + 1];

int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%*d");
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c);
	}
	sort(e + 1, e + m + 1);
	int res = 0;
	for (int i = 1; i <= m; ++i) {
		if (!got[e[i].b]) {
			got[e[i].b] = 1;
			--n;
			res += e[i].c;
		}
	}
	if (n == 1) printf("%d\n", res);
	else printf("-1\n");
}