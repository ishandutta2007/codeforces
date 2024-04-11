#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;

ll ts, tf, t;
int n;
ll c[Maxn], d[Maxn];

int main() 
{
	scanf("%I64d %I64d %I64d", &ts, &tf, &t); tf -= t;
	scanf("%d", &n);
	ll fre = ts;
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &c[i]);
		fre = max(fre, c[i]); fre += t;
		d[i] = fre;
	}
	if (n == 0 || ts < c[0]) printf("%I64d\n", max(ts, 0ll));
	else {
		ll best = Inf, bi = -1;
		if (ts < c[0]) { best = 0; bi = max(ts, 0ll); }
		else if (0 < c[0]) {
			ll sh = c[0] - 1;
			ll cand = ts - sh;
			if (cand < best) { best = cand; bi = sh; }
		}
		for (int i = 0; i < n; i++)
			if (d[i] <= tf)
				if (i == n - 1 || d[i] < c[i + 1]) { best = 0; bi = d[i]; }
				else if (c[i] < c[i + 1]) {
					ll sh = c[i + 1] - 1;
					ll cand = d[i] - sh;
					if (cand < best) { best = cand; bi = sh; }
				}
		printf("%I64d\n", bi);
	}
    return 0;
}