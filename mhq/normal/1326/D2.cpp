#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
pair < vector < int >, vector < int > > manacher(string& s) {
    string p;
    for (int i = 0; i < s.size(); i++) {
        p += s[i];
        if (i + 1 < s.size()) p += "#";
    }
    int n = p.size();
    int l = -1;
    int r = -1;
    vector < int > ans(n);
    for (int i = 0; i < n; i++) {
        if (r < i) {
            l = i;
            r = i;
        }
        int d = min(ans[l + r - i], r - i) + 1;
        while (i - d >= 0 && i + d < n && p[i + d] == p[i - d]) d++; d--;
        ans[i] = d;
        if (i + d > r) {
            l = i - d;
            r = i + d;
        }
    }
    vector < int > odd, even;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // odd
            odd.emplace_back(ans[i] / 2);
        }
        else {
            // even
            even.emplace_back((ans[i] + 1) / 2);
            even.back()--;
        }
    }
    return make_pair(odd, even);
}
//   , odd -      , even  
// .. even[i] = -1 ,   
// abbba
// odd   0 0 2 0 0
// even -1 0 0 -1
const int maxN = (int)1e6 + 10;
int rght[maxN];
int ev[maxN];
string solve(string& s) {
    int n = s.size();
    int l = 0;
    int r = n - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        rght[i] = -1;
        ev[i] = -1;
    }
    auto mc = manacher(s);
    for (int i = 0; i <= (n - 1) / 2; i++) {
        int le = i - mc.first[i];
        rght[le] = max(rght[le], i);
    }
    for (int i = 0; i <= (n == 1 ? -1 : (n - 2) / 2); i++) {
        if (mc.second[i] == -1) continue;
        int le = i - mc.second[i];
        ev[le] = max(ev[le], i);
    }
    int ans = -0;
    int best = -1;
    int delta = 0;
    for (int i = 0; i <= l; i++) {
        rght[i + 1] = max(rght[i + 1], rght[i]);
        ev[i + 1] = max(ev[i + 1], ev[i]);
        int cur_sz = 2 * i + max({0, 2 * (ev[l] - l + 1), 2 * (rght[l] - l + 1) - 1});
        if (cur_sz > ans) {
            ans = cur_sz;
            best = i;
            delta = max({0, 2 * (ev[l] - l + 1), 2 * (rght[l] - l + 1) - 1});
        }
    }
    string resp;
    for (int j = 0; j < best; j++) resp += s[j];
    if (delta != 0) {
        if (delta % 2 == 0) {
            for (int j = l; j <= ev[l]; j++) resp += s[j];
            for (int j = ev[l]; j >= l; j--) resp += s[j];
        }
        else {
            for (int j = l; j <= rght[l]; j++) resp += s[j];
            for (int j = rght[l] - 1; j >= l; j--) resp += s[j];
        }
    }
    for (int j = best - 1; j >= 0; j--) resp += s[j];
    return resp;
}
void solve() {
    string s;
    cin >> s;
    auto p1 = solve(s);
    reverse(s.begin(), s.end());
    auto p2 = solve(s);
    if (p1.size() < p2.size()) swap(p1, p2);
    cout << p1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}