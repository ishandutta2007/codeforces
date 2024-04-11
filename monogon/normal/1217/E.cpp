#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, q;
int l, r;
int a[N];
int tree[9][4 * N][2];
int pow10[9];

struct minpair {
    int min1;
    int min2;
};

minpair getMin(int d, int i, int l, int r, int ql, int qr) {
    if(qr < l || ql > r) {
        return {INT_MAX, INT_MAX};
    }
    if(ql <= l && r <= qr) {
        return {tree[d][i][0], tree[d][i][1]};
    }
    int m = l + (r - l) / 2;
    minpair p1 = {INT_MAX, INT_MAX}, p2 = {INT_MAX, INT_MAX};
    if(qr >= l && ql <= m) {
        p1 = getMin(d, 2 * i + 1, l, m, ql, qr);
    }
    if(qr >= m + 1 && ql <= r) {
        p2 = getMin(d, 2 * i + 2, m + 1, r, ql, qr);
    }

    int min1 = p1.min1;
    int min2 = p1.min2;
    if(p2.min1 < min1) {
        min2 = min1;
        min1 = p2.min1;
        if(p2.min2 < min2) {
            min2 = p2.min2;
        }
    }else if(p2.min1 < min2) {
        min2 = p2.min1;
    }
    return {min1, min2};
}

void treeset(int d, int i, int l, int r, int idx, int val) {
    if(l == r) {
        tree[d][i][0] = ((val / pow10[d]) % 10 == 0 ? INT_MAX : val);
        tree[d][i][1] = INT_MAX;
        return;
    }
    int m = l + (r - l) / 2;
    if(idx <= m) {
        treeset(d, 2 * i + 1, l, m, idx, val);
    }else {
        treeset(d, 2 * i + 2, m + 1, r, idx, val);
    }
    minpair p1 = {tree[d][2 * i + 1][0], tree[d][2 * i + 1][1]};
    minpair p2 = {tree[d][2 * i + 2][0], tree[d][2 * i + 2][1]};

    int min1 = p1.min1;
    int min2 = p1.min2;
    if(p2.min1 < min1) {
        min2 = min1;
        min1 = p2.min1;
        if(p2.min2 < min2) {
            min2 = p2.min2;
        }
    }else if(p2.min1 < min2) {
        min2 = p2.min1;
    }
    tree[d][i][0] = min1;
    tree[d][i][1] = min2;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p = 1;
    for(int d = 0; d < 9; d++) {
        pow10[d] = p;
        p *= 10;
        for(int i = 0; i < n; i++) {
            treeset(d, 0, 0, n - 1, i, a[i]);
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> q >> l >> r;
        if(q == 1) {
            // update a[l] = r
            for(int d = 0; d < 9; d++) {
                treeset(d, 0, 0, n - 1, l - 1, r);
            }
        }else {
            // query range [l, r]
            int M = INT_MAX;
            for(int d = 0; d < 9; d++) {
                minpair p1 = getMin(d, 0, 0, n - 1, l - 1, r - 1);
                if(p1.min1 < INT_MAX && p1.min2 < INT_MAX) {
                    M = min(M, p1.min1 + p1.min2);
                }
            }
            cout << (M == INT_MAX ? -1 : M) << endl;
        }
    }
}