#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <string>

using namespace std;


void solve() {
    string l, r;
    int n;
    cin >> n >> l >> r;
    map<char, vector<int>> L, R;
    for (int i = 0; i < n; ++i) {
        L[l[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        R[r[i]].push_back(i);
    }

    vector<pair<int, int>> result;

    vector<int> ll, rr;

    for (char c = 'a'; c <= 'z'; ++c) {
        int cnt = min(L[c].size(), R[c].size());

        auto& LL = L[c];
        auto& RR = R[c];

        for (int i = 0; i < cnt; ++i) {
            result.emplace_back(LL.back(), RR.back());
            LL.pop_back();
            RR.pop_back();
        }

        for (auto i : LL) {
            ll.push_back(i);
        }
        for (auto i : RR) {
            rr.push_back(i);
        }
    }

    auto& LL = L['?'];
    auto& RR = R['?'];

    while (!LL.empty() && !rr.empty()) {
        result.emplace_back(LL.back(), rr.back());
        LL.pop_back();
        rr.pop_back();
    }

    while (!ll.empty() && !RR.empty()) {
        result.emplace_back(ll.back(), RR.back());
        ll.pop_back();
        RR.pop_back();
    }

    for (int i = 0; i < min(LL.size(), RR.size()); ++i) {
        result.emplace_back(LL[i], RR[i]);
    }

    cout << result.size() << "\n";
    for (auto& p : result) {
        cout << p.first + 1 << ' ' << p.second + 1 << "\n";
    }
}

int main() {
    solve();

    return 0;
}