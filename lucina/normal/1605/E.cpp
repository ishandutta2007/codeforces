#include<bits/stdc++.h>
using namespace std;
const int L = 1e6;
const int nax = 3e5 + 10;
int n, nq;
int a[nax];
int b[nax];
int64_t ans[L + 1];
pair <int, int> bar[nax];


int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
    }

    for (int i = 2 ; i <= n ; ++ i) {
        bar[i] = make_pair(a[i] - b[i], 1);
    }
    vector <tuple <int64_t, int, int>> inc, dec;
    int64_t to_add = 0;
    for (int i = 2 ; i <= n ; ++ i) {
        auto [cost, k] = bar[i];
        if (k > 0) {
            int64_t when = (-cost) / k;
            if (cost + when * k < 0) ++ when;
            inc.emplace_back(when, cost, k);
        } else if (k < 0){
            int64_t ak = abs(k);
            int64_t when = cost / ak;
            if (cost - when * ak < 0) ++ when;
            dec.emplace_back(when, cost, k);
        } else if (k == 0) {
            to_add += abs(cost);
        }
        for (int j = i ; j <= n ; j += i) {
            bar[j].first -= cost;
            bar[j].second -= k;
        }
    }

    sort(inc.rbegin(), inc.rend());
    sort(dec.rbegin(), dec.rend());

    int64_t sum_cost_pos = 0, sum_cost_neg = 0;
    int64_t sum_k_pos = 0, sum_k_neg = 0;
    for (auto [_, cost, k] : inc) {
        sum_cost_neg += cost;
        sum_k_neg += k;
    }

    for (auto [_, cost, k] : dec) {
        sum_cost_pos += cost;
        sum_k_pos += k;
    }

    for (int x = 1 ; x <= L ; ++ x) {
        int64_t K = x - a[1];

        while (!inc.empty() && get<0>(inc.back()) <= K) {
            auto [_, cost, k] = inc.back();
            inc.pop_back();
            sum_cost_neg -= cost;
            sum_cost_pos += cost;
            sum_k_neg -= k;
            sum_k_pos += k;
        }
        while (!dec.empty() && get<0>(dec.back()) <= K) {
            auto [_, cost, k] = dec.back();
            dec.pop_back();
            sum_cost_neg += cost;
            sum_cost_pos -= cost;
            sum_k_neg += k;
            sum_k_pos -= k;
        }
        ans[x] = sum_cost_pos - sum_cost_neg + K * (sum_k_pos - sum_k_neg);
        ans[x] += abs(K);
    }

    int Q;
    cin >> Q;
    while (Q -- ) {
        int x;
        cin >> x;
        cout << to_add + ans[x] << '\n';
    }
}
/*
    Missing the contest. :3
*/