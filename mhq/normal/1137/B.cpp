#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
int f[2], g[2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    for (auto t : s) {
        f[t - '0']++;
    }
    for (auto s : t) {
        g[s - '0']++;
    }
    if (f[0] < g[0] || f[1] < g[1]) {
        cout << s;
        return 0;
    }
    string tt = t + "#" + t;
    auto z = z_function(tt);
    int n = t.size();
    int need = -1;
    for (int i = n + 2; i <= 2 * n; i++) {
        if (z[i] == (2 * n + 1 - i)) {
            need = i - n - 1;
            break;
        }
    }
    f[0] -= g[0];
    f[1] -= g[1];
    s = t;
    int from;
    if (need == -1) {
        from = 0;
    }
    else {
        from = n - need;
    }
    while (true) {
        for (int j = from; j < n; j++) {
            if (f[t[j] - '0'] == 0) break;
            f[t[j] - '0']--;
            s += t[j];
        }
        if (f[0] == 0 || f[1] == 0) break;
    }
    for (int j = 0; j < f[0]; j++) s += '0';
    for (int j = 0; j < f[1]; j++) s += '1';
    cout << s;
}