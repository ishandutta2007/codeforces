#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> z_function (vector < int > s) {
    int n = (int) s.size();
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
int n, m;
string s, t;
const int maxN = 2 * (int)1e5 + 100;
int cnt[maxN][26];
vector < int > posT[30], posS[30];
bool ok[maxN][26];
int nxt[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) posS[s[i] - 'a'].push_back(i);
    for (int i = 0; i < t.size(); i++) posT[t[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; i++) {
        if (posT[i].empty()) continue;
        if (posT[i].size() == 1) {
            for (int k = 0; k < n; k++) ok[k][i] = true;
            continue;
        }
        for (int r = 0; r < 26; r++) {
            vector<int> dif;
            for (int j = 0; j + 1 < posT[i].size(); j++) {
                dif.push_back(posT[i][j + 1] - posT[i][j]);
            }
            dif.push_back(-228);
            for (int j = 0; j + 1 < posS[r].size(); j++) {
                dif.push_back(posS[r][j + 1] - posS[r][j]);
            }
            auto z = z_function(dif);
            int k = posT[i].size();
            for (int j = 0; j < posS[r].size(); j++) {
                if (z[j + k] == k - 1) {
                    //cout << i << " " << j << " hre " << endl;
                    ok[posS[r][j] - posT[i][0]][i] = true;
                }
            }
        }
    }
    vector < int > ans;
    for (int i = 0; i <= n - m; i++) {
        vector < int > par(26, -1);
        vector < int > cnt(26, 0);
        bool can = true;
        for (int k = 0; k < 26; k++) {
            if (posT[k].empty()) continue;
            if (!ok[i][k]) {
                can = false;
                break;
            }
            int what = i + posT[k][0];
            cnt[s[what] - 'a']++;
            par[k] = s[what] - 'a';
        }
        for (int k = 0; k < 26; k++) {
            if (cnt[k] > 1) {
                can = false;
                break;
            }
            if (par[k] == -1) continue;
            if (par[par[k]] != -1) {
                if (par[par[k]] != k) {
                    can = false;
                    break;
                }
            }
        }
        if (can) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << '\n';
    for (int v : ans) cout << v << " ";
}