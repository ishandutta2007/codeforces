#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int p[400040]; int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
int za[400040], zb[400040];

int main() {
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=n+m;i++) p[i] = i, za[i] = (i <= n), zb[i] = (i > n);
	for(int i=1;i<=q;i++) {
		int x, y; scanf("%d%d", &x, &y);
		y += n;
		if(Find(x) != Find(y)) {
			int px = Find(x), py = Find(y);
			p[px] = py;
			za[py] += za[px];
			zb[py] += zb[px];
		}
	}
	int ans = 0;
	for(int i=1;i<=n+m;i++) if(p[i] == i) ++ans;
	printf("%d\n", ans - 1);
	return 0;
}