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

ll T[1<<21];
ll C[1<<21];

void spread(int rt) {
	if(C[rt]) {
		T[rt<<1] += C[rt];
		T[rt<<1|1] += C[rt];
		C[rt<<1] += C[rt];
		C[rt<<1|1] += C[rt];
		C[rt] = 0;
	}
}

void update(int rt, int l, int r, int s, int e, ll add) {
	if(s <= l && r <= e) {
		T[rt] += add;
		C[rt] += add;
		return;
	}
	int m = (l + r) >> 1;
	spread(rt);
	if(s <= m) update(rt<<1, l, m, s, e, add);
	if(m < e) update(rt<<1|1, m+1, r, s, e, add);
	T[rt] = max(T[rt<<1], T[rt<<1|1]);
}

ll read(int rt, int l, int r, int s, int e) {
	if(s <= l && r <= e) return T[rt];
	int m = (l + r) >> 1;
	spread(rt);
	ll res = -1e18;
	if(s <= m) res = max(res, read(rt<<1, l, m, s, e));
	if(m < e) res = max(res, read(rt<<1|1, m+1, r, s, e));
	return res;
}

pii w[1000030];

int main() {
	int q; scanf("%d", &q);
	const int INF = 1e6 + 10;
	for(int i=1;i<=INF;i++) update(1, 1, INF, i, i, i);
	for(int qq=1;qq<=q;qq++) {
		char buf[4]; scanf("%s", buf);
		if(buf[0] == '?') {
			int x; scanf("%d", &x);
			printf("%lld\n", read(1, 1, INF, 1, x) - read(1, 1, INF, x+1, x+1) + 1);
		}
		else if(buf[0] == '+') {
			int t, d; scanf("%d%d", &t, &d);
			w[qq] = pii(t, d);
			update(1, 1, INF, t+1, INF, -d);
		}
		else {
			int idx; scanf("%d", &idx);
			update(1, 1, INF, w[idx].Fi + 1, INF, w[idx].Se);
		}
	}
	return 0;
}