
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N];
ll seg[4 * N], lazy[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        seg[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    seg[i] = min(seg[2 * i + 1], seg[2 * i + 2]);
}

void prop(int i, int l, int r) {
    if(lazy[i] != 0) {
        seg[i] += lazy[i];
        if(l < r) {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
}
ll query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return LLONG_MAX;
    prop(i, l, r);
    if(L <= l && r <= R) return seg[i];
    int m = (l + r) / 2;
    return min(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int L, int R, int x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    seg[i] = min(seg[2 * i + 1], seg[2 * i + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    cin >> m;
    string s;
    getline(cin, s);
    while(m--) {
        getline(cin, s);
        istringstream is(s);
        vector<int> v = vector<int>(istream_iterator<int>(is), istream_iterator<int>());
        int l = v[0], r = v[1];
        if(v.size() == 2) {
            if(l <= r) {
                cout << query(0, 0, n - 1, l, r) << endl;
            }else {
                cout << min(query(0, 0, n - 1, l, n - 1), query(0, 0, n - 1, 0, r)) << endl;
            }
        }else {
            int x = v[2];
            if(l <= r) {
                upd(0, 0, n - 1, l, r, x);
            }else {
                upd(0, 0, n - 1, l, n - 1, x);
                upd(0, 0, n - 1, 0, r, x);
            }
        }
    }
}