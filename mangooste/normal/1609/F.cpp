#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n);
    vector<int> pc(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pc[i] = __builtin_popcountll(a[i]);
    }

    const int A = 61;
    vector<vector<array<int, 3>>> min_segs(A), max_segs(A);

    auto add_segment = [&](vector<array<int, 3>> &segs, int l, int r) {
        segs.push_back({l, r, (segs.empty() ? 0 : segs.back()[2]) + r - l + 1});
    };

    vector st_min{-1}, st_max{-1};
    ll answer = 0, cur = 0;

    auto query_pref = [&](const vector<array<int, 3>> &segs, int pos) {
        int id = lower_bound(all(segs), array{pos + 1, -1, -1}) - segs.begin() - 1;
        if (id < 0)
            return 0;

        return (id == 0 ? 0 : segs[id - 1][2]) + min(segs[id][1], pos) - segs[id][0] + 1;
    };

    auto query = [&](const vector<array<int, 3>> &segs, int l, int r) {
        return query_pref(segs, r) - query_pref(segs, l - 1);
    };

    for (int i = 0; i < n; i++) {
        while (len(st_min) > 1 && a[st_min.back()] > a[i]) {
            cur -= query(max_segs[pc[st_min.back()]], st_min.end()[-2] + 1, st_min.back());
            min_segs[pc[st_min.back()]].pop_back();
            st_min.pop_back();
        }

        cur += query(max_segs[pc[i]], st_min.back() + 1, i);
        add_segment(min_segs[pc[i]], st_min.back() + 1, i);
        st_min.push_back(i);

        while (len(st_max) > 1 && a[st_max.back()] < a[i]) {
            cur -= query(min_segs[pc[st_max.back()]], st_max.end()[-2] + 1, st_max.back());
            max_segs[pc[st_max.back()]].pop_back();
            st_max.pop_back();
        }

        cur += query(min_segs[pc[i]], st_max.back() + 1, i);
        add_segment(max_segs[pc[i]], st_max.back() + 1, i);
        st_max.push_back(i);

        answer += cur;
    }

    cout << answer << '\n';
}