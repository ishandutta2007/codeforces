#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

struct Tree {
    vector<int> op;
    vector<int> sum;
    int sz;

    Tree(int n): op(4 * n + 10), sum(4 * n + 10), sz(n) {}

    void push(int i, int l, int r) {
        if (!op[i])
            return;
        if (l != r) {
            if (op[i] <= 2) {
                op[2 * i + 1] = op[2 * i + 2] = op[i];
            } else {
                op[2 * i + 1] ^= op[i];
                op[2 * i + 2] ^= op[i];
            }
        }
        int len = r - l + 1;
        if (op[i] == 1)
            sum[i] = len;
        else if (op[i] == 2)
            sum[i] = 0;
        else 
            sum[i] = len - sum[i];
        op[i] = 0;
    }

    void upd(int i, int tl, int tr, int l, int r, int nop) {
        push(i, tl, tr);
        if (l == tl && r == tr) {
            op[i] = nop;
            return;
        }
        int m = (tl + tr) / 2;
        if (l <= m)
            upd(2 * i + 1, tl, m, l, min(r, m), nop);
        if (r > m)
            upd(2 * i + 2, m + 1, tr, max(m + 1, l), r, nop);
        push(2 * i + 1, tl, m);
        push(2 * i + 2, m + 1, tr);
        sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
    }

    void upd(int l, int r, int nop) {
        upd(0, 0, sz - 1, l, r, nop);
    }

    int get() {
        return get(0, 0, sz - 1);
    }

    int get(int i, int l, int r) {
        push(i, l, r);
        if (l == r) {
            assert (sum[i] == 0);
            return l;
        }
        int m = (l + r) / 2;
        push(2 * i + 1, l, m);
        push(2 * i + 2, m + 1, r);
        if (sum[2 * i + 1] == m - l + 1)
            return get(2 * i + 2, m + 1, r);
        return get(2 * i + 1, l, m);
    }
        
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> t(n);
    vector<ll> l(n);
    vector<ll> r(n);
    vector<ll> all;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> l[i] >> r[i];
        all.push_back(max(1ll, l[i] - 1));
        all.push_back(l[i]);
        all.push_back(r[i]);
        all.push_back(r[i] + 1);
    }
    all.push_back(1);
    all.push_back(ll(1e18) + 1);
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    Tree tree(all.size());
    for (int i = 0; i < n; i++) {
        l[i] = lower_bound(all.begin(), all.end(), l[i]) - all.begin();
        r[i] = lower_bound(all.begin(), all.end(), r[i]) - all.begin(); 
        tree.upd(l[i], r[i], t[i]);
        cout << all[tree.get()] << "\n";
    }
}