#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int score(string s) {
    int res = 0;
    for (char c : s) {
        res += c - 'a' + 1;
    }
    return res;
}

void solve() {
    string s;
    int n;
    cin >> s;
    n = s.size();
    if (n % 2 == 0) {
        cout << "Alice " << score(s) << '\n';
        return;
    }

    string as = s, bs = s; as.pop_back();
    reverse(bs.begin(), bs.end()); bs.pop_back();
    int score_a = score(as) - (s.back() - 'a' + 1);
    int score_b = score(bs) - (s[0] - 'a' + 1);
    int mx = max(score_a, score_b);
    if (mx > 0) {
        cout << "Alice " << mx << '\n';
    } else cout << "Bob " << -mx << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    sigh...
    too many assignments :)
*/