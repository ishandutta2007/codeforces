#include <bits/stdc++.h>
using namespace std;

#define REP(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define pb emplace_back

typedef long long ll;
#define MOD 1000000007
#define MAXN 500005

int n, m;
ll val = 1;
vector<int> ans;

int ranks[MAXN], p[MAXN];
void init() {
	for (int i = 0; i < MAXN; i++) {
		ranks[i] = 1;
		p[i] = i;
	}
}
int findSet(int a) {
	if (p[a] == a) return a;
	return p[a] = findSet(p[a]);
}
bool unionSet(int a, int b) {
	int pa = findSet(a), pb = findSet(b);
	if (pa == pb) return false;
	if (ranks[pa] < ranks[pb]) swap(pa, pb);
	p[pb] = pa;
	if (ranks[pa] == ranks[pb]) ranks[pa]++;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	init();
	REP (i, 1, n + 1) {
		int k, x; scanf("%d%d", &k, &x);
		if (k == 1) {
			if (unionSet(0, x)) {
				val *= 2;
				val %= MOD;
				ans.pb(i);
			}
		} else {
			int y; scanf("%d", &y);
			if (unionSet(x, y)) {
				val *= 2;
				val %= MOD;
				ans.pb(i);
			}
		}
	}
	printf("%lld %d\n", val, (int) ans.size());
	REP (i, 0, ans.size()) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}