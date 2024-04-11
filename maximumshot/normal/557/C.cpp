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

	LL value, sum, cnt;

	Node() {
		y = rand() % base;
		l = r = 0;
		cnt = value = sum = 0;
	}

	Node(LL val) {
		y = rand() % base;
		l = r = 0;
		value = sum = val;
		cnt = 1;
	}
};

void update(Node *& v) {
	LL c, s;
	c = 1;
	s = v->value;
	if(v->l) c += v->l->cnt, s += v->l->sum;
	if(v->r) c += v->r->cnt, s += v->r->sum;
	v->cnt = c;
	v->sum = s;
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

LL get_cnt(Node *v) {
	return (v?v->cnt : 0);
}

void split(Node *v, Node *& l, Node *& r, LL x) {
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

void splitByValue(Node *v, Node *& l, Node *& r, LL value) {
	if(!v) {
		l = r = 0;
		return;
	}

	if(v->value <= value) {
		splitByValue(v->r, v->r, r, value);
		l = v;
	}else {
		splitByValue(v->l, l, v->l, value);
		r = v;
	}

	if(l) update(l);
	if(r) update(r);
}

bool solve()
{
	int n;
	scanf("%d", &n);

	vec< pair<int, int> > a(n);
	vec< int > l;
	vec< LL > cost(1e5 + 10);
	vec< vec< int > > all(1e5 + 10);

	for(int i(0);i < n;i++) scanf("%d", &a[i].second), l.push_back(a[i].second);
	for(int i(0);i < n;i++) scanf("%d", &a[i].first), cost[a[i].second] += a[i].first, all[a[i].second].push_back(a[i].first);
	for(int i(1e5 + 8);i >= 0;i--) cost[i] += cost[i + 1];

	sort(ALL(l));
	l.resize(unique(ALL(l)) - l.begin());

	Node *t, *nl, *nm, *nr;
	t = 0;

	LL ans = inf64;

	for(int i(0);i < (int)l.size();i++) {
		LL len = l[i];
		LL tmp = cost[l[i] + 1];
		LL x = (int)all[len].size();

		nl = nm = nr = 0;

		if(get_cnt(t) > x - 1) {
			split(t, nl, nr, get_cnt(t) - (x - 1));
			tmp += (nl?nl->sum : 0);
			merge(t, nl, nr);
		}

		ans = min(ans, tmp);

		for(int j(0);j < (int)all[len].size();j++) {
			nl = nm = nr = 0;
			LL value = all[len][j];
			splitByValue(t, nl, nr, value);
			merge(nl, nl, new Node(value));
			merge(t, nl, nr);
		}
	}

	cout << ans << '\n';

	return true;
}   

int main() 
{
	//while(solve());
    solve();

    return 0;
}