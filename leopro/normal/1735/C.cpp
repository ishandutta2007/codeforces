#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

const int alpha = 26;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(128), up(128);
    vector<bool> free(128, true);
    for (int j = 'a'; j <= 'a' + alpha; ++j) {
        p[j] = -1;
        up[j] = j;
    }
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (p[s[i]] != -1) continue;
        for (int j = 'a'; j <= 'a' + alpha; ++j) {
            if (!free[j]) continue;
            if (s[i] != j && (cnt == alpha - 1 || up[j] != s[i])) {
                free[j] = false;
                p[s[i]] = j;
                cnt++;
                for (int k = 'a'; k <= 'z'; ++k) if (up[k] == s[i]) up[k] = up[j];
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << (char) p[s[i]];
    cout << '\n';
}