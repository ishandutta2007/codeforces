#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = 27;
    int l = -1;
    int r = -1;
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n; j++)
            if (s[i] == s[j]) {
                l = i;
                r = j;
            }
    if (l == -1) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<vector<char>> res(2, vector<char>(13, '0'));
    string pref = s.substr(0, l);
    string suf = s.substr(r + 1, s.length() - r);
    string cycle = s.substr(l, r - l + 1);
    int L = cycle.length();
    int dj = -1;
    int i = 0;
    int j = L / 2 - 1;
    for (int k = 0; k < int(cycle.length()) - 1; k++) {
        if (j < 0) {
            j = 0;
            dj = 1;
            i = 1;
        }
        res[i][j] = cycle[k];
        j += dj;
    }
    reverse(suf.begin(), suf.end());
    reverse(pref.begin(), pref.end());
    pref += suf;
    j = L / 2;
    i = 0;
    dj = 1;
    for (int k = 0; k < pref.length(); k++) {
        if (j == 13) {
            i = 1;
            j = 12;
            dj = -1;
        }
        res[i][j] = pref[k];
        j += dj;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 13; j++)
            cout << res[i][j];
        cout << endl;
    }
    return 0;
}