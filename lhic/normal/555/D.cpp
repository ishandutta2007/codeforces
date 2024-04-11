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

const int MAXN = 210000;

int x[MAXN];
int x2[MAXN];
map<int, int> mm;
int n, m;


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &x[i]), mm[x[i]] = i + 1, x2[i] = x[i];
	sort(x, x + n);
	for (int i = 0; i < m; ++i) {
		int a, g;
		scanf("%d%d", &a, &g);
		a = x2[a - 1];
		a = lower_bound(x, x + n, a) - x; 
		int r = upper_bound(x, x + n, x[a] + g) - x - 1;
		g -= x[r] - x[a];
		a = r;
		int l = lower_bound(x, x + n, x[a] - g) - x;
		g -= x[a] - x[l];
		a = l;
		int ans;
		while (true) {
			int r = upper_bound(x, x + n, x[a] + g) - x - 1;
			if (r == a) {
				ans = a;
				break;
			}
			if (g >= 2 * (x[r] - x[a])) {
				g %= 2 * (x[r] - x[a]);
				continue;
			}
			g -= x[r] - x[a];
			a = r;
			int l = lower_bound(x, x + n, x[a] - g) - x;
			g -= x[a] - x[l];
			a = l;
		}
		printf("%d\n", mm[x[ans]]);
	}
	return 0;
}