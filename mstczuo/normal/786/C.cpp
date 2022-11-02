# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>

#define mp make_pair
#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)

using namespace std;

int a[100010];
int pre[100010];
int last[100010];
bool ini[100010];

int n = 1;

struct node {
	node *lc, *rc;
	int cnt;
};

node* init(int l,int r) {
	node* p = new node;
	if(l == r) {
		return new (node){NULL, NULL, ini[l]};
	} else {
		int mid = (l + r) >> 1;
		node* p = new (node) {
			init(l, mid), init(mid + 1, r), 0};
		p->cnt = p->lc->cnt + p->rc->cnt;
		return p;
	}
}

node* add(node* u,int l,int r,int v) {
	if(l == r) {
		return new (node){NULL, NULL, 1};
	} else {
		int mid = (l + r) >> 1;
		node* p = new (node);
		if (v <= mid)
			p->lc = add(u->lc, l, mid, v), p->rc = u->rc;
		else
			p->lc = u->lc, p->rc = add(u->rc, mid + 1, r, v);
		p->cnt = p->lc->cnt + p->rc->cnt;
		return p;
	}
}

int query(node* u,int l,int r,int k) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(u->lc->cnt >= k) return query(u->lc, l, mid, k);
	else return query(u->rc, mid + 1, r, k - u->lc->cnt);
}

node* root[100010];
vector<int> g[100010];

int main() {
	int sz; scanf("%d", &sz);
	rep(i, sz) {
		scanf("%d", &a[n]);
		if(n == 1 || a[n] != a[n-1]) {
			n++;
		}
	}
	--n;
	for(int i = 1; i <= n; ++i) {
		pre[i] = last[a[i]];
		if(pre[i] == 0) {
			ini[i] = true;
		} else {
			g[pre[i]].push_back(i);
		}
		last[a[i]] = i;
	}
	root[0] = init(1, n + 1);
	for(int i = 1; i < n; ++i) {
		node* p = root[i-1];
		for(auto v: g[i]) 
			p = add(p, 1, n + 1, v);
		root[i] = p;
	}

	printf("%d", n);
	for(int gap = 2; gap <= n; ++gap) {
		int cur = 0, ans = 0;
		while(cur < n) {
			cur = query(root[cur], 1, n + 1, cur + gap + 1) - 1;
			ans += 1;
		}
		printf(" %d", ans);
	}
	for(int i = n + 1; i <= sz; ++i) {
		printf(" 1");
	}
	puts("");
	return 0;
}