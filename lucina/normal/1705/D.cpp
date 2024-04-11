#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
char s[nax];
char t[nax];

void solve() {
    cin >> n >> s >> t;
    string ns;
    string nt;
    for (int i = 0 ; i + 1 < n ; ++ i) {
        ns += '0' + (s[i] ^ s[i + 1]);
        nt += '0' + (t[i] ^ t[i + 1]);
    }
    if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
        cout << "-1\n";
        return;
    }
   // cout << ns << ' ' << nt << '\n';
    if (count(ns.begin(), ns.end(), '0') != count(nt.begin(), nt.end(), '0')) {
        cout << "-1\n";
        return;
    }
    vector <int> pos_s, pos_t;
    for (int i = 0 ; i < ns.size() ; ++ i) {
        if (ns[i] == '1') pos_s.push_back(i);
        if (nt[i] == '1') pos_t.push_back(i);
    }
    int64_t ans = 0;
    for (int i = 0 ; i < pos_s.size() ; ++ i)
        ans += abs(pos_s[i] - pos_t[i]);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}