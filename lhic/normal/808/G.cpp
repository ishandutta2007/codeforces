#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

string s, t;
int pr[120000];
int go[120000][26];
int go1[120000];
int go2[120000];
const int INF = 120000;

int main() {
    cin >> s >> t;
    if (t.size() > s.size()) {
        cout << 0 << "\n";
        return 0;
    }
    pr[0] = 0;
    for (int i = 1; i < t.size(); ++i) {
        int k = pr[i - 1];
        while (k > 0 && t[i] != t[k])
            k = pr[k - 1];
        if (t[i] == t[k])
            ++k;
        pr[i] = k;
    }
    for (int i = 0; i <= t.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            int k = i;
            while (k > 0 && t[k] != (char)('a' + j))
                k = pr[k - 1];
            if (t[k] == (char)('a' + j))
                ++k;
            go[i][j] = k;
        }
    }
    for (int i = 0; i <= t.size(); ++i)
        go1[i] = -INF;
    go1[0] = 0;
    for (int i = 0; i < s.size(); ++i) {
        fill(go2, go2 + t.size(), -INF);
        for (int j = 0; j < t.size(); ++j) {
            if (go1[j] < 0)
                continue;
            if (s[i] == '?') {
                for (int k = 0; k < 26; ++k) {
                    int nw = go[j][k];
                    if (nw == t.size())
                        go2[pr[t.size() - 1]] = max(go2[pr[t.size() - 1]], go1[j] + 1);
                    else
                        go2[nw] = max(go2[nw], go1[j]);
                }
            }
            else {
                int nw = go[j][s[i] - 'a'];
                if (nw == t.size())
                    go2[pr[t.size() - 1]] = max(go2[pr[t.size() - 1]], go1[j] + 1);
                else
                    go2[nw] = max(go2[nw], go1[j]);
            }
        }
        for (int i = 0; i < t.size(); ++i)
            go1[i] = go2[i];
    }
    int ans = 0;
    for (int i = 0; i < t.size(); ++i)
        ans = max(ans, go1[i]);
    cout << ans << "\n";
    return 0;
}