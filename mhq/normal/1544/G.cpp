#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
pair<vector<pair<int,int>>, string> to_canon(string a, int k) {
    int ones = 0;
    for (char& c : a) {
        if (c == '1') ones++;
    }
    vector<pair<int,int>> to_rev;
    if (ones == k) {
        int last = -1;
        for (int x = 0; x < n; x++) {
            if (a[x] == '1') last = x;
        }
        to_rev.emplace_back(0, last);
        reverse(a.begin() + 0, a.begin() + last + 1);
        assert(a[0] == '1');
        last = -1;
        for (int x = 0; x < n; x++) {
            if (a[x] == '1') last = x;
        }
        string b = a;
        reverse(b.begin() + 0, b.begin() + last + 1);
        if (b < a) {
            to_rev.emplace_back(0, last);
            a = b;
        }
        return make_pair(to_rev, a);
    }
    int from = 0;
    int MOVES = 0;
    if (k != 1) MOVES = ones - k - 1;
    else MOVES = ones;
    for (int mv = 0; mv < MOVES; mv++) {
        int cnt = 0;
        int pos = -1;
        for (int x = from; x < n; x++) {
            if (a[x] == '1') {
                cnt++;
                if (cnt == k) {
                    pos = x;
                    break;
                }
            }
        }
        assert(pos != -1);
        reverse(a.begin() + from, a.begin() + pos + 1);
        to_rev.emplace_back(from, pos);
        from++;
    }
    if (k == 1) {
        return make_pair(to_rev, a);
    }
    for (int z = 0; z < from; z++) {
        assert(a[z] == '1');
    }
    for (int c = 0; c < k; c++) {
        int fi = -1;
        int last = -1;
        for (int t = from; t < n; t++) {
            if (a[t] == '1') {
                last = t;
                if (fi == -1) fi = t;
            }
        }
        if (c % 2 == 1) {
            reverse(a.begin() + fi + 1, a.begin() + last + 1);
            to_rev.emplace_back(fi + 1, last);
        }
        else {
            reverse(a.begin() + fi, a.begin() + last);
            to_rev.emplace_back(fi, last - 1);
        }
    }
    if (k % 2 == 0) {
        return make_pair(to_rev, a);
    }
    for (int step = 0; step < k + 1; step++) {
        int fi = -1;
        int last = -1;
        int bal = 0;
        for (int t = from; t < n; t++) {
            if (a[t] == '1') {
                bal++;
                last = t;
                if (bal == 1) fi = t + 1;
            }
        }
        if (step % 2 == 0) {
            reverse(a.begin() + from, a.begin() + last);
            to_rev.emplace_back(from, last - 1);
        }
        else {
            reverse(a.begin() + fi, a.begin() + last + 1);
            to_rev.emplace_back(fi, last);
        }
    }
    for (int x = 0; x < a.size(); x++) {
        if (x < ones) assert(a[x] == '1');
        else assert(a[x] == '0');
    }
    assert(to_rev.size() <= 2 * a.size());
    return make_pair(to_rev, a);
}
void solve() {
    cin >> n >> k;
    string a;
    string b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') cnt1++;
        if (b[i] == '1') cnt2++;
    }
    if (cnt1 != cnt2) {
        cout << -1 << '\n';
        return;
    }
    if (cnt1 < k) {
        cout << -1 << '\n';
        return;
    }
    if (k == 0) {
        cout << -1 << '\n';
        return;
    }
    auto t1 = to_canon(a, k);
    auto t2 = to_canon(b, k);
    if (t1.second != t2.second) {
        cout << -1 << '\n';
    }
    else {
        auto p1 = t1.first;
        auto p2 = t2.first;
        reverse(p2.begin(), p2.end());
        cout << p1.size() + p2.size() << '\n';
        for (auto& it : p1) {
            cout << it.first + 1 << " " << it.second + 1 << '\n';
            reverse(a.begin() + it.first, a.begin() + it.second + 1);
        }
        for (auto& it : p2) {
            cout << it.first + 1 << " " << it.second + 1 << '\n';
            reverse(a.begin() + it.first, a.begin() + it.second + 1);
        }
        assert(a == b);
    }
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