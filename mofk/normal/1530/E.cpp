#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> f(26, 0);
        for (int i = 0; i < n; ++i) ++f[s[i] - 'a'];
        int x = -1;
        for (int i = 0; i < 26; ++i) if (f[i] && (x == -1 || f[i] < f[x])) x = i;
        if (f[x] == n) {
            cout << s << endl;
            continue;
        }
        if (f[x] == 1) {
            cout << (char)(x + 'a');
            for (int i = 0; i < 26; ++i) if (i != x) for (int z = 0; z < f[i]; ++z) cout << (char)(i + 'a');
            cout << endl;
            continue;
        }

        int lim = n / 2 + 1;
        for (int i = 0; i < 26; ++i) if (f[i] && f[i] <= lim) {
            x = i;
            break;
        }
        int fx = f[x];
        string t;
        for (auto c: s) if (c != x + 'a') t += c;
        sort(t.begin(), t.end());
        string ans(2, x + 'a');
        fx -= 2;
        for (auto c: t) {
            ans += c;
            if (fx) {
                ans += (char)(x + 'a');
                --fx;
            }
        }

        string ans2;
        t = s;
        string u = "";
        for (char c = 'a'; c <= 'z'; ++c) if (f[c - 'a']) u += c;
        if (u.size() == 2) {
            ans2 += u[0];
            ans2 += u[1];
            for (int z = 1; z < f[u[1] - 'a']; ++z) ans2 += u[1];
            for (int z = 1; z < f[u[0] - 'a']; ++z) ans2 += u[0];
        }
        else {
            ans2 += u[0];
            ans2 += u[1];
            for (int z = 1; z < f[u[0] - 'a']; ++z) ans2 += u[0];
            ans2 += u[2];
            for (int z = 1; z < f[u[1] - 'a']; ++z) ans2 += u[1];
            for (int z = 1; z < f[u[2] - 'a']; ++z) ans2 += u[2];
            for (int i = 3; i < u.size(); ++i) for (int z = 0; z < f[u[i] - 'a']; ++z) ans2 += u[i];
        }
        ans = min(ans, ans2);
        cout << ans << endl;
    }
    return 0;
}