
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n, p[N], invp[N], q[N], tree[4 * N], lazy[4 * N];

void prop(int i, int l, int r) {
    tree[i] += lazy[i];
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
int query(int i, int l, int r, int L, int R) {
    if(R < l || r < L) return INT_MIN;
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int L, int R, int x) {
    prop(i, l, r);
    if(R < l || r < L) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        invp[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    int j = 0;
    for(int i = n; i > 0; i--) {
        upd(0, 1, n, 0, invp[i], 1);
        while(query(0, 1, n, 1, n) > 0) {
            j++;
            upd(0, 1, n, 0, q[j], -1);
            cout << i << " ";
        }
    }
    cout << endl;
}