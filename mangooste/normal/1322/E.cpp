#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    if (n <= 2) {
        cout << "0\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];

        return 0;
    }

    map<int, vector<int>> freq;
    for (int i = 0; i < n; i++)
        freq[a[i]].push_back(i);

    auto values = a;
    sort(all(values));
    values.resize(unique(all(values)) - values.begin());
    
    array<set<int>, 2> sets;
    vector<int> b(n);
    vector<int> c(n, 1);

    for (int i = 0; i < n; i++) {
        b[i] = i % 2;
        sets[b[i]].insert(i);
    }

    set<int> alive;
    for (int i = 1; i < n - 1; i++)
        alive.insert(i);

    auto answer = a;
    int max_len = 0;

    for (auto x : values) {
        auto set_segment = [&](int from, int to) {
            while (true) {
                auto it = alive.lower_bound(from);
                if (it == alive.end() || *it > to)
                    break;

                answer[*it] = x;
                alive.erase(it);
            }
        };

        auto insert_segment = [&](int from, int to) {
            max_len = max(max_len, to - from + 1);
            if (from > to)
                return;

            if ((to - from + 1) % 2 == 1) {
                if (c[from] == 1)
                    set_segment(from, to);
            } else if (c[from] == 1) {
                set_segment(from, (from + to) / 2);
            } else {
                set_segment((from + to) / 2 + 1, to);
            }
        };

        auto solve_candidate = [&](int pos) {
            if (pos < 0 || pos >= n)
                return;

            auto it = sets[b[pos] ^ 1].lower_bound(pos);
            int from = it == sets[b[pos] ^ 1].begin() ? 0 : *prev(it) + 1;
            int to = it == sets[b[pos] ^ 1].end() ? n - 1 : *it - 1;

            if (from + 1 <= to - 1)
                insert_segment(from + 1, to - 1);
        };

        auto update = [&](int pos) {
            sets[b[pos]].erase(pos);
            b[pos] ^= 1;
            sets[b[pos]].insert(pos);
            c[pos] = 0;
        };

        for (auto pos : freq[x])
            update(pos);

        for (auto pos : freq[x]) {
            for (int d : {-1, 0, 1})
                solve_candidate(pos + d);

            for (int d : {-1, 1})
                if (pos + d >= 0 && pos + d < n && c[pos + d] == c[pos] && c[pos + d] == 0) {
                    set_segment(pos + d, pos + d);
                    set_segment(pos, pos);
                }
        }
    }

    cout << (max_len + 1) / 2 << '\n';
    for (int i = 0; i < n; i++)
        cout << answer[i] << " \n"[i == n - 1];
}