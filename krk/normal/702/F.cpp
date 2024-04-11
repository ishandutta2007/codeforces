#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> ii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef struct item * pitem;
struct item {
    int prior, lft, ind;
    int cnt;
    int flaglft, flagcnt;
    pitem l, r;
    item(int val, int ind): prior(uniform_int_distribution<int>(1, 1000000000)(rng)), lft(val), ind(ind), cnt(0), flaglft(0), flagcnt(0), l(nullptr), r(nullptr) {}
};
 
void push(pitem it) {
    if (it && (it->flaglft || it->flagcnt)) {
        it->lft -= it->flaglft;
        it->cnt += it->flagcnt;
        if (it->l) {
            it->l->flaglft += it->flaglft;
            it->l->flagcnt += it->flagcnt;
        }
        if (it->r) {
            it->r->flaglft += it->flaglft;
            it->r->flagcnt += it->flagcnt;
        }
        it->flaglft = it->flagcnt = 0;
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

int min(pitem it)
{
    push(it);
    if (it->l) return min(it->l);
    return it->lft;
}

int max(pitem it)
{
    push(it);
    if (it->r) return max(it->r);
    return it->lft;
}
 
void split (pitem t, int key, pitem & l, pitem & r) {
    push(t);
    if (!t)
        l = r = NULL;
    else if (key < t->lft)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
}

void splitMin(pitem t, pitem &l, pitem &r) {
    push(t);
    if (t->l) splitMin(t->l, l, t->l), r = t;
    else split(t->r, -1, t->r, r), l = t;
}
 
const int Maxn = 200005;
 
int n;
ii qc[Maxn];
int k;
ii b[Maxn];
pitem root;
int res[Maxn];
 
void Print(pitem t)
{
    push(t);
    if (!t) return;
    Print(t->l);
    res[t->ind] = t->cnt;
    Print(t->r);
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &qc[i].second, &qc[i].first);
        qc[i].first = -qc[i].first;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    sort(b, b + k);
    for (int i = 0; i < k; i++)
        merge(root, root, new item(b[i].first, b[i].second));
    Print(root);
    sort(qc, qc + n);
    for (int i = 0; i < n; i++) {
        pitem lef, rig; split(root, qc[i].second - 1, lef, rig);
        if (rig) {
            rig->flaglft += qc[i].second;
            rig->flagcnt++;
        }
        while (lef && rig && max(lef) > min(rig)) {
            pitem it;
            splitMin(rig, it, rig);
            pitem A, B;
            split(lef, it->lft, A, B);
            merge(A, A, it);
            merge(lef, A, B);
        }
        merge(root, lef, rig);
    }
    Print(root);
    for (int i = 0; i < k; i++)
        printf("%d%c", res[i], i + 1 < k? ' ': '\n');
    return 0;
}