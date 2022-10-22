#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

struct Node {
	int y, cnt;
	char c;
	Node *l, *r;

	Node() {
		y = rand();
		cnt = 0;
		l = r = 0;
		c = 0;
	}
	Node(char x) {
		l = r = 0;
		y = rand();
		l = r = 0;
		c = x;
		cnt = 1;
	}

	void show() {
		if(l) l->show();
		cout << c;
		if(r) r->show();
	}
};

void update(Node *& v) {
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

	if(l->y >= r->y) {
		merge(l->r, l->r, r);
		v = l;
	}else {
		merge(r->l, l, r->l);
		v = r;
	}

	if(v) update(v);
}

int get_cnt(Node *v) {
	return (v?v->cnt : 0);
}

void split(Node * v, Node *& l, Node *& r, int x) {
	if(!v) {
		l = r = 0;
		return;
	}

	if(get_cnt(v->l) + 1 <= x) {
		split(v->r, v->r, r, x - get_cnt(v->l) - 1);
		l = v;
	}else {
		split(v->l, l, v->l, x);
		r = v;
	}

	if(l) update(l);
	if(r) update(r); 
}

bool solve()
{
	string s;
	cin >> s;
	s = " " + s;

	int m, n;

	cin >> m;

	n = (int)s.size() - 1;

	Node *t = 0;

	for(int i = 1;i <= n;i++) merge(t, t, new Node(s[i]));

	for(;m;m--) {
		int l, r, k;
		cin >> l >> r >> k;

		k %= (r - l + 1);

		if(k == 0) continue;

		Node *nl, *nm, *nr, *qm;

		nl = nm = nr = qm = 0;

		split(t, nl, nr, r);
		split(nl, nl, nm, l - 1);
		split(nm, qm, nm, r - l - k + 1);

		merge(nm, nm, qm);
		merge(nl, nl, nm);
		merge(t, nl, nr);

	}

	t->show();
	cout << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}