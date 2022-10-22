#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

struct Node {
    Node * l;
    Node * r;
    int cnt;
    Node() : l(0), r(0), cnt(0) { }
    Node(int cnt) : l(0), r(0), cnt(cnt) { }
    Node(Node * l, Node * r) : l(l), r(r) {
        cnt = (l ? l->cnt : 0) + (r ? r->cnt : 0);
    }
};

Node * put(Node * v, int tl, int tr, int pos, int val) {
    if(tl == tr) {
        return new Node(val);
    }else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            return new Node(
                put(v ? v->l : 0, tl, tm, pos, val),
                v ? v->r : 0
            );
        }else {
            return new Node(
                v ? v->l : 0,
                put(v ? v->r : 0, tm + 1, tr, pos, val)
            );
        }
    }
}

int const N = 1e5 + 5;

int n;
int a[N];
Node * tree[N];
int last[N];

// exists at least k+1 different values
int get(Node * v, int tl, int tr, int l, int k) {
    if(tl == tr) {
        if((v ? v->cnt : 0) <= k) {
            return tl;
        }else {
            return tl - 1;
        }
    }else {
        int tm = (tl + tr) / 2;
        if(v && (v->l ? v->l->cnt : 0) > k) {
            return get(v ? v->l : 0, tl, tm, l, k);
        }else {
            int cnt;
            if(v && v->l) cnt = v->l->cnt;
            else cnt = 0;
            return get(v ? v->r : 0, tm + 1, tr, l, k - cnt);
        }
    }
}

int get(int l, int k) {
    return get(tree[l], 1, n, l, k);
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = n;i >= 1;i--) {
        if(last[a[i]]) {
            tree[i] = put(tree[i + 1], 1, n, last[a[i]], 0);
        }else {
            tree[i] = tree[i + 1];
        }
        tree[i] = put(tree[i], 1, n, i, 1);
        last[a[i]] = i;
    }

    for(int k = 1;k <= n;k++) {
        int i = 1;
        int res = 0;
        while(i <= n) {
            res++;
            i = get(i, k) + 1;
        }
        printf("%d ", res);
    }
    printf("\n");

    return 0;
}