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
#include <math.h>

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
	ll y;

	ll value;
	ll sum, cnt, cnt_now;

	Node() {
		l = r = 0;
		y = rand();
		value = sum = cnt = cnt_now = 0;
	}

	Node(ll x) {
		l = r = 0;
		y = rand();
		value = sum = x;
		cnt = cnt_now = 1;
	}
};

void upd(Node *& v) {
	ll s = 1ll * v->value * v->cnt_now;
	ll c = v->cnt_now;
	if(v->l) s += v->l->sum, c += v->l->cnt;
	if(v->r) s += v->r->sum, c += v->r->cnt;
	v->sum = s;
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

// <= x | > x
void split(Node *v, Node *& l, Node *& r, int x) {
	if(!v) {
		l = r = 0;
		return;
	}
	
	if(v->value <= x) {
		split(v->r, v->r, r, x);
		l = v;
	}else {
		split(v->l, l, v->l, x);
		r = v;
	}

	if(l) upd(l);
	if(r) upd(r);
}

void insert(Node *& t, ll x) {
	Node *nl, *nm, *nr;
	nl = nm = nr = 0;
	split(t, nl, nr, x);
	split(nl, nl, nm, x - 1);
	if(nm) nm->cnt_now++, nm->cnt++, nm->sum += x;
	else nm = new Node(x);
	merge(nl, nl, nm);
	merge(t, nl, nr);
}

void erase(Node *& t, int x) {
	Node *nl, *nm, *nr;
	nl = nm = nr = 0;
	split(t, nl, nr, x);
	split(nl, nl, nm, x - 1);
	nm->cnt_now--, nm->cnt--, nm->sum -= x;
	if(nm->cnt_now == 0) nm = 0;
	merge(nl, nl, nm);
	merge(t, nl, nr);
}

// <= mn
pair< ll, ll > get(Node *& t, int mn) {
	Node *nl, *nr;
	nl = nr = 0;
	split(t, nl, nr, mn);
	ll SUM = (nl?nl->sum : 0);
	ll CNT = (nl?nl->cnt : 0);
	merge(t, nl, nr);
	return mp(SUM, CNT);
}

bool solve() {
	
	ll A, cf, cm, m;
	int n;

	cin >> n >> A >> cf >> cm >> m;

	vec< pii > a(n);
	for(int i = 0;i < n;i++) scanf("%d", &a[i].first), a[i].second = i;

	ll sum = 0;

	for(int i = 0;i < n;i++) sum += a[i].first;

	sum = 1ll * n * A - sum;

	if(sum <= m) {
		cout << 1ll * n * cf + 1ll * A * cm << '\n';
		for(int i = 0;i < n;i++) printf("%d ", A);
		puts("");
		return true;
	}

	sort(ALL(a));
	reverse(ALL(a));

	vec< int > mn(n);
	mn[n - 1] = a[n - 1].first;
	for(int i = n - 2;i >= 0;i--) mn[i] = min(mn[i + 1], a[i].first);

	ll best = -inf64;
	int best_cnt = -1, ans_mn = -1;

	sum = 0;

	Node *t = 0;
	for(int i = 0;i < n;i++) insert(t, a[i].first);

	for(int i = 0;i < n;i++) {
		// [i .. n - 1]
		if(1ll * i * A - sum > m) break;
		if(a[i].first == A) {
			sum += A;
			erase(t, A);
			continue;
		}

		ll ost = m - (1ll * i * A - sum);

		int bl, br, bm, bp;

		bl = mn[i];
		br = A - 1;

		while(br - bl > 1) {
			bm = (bl + br) / 2;
			ll t1, t2;
			tie(t1, t2) = get(t, bm);
			ll need = t2 * (ll)bm - t1;
			if(need <= ost) bl = bm;
			else br = bm - 1;
		}

		ll t1, t2;
		tie(t1, t2) = get(t, br);
		ll need = t2 * br - t1;
		if(need <= ost) bp = br;
		else bp = bl;

		if(1ll * i * cf + 1ll * bp * cm > best) {
			best = 1ll * i * cf + 1ll * bp * cm;
			best_cnt = i;
			ans_mn = bp;
		}

		sum += a[i].first;
		erase(t, a[i].first);
	}

	cout << best << '\n';

	for(int i = 0;i < best_cnt;i++) a[i].first = A;
	for(int i = best_cnt;i < n;i++) if(a[i].first < ans_mn) a[i].first = ans_mn;
	for(int i = 0;i < n;i++) swap(a[i].first, a[i].second);

	sort(ALL(a));

	for(int i = 0;i < n;i++) printf("%d ", a[i].second);
	puts("");

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}