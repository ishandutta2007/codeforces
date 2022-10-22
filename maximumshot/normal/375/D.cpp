#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

struct Node {
	Node *l, *r;
	int y, cnt, key, now;

	Node() {
		l = r = 0;
		y = rand();
		cnt = now = 0;
		key = -1;
	}

	Node(int x) {
		l = r = 0;
		y = rand();
		cnt = now = 1;
		key = x;
	}

	void show() {
		if(l) l->show();
		cout << "{" << key << " " << now << "} ";
		if(r) r->show();
	}
};

void upd(Node *& v) {
	int c = v->now;
	if(v->l) c += v->l->cnt;
	if(v->r) c += v->r->cnt;
	v->cnt = c;
}

void merge(Node *& v, Node *l, Node *r) {
	if(!l || !r) {
		v = (l?l : r);
		return;
	}

	if(l->y >= r->y) {
		merge(l->r, l->r, r);
		v = l;
	}else {
		merge(r->l, l, r->l);
		v = r;
	}

	if(v) upd(v);
}

void split(Node * v, Node *& l, Node *& r, int x) {
	if(!v) {
		l = r = 0;
		return;
	}

	if(v->key <= x) {
		split(v->r, v->r, r, x);
		l = v;
	}else {
		split(v->l, l, v->l, x);
		r = v;
	}

	if(l) upd(l);
	if(r) upd(r);
}

void insert(Node *& t, int x) {
	Node *nl, *nm, *nr;
	nl = nm = nr = 0;
	split(t, nl, nr, x);
	split(nl, nl, nm, x - 1);
	if(nm) nm->now++, nm->cnt++;
	else nm = new Node(x);
	merge(nl, nl, nm);
	merge(t, nl, nr);
}

void erase(Node *& t, int x) {
	Node *nl, *nm, *nr;
	nl = nm = nr = 0;
	split(t, nl, nr, x);
	split(nl, nl, nm, x - 1);
	if(nm && nm->now > 1) {
		nm->now--;
		nm->cnt--;
		merge(nl, nl, nm);
		merge(t, nl, nr);
	}else merge(t, nl, nr);
}

int n, m;
vec< int > c, ans;
vec< vec< int > > g;
vec< vec< pii > > ask;  

void read() {
	scanf("%d %d", &n, &m);
	c.resize(n + 1);
	for(int i = 1;i <= n;i++) scanf("%d", &c[i]);
	g.resize(n + 1);
	ask.resize(n + 1);
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int v, k, i = 0;i < m;i++) {
		scanf("%d %d", &v, &k);
		ask[v].push_back(mp(k, i));
	}
}

vec< map< int, int > > cnt;
vec< Node * > tree;  

void dfs(int v = 1, int par = -1) {
	cnt[v][c[v]] = 1;
	tree[v] = new Node(1);
	for(auto to : g[v]) {
		if(to == par) continue;
		dfs(to, v);
		if((int)cnt[v].size() < (int)cnt[to].size()) swap(cnt[v], cnt[to]), swap(tree[v], tree[to]);
		for(auto it : cnt[to]) {
			int color = it.first;
			int _count = it.second;
			erase(tree[v], cnt[v][color]);
			cnt[v][color] += _count;
			insert(tree[v], cnt[v][color]);
		}
	}

	for(auto it : ask[v]) {
		int id, k;
		k = it.first;
		id = it.second;
		Node *nl, *nr;
		nl = nr = 0;
		split(tree[v], nl, nr, k - 1);
		ans[id] = (nr?nr->cnt : 0);
		merge(tree[v], nl, nr);
	}
	/*cout << v << " : ";
	for(auto it : cnt[v]) cout << "{" << it.first << " " << it.second << "} ";
	cout << " | ";
	tree[v]->show();
	cout << "\n";*/
}

bool solve() {

	read();

	cnt.resize(n + 1);
	tree.resize(n + 1);
	ans.resize(m);

	dfs();

	for(int i = 0;i < m;i++) printf("%d\n", ans[i]);

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}