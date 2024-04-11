#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <time.h>

#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

struct Node {
	LL y;
	Node *l, *r;

	int left, right, MinValue, cnt;

	Node() {
		l = r = 0;
		cnt = 0;
		y = rand() % base;
		left = right = -1;
		MinValue = inf;
	}

	Node(int L, int R, int VAL) {
		l = r = 0;
		y = rand() % base;
		left = L;
		right = R;
		MinValue = VAL;
		cnt = 1;
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

void splitByValue(Node *v, Node *& l, Node *& r, int x) {
	if(!v) {
		l = r = 0;
		return;
	}

	if(v->left <= x) {
		splitByValue(v->r, v->r, r, x);
		l = v;
	}else {
		splitByValue(v->l, l, v->l, x);
		r = v;
	}

	if(l) update(l);
	if(r) update(r);
}

void splitByCnt(Node *v, Node *& l, Node *& r, int x) {
	if(!v) {
		l = r = 0;
		return;
	}

	if(get_cnt(v->l) + 1 <= x) {
		splitByCnt(v->r, v->r, r, x - get_cnt(v->l) - 1);
		l = v;
	}else {
		splitByCnt(v->l, l, v->l, x);
		r = v;
	}

	if(l) update(l);
	if(r) update(r);
}

bool solve()
{
	int n, q;
	scanf("%d %d", &n, &q);

	set< int > s;

	Node *l, *u, *nl, *nm, *nr;
	
	l = new Node(1, n, 1);
	u = new Node(1, n, 1);

	for(int i(0);i < q;i++) {
		int x, y;
		char type;
		scanf("%d %d %c", &x, &y, &type);
		
		if(s.find(y) != s.end()) {
			puts("0");
			continue;
		}

		s.insert(y);

		nl = nm = nr = 0;

		if(type == 'L') {
			splitByValue(l, nl, nr, y);
			splitByCnt(nl, nl, nm, get_cnt(nl) - 1);
			merge(l, nl, nr);

			int left = nm->MinValue;
			int ql = nm->left, qr = nm->right;

			printf("%d\n", x - left + 1);;

			if(ql <= y - 1) {
				nl = nm = nr = 0;
				splitByValue(l, nl, nr, ql);
				merge(nl, nl, new Node(ql, y - 1, left));
				merge(l, nl, nr);
			}
		
			if(y + 1 <= qr) {
				nl = nm = nr = 0;
				splitByValue(l, nl, nr, y + 1);
				merge(nl, nl, new Node(y + 1, qr, left));
				merge(l, nl, nr);
			}

			nl = nm = nr = 0;

			splitByValue(u, nl, nr, y);
			splitByCnt(nl, nl, nm, get_cnt(nl) - 1);
			merge(u, nl, nr);

			int up = nm->MinValue;
			ql = nm->left;
			qr = nm->right;

			if(ql <= y - 1) {
				nl = nm = nr = 0;
				splitByValue(u, nl, nr, ql);
				merge(nl, nl, new Node(ql, y - 1, up));
				merge(u, nl, nr);
			}
			
			if(y + 1 <= qr) {
				nl = nm = nr = 0;
				splitByValue(u, nl, nr, y + 1);
				merge(nl, nl, new Node(y + 1, qr, y + 1));
				merge(u, nl, nr);
			}
		}else {
			splitByValue(u, nl, nr, y);
			splitByCnt(nl, nl, nm, get_cnt(nl) - 1);
			merge(u, nl, nr);

			int up = nm->MinValue;
			int ql = nm->left, qr = nm->right;

			printf("%d\n", y - up + 1);

			if(ql <= y - 1) {
				nl = nm = nr = 0;
				splitByValue(u, nl, nr, ql);
				merge(nl, nl, new Node(ql, y - 1, up));
				merge(u, nl, nr);
			}
			
			if(y + 1 <= qr) {
				nl = nm = nr = 0;
				splitByValue(u, nl, nr, y + 1);
				merge(nl, nl, new Node(y + 1, qr, up));
				merge(u, nl, nr);
			}

			nl = nm = nr = 0;

			splitByValue(l, nl, nr, y);
			splitByCnt(nl, nl, nm, get_cnt(nl) - 1);
			merge(l, nl, nr);

			int left = nm->MinValue;
			ql = nm->left;
			qr = nm->right;

			if(ql <= y - 1) {
				nl = nm = nr = 0;
				splitByValue(l, nl, nr, ql);
				merge(nl, nl, new Node(ql, y - 1, x + 1));
				merge(l, nl, nr);
			}
			
			if(y + 1 <= qr) {
				nl = nm = nr = 0;
				splitByValue(l, nl, nr, y + 1);
				merge(nl, nl, new Node(y + 1, qr, left));
				merge(l, nl, nr);
			}
		}
	}

	return true;
}   

int main() 
{
	//while(solve());
    solve();

    return 0;
}