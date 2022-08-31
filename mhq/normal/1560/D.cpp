#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int find_ans(int n, ll pw) {
    string p1 = to_string(n);
    string p2 = to_string(pw);
    int best = 1e9;
    for (int take = 0; take <= p2.size(); take++) {
        string g1 = p2.substr(0, take);
        int ptr = 0;
        for (char& c : p1) {
            if (ptr < (int)g1.size() && c == g1[ptr]) ptr++;
        }
        if (ptr == g1.size()) {
            best = min(best, (int)p2.size() - take + (int)p1.size() - (int)g1.size());
        }
    }
    return best;
}
void solve() {
    int n;
    cin >> n;
    ll pw = 1;
    int ans = find_ans(n, pw);
    for (int x = 0; x < 62; x++) {
        pw *= 2;
        ans = min(ans, find_ans(n, pw));
    }
    cout << ans << '\n';
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