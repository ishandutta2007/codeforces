#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
void solve() {
    string t;
    cin >> t;
    vector<int> f(26, -1);
    for (int i = 0; i < t.size(); i++) {
        f[t[i] - 'a'] = i;
    }
    vector<int> gg;
    for (int i = 0; i < 26; i++) {
        if (f[i] != -1) gg.emplace_back(i);
    }
    sort(gg.begin(), gg.end(), [&](int x, int y) {
         return f[x] > f[y];}
    );
    vector<int> cnt(26);
    for (char& c : t) {
        cnt[c - 'a']++;
    }
    int tot_size = 0;
    int sz = gg.size();
    for (int v : gg) {
        if (cnt[v] % sz != 0) {
            cout << -1 << '\n';
            return ;
        }
        tot_size += cnt[v] / sz;
        sz--;
    }
    if (tot_size > (int)t.size()) {
        cout << -1 << '\n';
    }
    string s = t.substr(0, tot_size);
    string to_del;
    reverse(gg.begin(), gg.end());
    string nt;
    string cops = s;
    for (int u : gg) {
        nt += s;
        to_del += (char)(u + 'a');
        if ((int)nt.size() > (int)t.size()) {
            cout << -1 << '\n';
            return ;
        }
        string ps;
        for (char& c : s) {
            if (c == (char)('a' + u)) continue;
            ps += c;
        }
        s = ps;
    }
    if (nt == t && s.empty()) {
        cout << cops << " " << to_del << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}