#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
void alice() {
    cout << "YES" << '\n';
}
void bob() {
    cout << "NO" << '\n';
}
int a, b;
string s;
bool bad(int x) {
    if (x >= 2 * b || (b <= x && x < a)) return true;
    else return false;
}
void solve() {
    cin >> a >> b;
    cin >> s;
    s = 'X' + s;
    s += 'X';
    vector < int > lens;
    int i = 0;
    while (i < s.size()) {
        int j = i + 1;
        while (j < s.size() && s[j] != 'X') j++; j--;
        lens.emplace_back(j - i);
        i = j + 1;
    }
    vector < int > nlens;
    for (int v : lens) {
        if (v < b) continue;
        nlens.emplace_back(v);
    }
    lens = nlens;
    for (int v : lens) {
        if (b <= v && v < a) {
            bob();
            return ;
        }
    }
    int cnt = 0;
    vector < int > big;
    for (int v : lens) {
        if (v >= 2 * b) {
            cnt++;
            big.push_back(v);
        }
    }
    if (cnt >= 2) {
        bob();
        return;
    }
    if (cnt == 0) {
        if (lens.size() % 2) alice();
        else bob();
        return;
    }
    assert(big.size() == 1);
    int p = big[0];
    for (int len1 = 0; len1 + a <= p; len1++) {
        int len2 = p - a - len1;
        if (bad(len1) || bad(len2)) continue;
        int cnt2 = (int)(lens.size() - 1) + (len1 >= a) + (len2 >= a);
        if (cnt2 % 2 == 0) {
            alice();
            return;
        }
    }
    bob();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}