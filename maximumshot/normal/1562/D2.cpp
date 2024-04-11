#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<vector<int>> fast(int n, int q, string s, vector<pii> qs) {
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int x = s[i] == '+' ? +1 : -1;
        if (i % 2) x = -x;
        p[i] = (i > 0 ? p[i - 1] : 0) + x;
    }
    vector<vector<int>> res(q);
    unordered_map<int, set<int>> Q;
    for (int i = 0; i < n; i++) {
        int x = s[i] == '+' ? +1 : -1;
        if (i % 2) x = -x;
        Q[2 * (i > 0 ? p[i - 1] : 0) + x].insert(i);
    }
    for (int it = 0; it < q; it++) {
        auto [l, r] = qs[it];
        int S = p[r] - (l > 0 ? p[l - 1] : 0);
        if (S == 0) {
            res[it] = {};
            continue;
        }
        if (S % 2) {
            int need = S + 2 * (l > 0 ? p[l - 1] : 0);
            res[it] = {*Q[need].lower_bound(l)};
        } else {
            S = p[r - 1] - (l > 0 ? p[l - 1] : 0);
            int need = S + 2 * (l > 0 ? p[l - 1] : 0);
            res[it] = {*Q[need].lower_bound(l)};
            res[it].push_back(r);
        }
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<pii> qs(q);
        for (auto& [l, r] : qs)
            cin >> l >> r, l--, r--;
        auto res = fast(n, q, s, qs);
        for (auto x : res) {
            cout << (int) x.size() << "\n";
            for (auto y : x)
                cout << y + 1 << " ";
            cout << "\n";
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}