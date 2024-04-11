#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e6 + 10;
int delta[maxN];
int delta1[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt0 = 0;
    for (char& c : s) {
        if (c == '0') cnt0++;
    }
    for (char& c : t) {
        if (c == '0') cnt0--;
    }
    if (cnt0 != 0) {
        cout << -1;
        return 0;
    }
    vector < int > f[2];
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            f[s[i] - '0'].emplace_back(i);
        }
    }
    assert(f[0].size() == f[1].size());
    for (int i = 0; i < f[0].size(); i++) {
        int l = f[0][i];
        int r = f[1][i];
        if (l < r) {
            delta[l]++;
            delta[r + 1]--;
        }
        else {
            swap(l, r);
            delta1[l]++;
            delta1[r + 1]--;
        }
    }
    int best = 0;
    int best1 = 0;
    for (int i = 0; i < n; i++) {
        if (i) delta[i] += delta[i - 1];
        best = max(best, delta[i]);
        if (i) delta1[i] += delta1[i - 1];
        best1 = max(best1, delta1[i]);
    }
    cout << best + best1;
    return 0;
}