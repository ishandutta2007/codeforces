#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    mt19937 rng(58);
    while (tt--) {
    int N; cin >> N;
    vector<int> P(N); for (int &p : P) cin >> p, --p;
    // shuffle(P.begin(), P.end(), rng);
    // for (int v : P) cerr << v << ' '; cerr << '\n';
    vector<vector<int>> ops;
    auto make = [&](vector<int> d) {
        if (d.size() < 2) return;
        ops.emplace_back(d);
        vector<vector<int>> parts;
        int cur = 0;
        for (int v : d) {
            parts.emplace_back(vector<int>(P.begin() + cur, P.begin() + cur + v));
            cur += v;
        }
        assert(cur == N);
        reverse(parts.begin(), parts.end());
        int i = 0;
        for (auto vv : parts) for (int v : vv) P[i++] = v;
        assert(i == N);
    };
    for (int i = 1; i < N; ++i) {
        int cur = find(P.begin(), P.end(), 0) - P.begin();
        bool rev = false;
        if (cur > 0 && i > 1 && P[cur-1] == 1) rev = true;
        if (rev) {
            // ........321
            int nxt = find(P.begin(), P.end(), i) - P.begin();
            if (nxt < cur) {
                // .........4............321
                vector<int> d;
                if (nxt) d.emplace_back(nxt);
                d.emplace_back(cur - (i-1) - nxt);
                for (int z = 0; z < i; ++z) {
                    d.emplace_back(1);
                }
                if (cur < N-1) d.emplace_back(N-1-cur);
                make(d);
            } else {
                vector<int> d;
                if (cur - (i-1) > 0) d.emplace_back(cur - (i-1));
                d.emplace_back(i);
                d.emplace_back(nxt - cur);
                if (nxt < N-1) d.emplace_back(N-1-nxt);
                make(d);
            }
        } else {
            // ...........123
            int nxt = find(P.begin(), P.end(), i) - P.begin();
            if (nxt < cur) {
                // .......4.........123
                vector<int> d;
                if (nxt > 0) d.emplace_back(nxt);
                d.emplace_back(1);
                d.emplace_back(cur + i -1 - nxt);
                if (cur+i-1 < N-1) d.emplace_back(N-1 - (cur+i-1));
                make(d);
            } else {
                // ........123.........4
                vector<int> d;
                if (cur > 0) d.emplace_back(cur);
                for (int z = 0; z < i; ++z) d.emplace_back(1);
                d.emplace_back(nxt - (cur + i - 1));
                if (nxt < N-1) d.emplace_back(N-1-nxt);
                make(d);
            }
        }
    }
    if (N > 1 && P[0] == N-1) {
        vector<int> d(N, 1);
        make(d);
    }
    assert(is_sorted(P.begin(), P.end()));
    cout << ops.size() << '\n';
    for (auto op : ops) {
        cout << op.size() << ' ';
        for (int v : op) cout << v << ' ';
        cout << '\n';
    }
    }
}