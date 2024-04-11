#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout <<  (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

int jump[(int) 1e6 + 20][26];

void solve() {
    string s;
    cin >> s;
    vector<int> f(s.size() + 20);
    int n = s.size();
    jump[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; ++i) {
        f[i] = jump[i - 1][s[i] - 'a'];
        if (f[i]) memcpy(jump[i], jump[f[i] - 1], sizeof jump[i]);
        jump[i][s[f[i]] - 'a'] = f[i] + 1;
    }
    int q;
    cin >> q;
    do {
        string t;
        cin >> t;
        for (int i = 0; i < t.size(); ++i) s += t[i];
        for (int i = s.size() - t.size(); i < s.size(); ++i) {
            f[i] = jump[i - 1][s[i] - 'a'];
            if (f[i]) memcpy(jump[i], jump[f[i] - 1], sizeof jump[i]); else memset(jump[i], 0, sizeof jump[i]);
            jump[i][s[f[i]] - 'a'] = f[i] + 1;
        }
        for (int i = 0; i < t.size(); ++i) s.pop_back();
        for (int i = s.size(); i < s.size() + t.size(); ++i) cout << f[i] << ' ';
        cout << '\n';
    } while (--q);
}