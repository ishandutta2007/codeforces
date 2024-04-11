#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 1<<20;

string s;
int n, m;

struct data {
    int bst, lt, rt;
    data() : bst(0), lt(0), rt(0) {}
    data(int bst, int lt, int rt) : bst(bst), lt(lt), rt(rt) {}
} tree[2*MAXN];

data prop(data d1, data d2) {
    return data(d1.bst + d2.bst + 2*min(d1.lt, d2.rt),
                d1.lt + d2.lt - min(d1.lt, d2.rt),
                d1.rt + d2.rt - min(d1.lt, d2.rt));
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        if (s[lt] == '(')
            tree[cur] = data(0, 1, 0);
        else
            tree[cur] = data(0, 0, 1);
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = prop(tree[2*cur], tree[2*cur+1]);
    }
}

data query(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return data();
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return prop(query(2*cur, lt, mid, ql, qr),
                    query(2*cur+1, mid, rt, ql, qr));
    }
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> s; n = s.length();

    init(1, 0, n);

    cin >> m;
    for (int i=0; i<m; i++) {
        int l, r; cin >> l >> r;
        l--;
        cout << query(1, 0, n, l, r).bst << '\n';
    }

    return 0;
}