
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5, M = 1e9 + 7;

ll pow2[N];

int mod(ll x) {
    return ((x % M) + M) % M;
}

struct node {
    int n0, n1, h;
    node() {
        n0 = n1 = h = 0;
    }
    node operator+(const node o) const {
        node x;
        x.n0 = n0 + o.n0;
        x.n1 = n1 + o.n1;
        if(n1 % 2)
            x.h = mod(h + pow2[n0] * mod(pow2[o.n0] - 1 - o.h));
        else
            x.h = mod(h + pow2[n0] * o.h);
        return x;
    }
    bool operator==(const node o) const {
        return n0 == o.n0 && n1 == o.n1 && h == o.h;
    }
} tree[4 * N];

int n, q, l1, l2, len;
string s;

void build(int i, int l, int r) {
    if(l == r) {
        (s[l - 1] == '0' ? tree[i].n0 : tree[i].n1) = 1;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pow2[0] = 1;
    for(int i = 1; i < N; i++) {
        pow2[i] = mod(2 * pow2[i - 1]);
    }
    cin >> n >> s >> q;
    build(0, 1, n);
    while(q--) {
        cin >> l1 >> l2 >> len;
        cout << (query(0, 1, n, l1, l1 + len - 1) == query(0, 1, n, l2, l2 + len - 1) ? 
                "Yes\n" : "No\n");
    }
}