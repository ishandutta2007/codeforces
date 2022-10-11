#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n, n);
    vector<vector<int>> segs(n);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        a[r - 1] = l;
        segs[l].push_back(r);
    }

    const int B = sqrt(n);

    int q;
    cin >> q;
    vector<vector<pair<int, int>>> queries(n);
    vector<int> answer(q);

    for (int id = 0; id < q; id++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if (x / B == y / B) {
            int l = x, r = x;
            for (int i = x + 1; i <= y; i++)
                if (l <= a[i] && a[i] <= r)
                    r = i;

            answer[id] = r;
            continue;
        }
        queries[x].emplace_back(y, id);
    }

    for (int start = B; start < n; start += B) {
        stack<pair<int, int>> st;
        for (int i = start - 1; i >= 0; i--) {
            int cur_value = i;
            for (auto r : segs[i])
                if (r <= start)
                    while (!st.empty() && st.top().first < r) {
                        cur_value = max(cur_value, st.top().second);
                        st.pop();
                    }

            st.push({i, cur_value});

            for (auto &[rr, id] : queries[i])
                if (start <= rr && rr < start + B) {
                    int l = i, r = st.top().second;
                    // cout << id << ": [" << l << ", " << r << "]" << endl;
                    for (int i = start; i <= rr; i++)
                        if (l <= a[i] && a[i] <= r)
                            r = i;

                    answer[id] = r;
                }
        }
    }

    for (auto x : answer)
        cout << x + 1 << '\n';
}