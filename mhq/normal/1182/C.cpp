#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e6 + 100;
vector < string > all[maxN];
bool vow(char c) {
    return (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u');
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int v = 0;
        for (int j = 0; j < s.size(); j++) {
            v += vow(s[j]);
        }
        all[v].push_back(s);
    }
    vector < pair < string, string > > s, d;
    for (int i = 0; i < maxN; i++) {
        if (all[i].empty()) continue;
        vector < string > f[26];
        for (string p : all[i]) {
            char lst = 'a';
            for (char c : p) {
                if (vow(c)) lst = c;
            }
            f[lst - 'a'].push_back(p);
        }
        vector < string > lft;
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k + 1 < f[j].size(); k += 2) {
                s.emplace_back(f[j][k], f[j][k + 1]);
            }
            if (f[j].size() % 2 == 1) lft.push_back(f[j].back());
        }
        for (int k = 0; k + 1 < lft.size(); k += 2) {
            d.emplace_back(lft[k], lft[k + 1]);
        }
    }
    while (d.size() < s.size()) {
        d.push_back(s.back());
        s.pop_back();
    }
    cout << s.size() << '\n';
    for (int i = 0; i < s.size(); i++) {
        cout << d[i].first << " " << s[i].first << '\n' << d[i].second << " " << s[i].second << '\n';
    }
    return 0;
}