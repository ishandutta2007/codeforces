#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

struct node {
    node *l, *r;
    int d;
    node() {
        l = r = 0;
        d = 0;
    }
};

node *build(int tl, int tr) {
    if (tl + 1 == tr) {
        return new node();
    }
    node *ans = new node();
    int m = (tl + tr) >> 1;
    ans->l = build(tl, m);
    ans->r = build(m, tr);
    return ans;
}

node *add(node *v, int tl, int tr, int l, int r, int d) {
    if (r <= tl || tr <= l)
        return v;
    node *ans = new node();
    *ans = *v;
    if (l <= tl && tr <= r) {
        ans->d += d;
        return ans;
    }
    int m = (tl + tr) >> 1;
    ans->l = add(v->l, tl, m, l, r, d);
    ans->r = add(v->r, m, tr, l, r, d);
    return ans;
}

int get(node *v, int tl, int tr, int x) {
    if (tl + 1 == tr)
        return v->d;
    int m = (tl + tr) >> 1;
    if (x < m)
        return v->d + get(v->l, tl, m, x);
    else
        return v->d + get(v->r, m, tr, x);
}

int n, k;
int a[120000];
int pl[120000];
vector<int> gg[120000];
node *ans[120000];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        pl[i] = gg[a[i]].size(), gg[a[i]].push_back(i);
    node *cur = build(0, n);
    for (int i = n - 1; i >= 0; --i) {
        int go = pl[i] + k;
        if (go < gg[a[i]].size())
            cur = add(cur, 0, n, gg[a[i]][go], n, 1);
        ans[i] = cur;
    }
    int q;
    scanf("%d", &q);
    int lst = 0;
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        int l = (x + lst) % n + 1;
        int r = (y + lst) % n + 1;
        if (l > r)
            swap(l, r);
        --l;
        lst = r - l - get(ans[l], 0, n, r - 1);
        printf("%d\n", lst);
    }
    return 0;
}