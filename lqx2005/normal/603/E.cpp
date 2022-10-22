#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define PI pair<int, int>
#define pb push_back
using namespace std;
typedef long long i64;
typedef double db;
const int N = 4e5 + 10;
int n, m, a[N], b[N];
int ch[N][2], fa[N], rev[N], sze[N], cnt[N], tot;
PI mx[N], val[N];
multiset<PI> ans;

int newd(int v, int s) {
	int u = ++tot;
	val[u] = {v, u};
	cnt[u] = s;
	return u;
}

int nrt(int p) {return ch[fa[p]][0] == p || ch[fa[p]][1] == p; }

void upd(int p) {
	sze[p] = sze[ch[p][0]] + sze[ch[p][1]] + cnt[p];
	mx[p] = max(max(mx[ch[p][0]], mx[ch[p][1]]), val[p]);
	return;
}

void down(int p) {
	swap(ch[p][0], ch[p][1]);
	rev[p] ^= 1;
	return;
}

void pushd(int p) {
	if(!rev[p]) return;
	down(ch[p][0]);
	down(ch[p][1]);
	rev[p] = 0;
	return;
}

void rotate(int x) {
	int y = fa[x], z = fa[y], k = ch[y][1] == x, w = ch[x][!k];
	if(nrt(y)) ch[z][ch[z][1] == y] = x;
	ch[x][!k] = y, ch[y][k] = w, fa[y] = x, fa[w] = y, fa[x] = z;
	return upd(y);
}


void pushdown(int x) {
	if(nrt(x)) pushdown(fa[x]);
	return pushd(x);
}

void splay(int x) {
	pushdown(x);
	while(nrt(x)) {
		int y = fa[x], z = fa[y];
		if(nrt(y)) rotate((ch[z][1] == y) ^ (ch[y][1] == x) ? x : y);
		rotate(x);
	}
	return upd(x);
}

void access(int x) {
	for(int y = 0; x; x = fa[y = x]) {
		splay(x);
		cnt[x] -= sze[y];
		cnt[x] += sze[ch[x][1]];
		ch[x][1] = y;
		upd(x);
	}
	return;
}

void makeroot(int x) {
	access(x), splay(x);
	return down(x);
}

void split(int x, int y) {
	makeroot(x), access(y);
	return splay(y);
}

void link(int x, int y) {
//	cout << "link " << x <<" " << y << endl;
	makeroot(x), access(y), splay(y), fa[x] = y, cnt[y] += sze[x];
	return upd(y);
}

void cut(int x, int y) {
//	cout << "cut " << x <<" " << y << endl;
	split(x, y), ch[y][0] = 0, fa[x] = 0;
	return upd(y);
}

int findroot(int x) {
	access(x), splay(x);
	while(ch[x][0]) {
		pushd(x);
		x = ch[x][0];
	}
	splay(x);
	return x;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) newd(0, 1);
	int cnt = n;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[i + n] = u, b[i + n] = v;
		if(findroot(u) == findroot(v)) {
			split(u, v);
			if(w < mx[v].x) {
				ans.erase(ans.find(mx[v]));
				int p = mx[v].y;
				cut(p, a[p]), cut(p, b[p]);
				int id = newd(w, 0);
				link(u, id), link(id, v);
				ans.insert({w, id});
			} else {
				newd(w, 0);
			}
		} else {
			makeroot(u), makeroot(v);
			cnt -= sze[u] % 2 + sze[v] % 2;
			int id = newd(w, 0);
			link(u, id), link(id, v);
			makeroot(u);
			cnt += sze[u] % 2;
			ans.insert({w, id});
		}
		if(cnt) {
			printf("-1\n");
			continue;
		}
		for(; !ans.empty(); ) {
			int id = (--ans.end()) -> y; 
			cut(id, a[id]), cut(id, b[id]);
			makeroot(a[id]), makeroot(b[id]);
			if(sze[a[id]] % 2 == 0 && sze[b[id]] % 2 == 0) {
				ans.erase(--ans.end());
				assert(sze[a[id]] % 2 == 0);
				assert(sze[b[id]] % 2 == 0);
			} else {
				link(id, a[id]);
				link(id, b[id]);
				break;
			}
		}
		printf("%d\n", (--ans.end()) -> x);
	}
	return 0;
}