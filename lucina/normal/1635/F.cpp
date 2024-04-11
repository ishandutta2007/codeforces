#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int64_t INF = 4e18;
int x[nax];
int w[nax];
int n, nq;
vector <pair <int, int>> q[nax];
vector <int> g[nax];
int64_t ans[nax];
/*
* writing fenwick like this support suffix minimum
* by the same property, pos -= pos & -pos will meet pos += pos & -pos somewhere
*/
int64_t bit[nax];
void update(int pos, int64_t val) {
    for (; pos > 0 ; pos -= pos & -pos) {
        bit[pos] = min(bit[pos], val);
    }
}
int64_t get(int pos) {
    int64_t res = INF;;
    for (; pos < nax ; pos += pos & -pos) {
        res = min(res, bit[pos]);
    }
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> nq;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> x[i] >> w[i];
    }

    {
        vector <pair <int, int>> stk;
        for (int i = 1 ; i <= n ; ++ i) {
            while (!stk.empty() && stk.back().first > w[i]) stk.pop_back();
            if (!stk.empty()) {
                g[i].push_back(stk.back().second);
            }
            stk.emplace_back(w[i], i);
        }
    }

    {
        vector <pair <int, int>> stk;
        for (int i = n ; i >= 1 ; -- i) {
            while (!stk.empty() && stk.back().first > w[i]) stk.pop_back();
            if (!stk.empty()) {
                g[stk.back().second].push_back(i);
            }
            stk.emplace_back(w[i], i);
        }
    }

    for (int i = 1 ; i <= nq ; ++ i) {
        int l, r;
        cin >> l >> r;
        q[r].emplace_back(l, i);
    }
    for (int i = 0 ; i < nax ; ++ i)
        bit[i] = INF;

    for (int i = 1 ; i <= n ; ++ i) {
        for (int l : g[i]) {
            int64_t weight = 1LL * (x[i] - x[l]) * (w[i] + w[l]);
            update(l, weight);
        }
        for (auto [l, id] : q[i]) {
            ans[id] = get(l);
        }
    }

    for (int i = 1 ; i <= nq ; ++ i)
        cout << ans[i] << '\n';
}