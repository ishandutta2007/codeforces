#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, p[2020], c[2020];
vector <int> E[2020];
int ans[2020];

int bfs(int rt) {
	if(c[rt] == 0) return rt;
	vector<int> q;
	q.pb(rt);
	rep(i, szz(q)) {
		int t = q[i];
		for(int e : E[t]) {
			if(c[e] == 0) return e;
			q.pb(e);
		}
	}
	return -1;
}

int main() {
	scanf("%d", &n);
	int rt = -1;
	for(int i=1;i<=n;i++) {
		scanf("%d%d", p + i, c + i);
		if (p[i] == 0) rt = i;
		else E[p[i]].pb(i);
	}
	for(int i=1;i<=n;i++) {
		int v = bfs(rt);
		if(v == -1) {
			puts("NO");
			return 0;
		}
		ans[v] = i;
		for(int t=v;t;t=p[t]) c[t]--;
	}
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d ", ans[i]); puts("");
	return 0;
}