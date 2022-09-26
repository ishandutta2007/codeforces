#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int64_t N; cin >> N;
    vector<tuple<char, int64_t, int64_t>> ops;
    auto make_sum = [&](int64_t x, int64_t y) {
        ops.emplace_back('+', x, y);
    };
    auto make_xor = [&](int64_t x, int64_t y) {
        ops.emplace_back('^', x, y);
    };
    {
        int64_t _N = N;
        for (int i = 1; i < 40; ++i) {
            make_sum(_N, _N);
            _N *= 2;
        }
    }
    make_xor(N, N);
    mt19937_64 rng(58);
    vector<int64_t> basis(60, 0);
    while (basis[0] == 0) {
        int64_t val = rng() % (int64_t(1)<<40);
        int64_t cur = 0;
        for (int i = 0; i < 40; ++i) if (val >> i & 1) {
            make_sum(cur, N << i);
            cur += (N << i);
        }
        while (cur) {
            int l = __lg(cur);
            if (basis[l]) {
                make_xor(basis[l], cur);
                cur ^= basis[l];
            } else {
                basis[l] = cur;
                break;
            }
        }
    }
    cout << ops.size() << '\n';
    for (auto op : ops) {
        cout << get<1>(op) << ' ' << get<0>(op) << ' ' << get<2>(op) << '\n';
    }
}