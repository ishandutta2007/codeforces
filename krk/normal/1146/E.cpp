#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
	int prior;
	ii value;
	int cnt;
	pitem l, r;
	item(ii val = ii(0, 0)): prior(rng()), value(val), cnt(1), l(NULL), r(NULL) {}
};

int n, q;
vector <ii> bel, ab;
pitem trbel, trab;
int res[Maxn];

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
	if (it)
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void splitValue(pitem t, pitem &l, pitem &r, ii val)
{
    if (!t)
        return void(l = r = 0);
    if (val < t->value)
        splitValue(t->l, l, t->l, val), r = t;
    else splitValue(t->r, t->r, r, val), l = t;
    upd_cnt(t);
}

void splitLess(pitem t, pitem &l, pitem &r, int val)
{
    if (!t)
        return void(l = r = 0);
    if (val <= t->value.first)
        splitLess(t->l, l, t->l, val), r = t;
    else splitLess(t->r, t->r, r, val), l = t;
    upd_cnt(t);
}

void splitMore(pitem t, pitem &l, pitem &r, int val)
{
    if (!t)
        return void(l = r = 0);
    if (val >= t->value.first)
        splitMore(t->r, t->r, r, val), l = t;
    else splitMore(t->l, l, t->l, val), r = t;
    upd_cnt(t);
}

void unite(pitem &t, pitem fir, pitem sec)
{
	if (!fir || !sec)
		t = fir ? fir : sec;
	else if (fir->prior > sec->prior) {
        pitem a, b; splitValue(sec, a, b, fir->value);
        unite(fir->l, fir->l, a);
        unite(fir->r, fir->r, b);
        t = fir;
	} else {
        pitem a, b; splitValue(fir, a, b, sec->value);
        unite(sec->l, sec->l, a);
        unite(sec->r, sec->r, b);
        t = sec;
	}
	upd_cnt(t);
}

void Print(pitem t, bool neg)
{
    if (!t) return;
    Print(t->l, neg);
    res[t->value.second] = t->value.first;
    if (neg) res[t->value.second] = -res[t->value.second];
    Print(t->r, neg);
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (a >= 0) ab.push_back(ii(a, i));
        else bel.push_back(ii(-a, i));
    }
    sort(ab.begin(), ab.end());
    sort(bel.begin(), bel.end());
    for (int i = 0; i < ab.size(); i++)
        merge(trab, trab, new item(ab[i]));
    for (int i = 0; i < bel.size(); i++)
        merge(trbel, trbel, new item(bel[i]));
    while (q--) {
        char s; int x; scanf(" %c %d", &s, &x);
        if (s == '>')
            if (x >= 0) {
                pitem a, b; splitMore(trab, a, b, x);
                unite(trbel, trbel, b); trab = a;
            } else {
                pitem a, b; splitLess(trbel, a, b, -x);
                unite(trbel, b, trab); trab = a;
            }
        else if (x >= 0) {
                pitem a, b; splitLess(trab, a, b, x);
                unite(trab, b, trbel); trbel = a;
             } else {
                pitem a, b; splitMore(trbel, a, b, -x);
                unite(trab, trab, b); trbel = a;
             }
    }
    Print(trab, false);
    Print(trbel, true);
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}