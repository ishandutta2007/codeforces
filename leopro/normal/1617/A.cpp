#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

bool sub(string s, string t) {
    int cur = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == t[cur]) cur++;
        if (cur == t.size()) return true;
    }
    return false;
}

void solve() {
    string s, t;
    cin >> s >> t;
    vector<map<char, char>> transforms(6);
    for (auto &mp: transforms) for (char c = 'a'; c <= 'z'; ++c) mp[c] = c;
    vector<char> p{'a', 'b', 'c'};
    int cur = 0;
    do {
        for (int i = 0; i < 3; ++i) transforms[cur]['a' + i] = p[i];
        cur++;
    } while (next_permutation(p.begin(), p.end()));
    for (auto &mp: transforms) {
        string copy = s;
        sort(copy.begin(), copy.end(), [&](char x, char y) { return mp[x] < mp[y]; });
        if (!sub(copy, t)) {
            cout << copy << '\n';
            return;
        }
    }
}