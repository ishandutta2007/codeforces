#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

struct Node {
    int stack_size;
    int cnt_pop;
    int value;
    int type;
    Node() : stack_size(0), cnt_pop(0), value(0), type(0) { }
} tree[4 * N];

int m;

Node merge(Node const & l, Node const & r) {
    Node res;
    res.stack_size = max(0, l.stack_size - r.cnt_pop) + r.stack_size;
    res.cnt_pop = l.cnt_pop + max(0, r.cnt_pop - l.stack_size);
    return res;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v] = Node();
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
    }
}

void update(int v, int tl, int tr, int pos, int type, int value = 0) {
    if(tl == tr) {
        tree[v].type = type;
        tree[v].value = value;
        if(type == 1) {
            tree[v].stack_size = 1;
            tree[v].cnt_pop = 0;
        }else {
            tree[v].stack_size = 0;
            tree[v].cnt_pop = 1;
        }
    }else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) update(v << 1, tl, tm, pos, type, value);
        else update(v << 1 | 1, tm + 1, tr, pos, type, value);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
}

int get(int v, int tl, int tr, int del = 0) {
//    cout << tl << " .. " << tr << " = " << del << "\n";
    if(tl == tr) {
        return tree[v].value;
    }else {
        int tm = (tl + tr) >> 1;
        if(tree[v << 1 | 1].stack_size > del) {
            return get(v << 1 | 1, tm + 1, tr, del);
        }else {
            return get(v << 1, tl, tm, del - tree[v << 1 | 1].stack_size + tree[v << 1 | 1].cnt_pop);
        }
    }
}

void show(int v, int tl, int tr) {
    cout << tl << " .. " << tr << " : " << tree[v].stack_size << " " << tree[v].cnt_pop;
    if(tl == tr && tree[v].type == 1) cout << " " << tree[v].value << "\n";
    else cout << "\n";
    if(tl < tr) {
        int tm = (tl + tr) >> 1;
        show(v << 1, tl, tm);
        show(v << 1 | 1, tm + 1, tr);
    }
}

int main() {

    scanf("%d", &m);

    build(1, 1, m);

    for(int pos, type, value, iter = 1;iter <= m;iter++) {
        scanf("%d %d", &pos, &type);
        if(type == 1) {
            scanf("%d", &value);
        }else {
            value = 0;
            type = -1;
        }
        update(1, 1, m, pos, type, value);
//        cout << "\n";
//        show(1, 1, m);
//        cout << "\n";
        if(tree[1].stack_size > 0) {
            printf("%d\n", get(1, 1, m));
        }else {
            printf("-1\n");
        }
    }

    return 0;
}