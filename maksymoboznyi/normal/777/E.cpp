#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

struct cell {
    int a, b, h;
};

struct node {
    int key, prior, val, value;
    node *l, *r;
    node (int k, int v) {
        key = k;
        val = v;
        value = v;
        prior = rand();
        l = r = 0;
    }
};

typedef node *tnode;

int getVal(tnode t) {
    return (t ? t->val : 0);
}

void recalc(tnode &t) {
    if (!t)
        return;
    t->val = max(getVal(t->l), max(getVal(t->r), t -> value));
}

void merge(tnode &t, tnode &l, tnode &r) {
    if (!l || !r) {
        t = (l ? l : r);
        return;
    }
    if (l->prior > r-> prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    recalc(t);
}

void split(tnode t, tnode &l, tnode &r, int key) {
    if (!t) {
        l = r = 0;
        return;
    }
   // cout << '/' << key << ' ' << t->key << ' ' << t->l << endl;
    if (key > t->key)
        split(t->r, t->r, r, key), l = t;
    else
        split(t->l, l, t->l, key), r = t;
    recalc(t);
}

int get(tnode &t, int key) {
    tnode t1, t2;
    split(t, t1, t2, key);
    int res =  getVal(t1);
    merge(t, t1, t2);
    return res;
}

void add(tnode &t, int key, int val) {
    tnode t1, t2, t3;
    split(t, t1, t2, key);
    t3 = new node(key, val);
    merge(t1, t1, t3);
    merge(t, t1, t2);
}

int n, dp[N];
cell a[N];

bool cmp(cell a, cell b) {
    if (a.b != b.b)
        return a.b > b.b;
    if (a.a != b.a)
        return a.a > b.a;
    return a.h > b.h;
}

signed main()
{
    srand(time(nullptr));
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].a >> a[i].b >> a[i].h;
    sort(a, a + n, cmp);
    dp[0] = a[0].h;
    int ans = a[0].h;
    tnode root = new node(a[0].a, dp[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = a[i].h + get(root, a[i].b);
        add(root, a[i].a, dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}