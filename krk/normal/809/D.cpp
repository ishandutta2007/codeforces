#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    int prior, key, val;
    int add;
    pitem l, r;
    item(int key = 0, int val = 0): prior(uniform_int_distribution<int>(0, 1000000000)(rng)), key(key), val(val), add(0), l(nullptr), r(nullptr) {}
};

void push (pitem it) {
    if (it && it->add) {
        it->val += it->add;
        if (it->l) it->l->add += it->add;
        if (it->r) it->r->add += it->add;
        it->add = 0;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}

void split (pitem t, pitem & l, pitem & r, int key, bool incval) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    if (key <= t->key + (incval? t->val: 0))
        split (t->l, l, t->l, key, incval),  r = t;
    else
        split (t->r, t->r, r, key, incval),  l = t;
}

pitem getLeft(pitem t)
{
    push(t);
    if (t->l) return getLeft(t->l);
    return t;
}

pitem getRight(pitem t)
{
    push(t);
    if (t->r) return getRight(t->r);
    return t;
}

pitem T;
int n;
int l, r;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        pitem lef, mid, rig, tmp;
        split(T, lef, mid, l, true);
        split(mid, mid, rig, r, true);
        if (mid) {
            mid->add++;
            auto froml = getRight(mid);
            int has = froml->val;
            while (rig) {
                auto fromr = getLeft(rig);
                if (has >= fromr->val)
                    split(rig, tmp, rig, fromr->key + 1, false);
                else break;
            }
        }
        int best = 0;
        if (lef) best = max(best, getRight(lef)->val + 1);
        merge(T, lef, mid);
        merge(T, T, rig);
        int akey = l - best, aval = best;
        split(T, lef, rig, akey + 1, false);
        if (!lef || getRight(lef)->val < aval) {
            merge(T, lef, rig);
            split(T, lef, rig, akey, false);
            while (rig) {
                auto fromr = getLeft(rig);
                if (aval >= fromr->val)
                    split(rig, tmp, rig, fromr->key + 1, false);
                else break;
            }
            merge(T, lef, new item(akey, aval));
            merge(T, T, rig);
        } else merge(T, lef, rig);
    }
    cout << getRight(T)->val + 1 << endl;
    return 0;
}