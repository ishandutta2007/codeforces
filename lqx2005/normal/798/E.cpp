#include <bits/stdc++.h>
#define pii pair<int, string>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 5e5 + 10, K = 40, M = N * K;
struct edge {
	int to, nxt;
}e[M << 1];
int head[M], etot = 0;
int n, tot = 0;
int id[N * 2], deg[N * K], cnt[N * 2], ans[N], vis[N];
void addedge(int u, int v) {if(u && v) e[++etot] = edge{v, head[u]}, head[u] = etot, deg[v]++; }
void build(int p, int l, int r) {
	if(l == r) return void(id[p] = l);
	id[p] = ++tot;
	build(ls, l, mid), build(rs, mid + 1, r);
	addedge(id[ls], id[p]), addedge(id[rs], id[p]);
	cnt[p] = r - l + 1;
	return;
}
void add(int p, int l, int r, int L, int R, int v) {
	if(L > R) return;
	if(L <= l && r <= R) return addedge(id[p], v);
	if(L <= mid) add(ls, l, mid, L, R, v);
	if(R > mid) add(rs, mid + 1, r, L, R, v);
	return;
}
void ins(int p, int l, int r, int x) {
	cnt[p]++;
	if(l == r) return void(id[p] = l);
	id[p] = ++tot;
	if(x <= mid) ins(ls, l, mid, x);
	else ins(rs, mid + 1, r, x);
	addedge(id[ls], id[p]), addedge(id[rs], id[p]);
	return;
}
void del(int p, int l, int r, int x) {
	cnt[p]--;
	if(cnt[p] > 0) id[p] = ++tot;
	else id[p] = 0;
	if(l == r) return;
	if(x <= mid) del(ls, l, mid, x);
	else del(rs, mid + 1, r, x);
	addedge(id[ls], id[p]), addedge(id[rs], id[p]);
	return;
}
void topsort() {
	deque<int> q;
	for(int i = 1; i <= tot; i++) if(deg[i] == 0) q.eb(i);
	int ord = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop_front();
		if(u <= n) ans[u] = ++ord;
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			deg[v]--;
			if(deg[v] == 0) q.eb(v);
		}
	}
	return;
}
int main() {
	cin >> n;
	tot = n;
	build(1, 1, n);
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if(x == -1) x = n + 1;
		if(!vis[i] && x - 1 >= i) del(1, 1, n, i);
		add(1, 1, n, 1, x - 1, i);
		if(!vis[i] && x - 1 >= i) ins(1, 1, n, i);
		if(x <= n) addedge(i, x), del(1, 1, n, x), vis[x] = 1;
	}
	topsort();
	for(int i = 1; i <= n; i++) cout << ans[i] <<" ";
	cout << endl;
    return 0;
}