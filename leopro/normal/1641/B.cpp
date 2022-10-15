#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) {cout << (ans) << '\n'; return;}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    map<int, int> cnt;
    for (int x: a) cnt[x]++;
    for (auto[v, count]: cnt) if (count % 2 == 1) answer(-1);
    vector<int> ans;
    vector<pair<int, int>> ins;
    for (int i = 0; i < a.size();) {
        int j = find(a.begin() + i + 1, a.end(), a[i]) - a.begin();
        for (int k = i + 1; k < j; ++k) {
            ins.emplace_back(j + k - i, a[k]);
            a.insert(a.begin() + j - i + k, a[k]);
            a.insert(a.begin() + j - i + k, a[k]);
        }
        ans.push_back(2 * (j - i));
        i += 2 * (j - i);
    }
    cout << ins.size() << '\n';
    for (auto[x, y]: ins) cout << x << ' ' << y << '\n';
    cout << ans.size() << '\n';
    for (int x: ans) cout << x << ' ';
    cout << '\n';
}