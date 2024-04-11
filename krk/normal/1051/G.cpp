#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef struct item * pitem;
struct item {
    int prior, value;
    int cnt;
    ll sum;
    ll f;
    pitem l, r;
    item(int val): prior(uniform_int_distribution<int>(0, 1000000000)(rng)), value(val), cnt(1), sum(val), f(0), l(nullptr), r(nullptr) {}
};
 
void Update(pitem it) {
    if (it) {
        it->cnt = 1;
        it->sum = it->value;
        it->f = 0;
        if (it->l) {
            it->cnt += it->l->cnt;
            it->sum += it->l->sum;
            it->f += it->l->f + ll(it->l->cnt) * it->value;
        }
        if (it->r) {
            it->f += it->r->f + ll(it->cnt) * it->r->sum;
            it->sum += it->r->sum;
            it->cnt += it->r->cnt;
        }
    }
}
 
void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    Update(t);
}
 
void split (pitem t, pitem & l, pitem & r, int key) {
    if (!t)
        return void( l = r = 0 );
    if (key >= t->value)
        split (t->l, l, t->l, key),  r = t;
    else
        split (t->r, t->r, r, key),  l = t;
    Update(t);
}
 
pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt, rt;
    split (r, lt, rt, l->value);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    Update(l);
    return l;
}
 
typedef pair <int, pitem> ip;
 
int n;
map <int, ip> M;
ip P;
ll cur;
ll orig;
 
void Insert(int key, int val)
{
    orig += ll(key) * val;
    map <int, ip>::iterator it = M.upper_bound(key);
    if (it != M.begin()) {
        it--;
        if (it->first + it->second.first >= key) {
            cur -= (ll(it->first) * it->second.second->sum + it->second.second->f);
            pitem tr = it->second.second;
            pitem lef, rig;
            split(tr, lef, rig, val);
            merge(tr, lef, new item(val));
            merge(tr, tr, rig);
            key = it->first;
            P = ip(it->second.first + 1, tr);
            M.erase(it++);
        } else P = ip(1, new item(val));
    } else P = ip(1, new item(val));
    it = M.lower_bound(key);
    while (it != M.end() && key + P.first >= it->first) {
        cur -= (ll(it->first) * it->second.second->sum + it->second.second->f);
        P.first += it->second.first;
        P.second = unite(P.second, it->second.second);
        M.erase(it++);
    }
    M.insert(make_pair(key, P));
    cur += (ll(key) * P.second->sum + P.second->f);
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        Insert(a, b);
        printf("%I64d\n", cur - orig);
    }
    return 0;
}