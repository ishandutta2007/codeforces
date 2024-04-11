#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

struct Tree {
    vector<int> add;
    vector<int> t;
    int n;

    Tree(int sz): add(4 * sz + 10), t(4 * sz + 10), n(sz) {}

    void push(int i) {
        if (2 * i + 2 < (int)add.size()) {
            add[2 * i + 1] += add[i];
            add[2 * i + 2] += add[i];
        }
        t[i] += add[i];
        add[i] = 0;
    }   

    int get(int i, int tl, int tr, int l, int r) {
        push(i);
        if (l == tl && r == tr)
            return t[i];
        int m = (tl + tr) / 2;
        int ml = 0;
        int mr = 0;
        if (l <= m)
            ml = get(2 * i + 1, tl, m, l, min(r, m));
        if (r > m)
            mr = get(2 * i + 2, m + 1, tr, max(m + 1, l), r);
        return max(ml, mr);
    }

    int get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }

    void put(int i, int tl, int tr, int l, int r, int val) {
        push(i);
        if (l == tl && r == tr) {
            add[i] = val;
            return;
        }
        int m = (tl + tr) / 2;
        if (l <= m)
            put(2 * i + 1, tl, m, l, min(r, m), val);
        if (r > m)
            put(2 * i + 2, m + 1, tr, max(m + 1, l), r, val);
        t[i] = max(get(2 * i + 1, 0, 0, 0, 0), get(2 * i + 2, 0, 0, 0, 0));
    }

    void put(int l, int r, int val) {
        put(0, 0, n - 1, l, r, val);
    }
};
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int c = 1; c <= k; c++) {
        Tree tree(n + 1);
        vector<int> last(n + 1, -1);
        for (int i = 0; i < n; i++) {
            int old_dp = dp[c - 1][i];
            tree.put(i, i, old_dp);
            int low = last[a[i]] + 1;
            last[a[i]] = i;
            tree.put(low, i, 1);
            dp[c][i + 1] = tree.get(0, i);
        }
    }
    cout << dp.back().back() << endl;
}