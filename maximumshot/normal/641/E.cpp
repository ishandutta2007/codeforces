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
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;
typedef pair< ll, ll > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

int nxtRand() {
	int v = rand() + 1; 
	if(v < 10000) v = v * 10000 + rand();
	return v;
}

struct Node {
	Node *l, *r;
	int prior;
	int value, cnt;

	Node() {
		l = r = 0;
		prior = nxtRand();
		value = cnt = 0;
	}

	Node(int x) {
		l = r = 0;
		prior = nxtRand();
		value = x;
		cnt = 1;
	}
};

void upd(Node *& v) {
	int c = 1;
	if(v->l) c += v->l->cnt;
	if(v->r) c += v->r->cnt;
	v->cnt = c;
}

void merge(Node *& v, Node *l, Node *r) {
	if(!l || !r) {
		v = (l?l : r);
		return;
	}

	if(l->prior >= r->prior) {
		merge(l->r, l->r, r);
		v = l;
	}else {
		merge(r->l, l, r->l);
		v = r;
	}

	if(v) upd(v);
}

// < val
void split(Node *v, Node *& l, Node *& r, int val) {
	if(!v) {
		l = r = 0;
		return;
	}

	if(v->value < val) {
		split(v->r, v->r, r, val);
		l = v;
	}else {
		split(v->l, l, v->l, val);
		r = v;
	}

	if(l) upd(l);
	if(r) upd(r);
}

struct treap {
	Node *t;

	treap() {
		t = 0;
	}

	void insert(int val) {
		Node *nl, *nr;
		nl = nr = 0;
		split(t, nl, nr, val);
		merge(nl, nl, new Node(val));
		merge(t, nl, nr);
	}

	int count(int val) {
		Node *nl, *nr;
		nl = nr = 0;
		split(t, nl, nr, val);
		int res = (nl?nl->cnt : 0);
		merge(t, nl, nr);
		return res;
	}
};

bool solve() {
	
	srand(time(NULL));

	int n;

	scanf("%d", &n);

	vec< int > a(n), t(n), x(n), crd;

	for(int i = 0;i < n;i++) {
		scanf("%d %d %d", &a[i], &t[i], &x[i]);
		crd.push_back(x[i]);
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());
	int sz = (int)crd.size();

	vec< treap > plus(sz, treap()), minus(sz, treap());

	for(int i = 0;i < n;i++) {
		x[i] = lower_bound(ALL(crd), x[i]) - crd.begin();
		if(a[i] == 1) {
			plus[x[i]].insert(t[i]);
		}else if(a[i] == 2) {
			minus[x[i]].insert(t[i]);
		}else {
			printf("%d\n", plus[x[i]].count(t[i]) - minus[x[i]].count(t[i]));
		}
	}

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}