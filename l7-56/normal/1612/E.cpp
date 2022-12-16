#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

const int maxn = 2e5 + 10;
int n,m[maxn],k[maxn],idx;

struct node {
	int id;
	db val;
	bool operator < (const node &x) const { return val > x.val; }
}a[maxn];

vector <int> ans;
db ansv;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d%d", &m[i], &k[i]), idx = max(idx, m[i]);
	for(int c = 1; c <= 20; ++c) {
		for(int i = 1; i <= idx; ++i) a[i].val = 0, a[i].id = i;
		for(int i = 1; i <= n; ++i) {
			if(k[i] >= c) a[m[i]].val += 1;
			else a[m[i]].val += (db)k[i] / c;
		}
		sort(a + 1, a + idx + 1);
		db resv = 0;
		vector <int> res;
		for(int i = 1; i <= c; ++i) resv += a[i].val, res.push_back(a[i].id);
		if(resv > ansv) ansv = resv, ans = res;
	}
	printf("%d\n", (int)ans.size());
	for(int v : ans) printf("%d ", v);
	return 0;
}