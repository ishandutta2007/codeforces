#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
const int maxN = (int)1e5 + 100;
int n;
int pref[maxN];
int add[maxN];
// pref[i]
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> s;
    n = s.size();
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            pref[i] = min(r - i + 1, pref[i - l]);
        }
        while (i + pref[i] < n && s[pref[i]] == s[i + pref[i]]) pref[i]++;
        if (i + pref[i] - 1 > r) {
            l = i, r = i + pref[i] - 1;
        }
    }
    pref[0] = n;
    for (int i = 0; i < n; i++) {
        add[0]++;
        add[pref[i]]--;
    }
    vector < pair < int, int > > ans;
    int del = 0;
    for (int i = 0; i < n; i++) {
        del += add[i];
        if (pref[n - 1 - i] == i + 1) {
            ans.emplace_back(i + 1, del);
        }
    }
    cout << ans.size() << '\n';
    for (auto it : ans) cout << it.first << " " << it.second << '\n';
    return 0;
}