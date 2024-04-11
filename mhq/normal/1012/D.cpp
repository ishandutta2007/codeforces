#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 100;
const int maxN = 2 * (int)1e5 + 10;
string s[2];
void calc(vector < pair < int, int > >& g0, vector < pair < int, int > >& g1, vector < pair < int, int > >& ans) {
    int s1 = 0;
    int s2 = 0;
    while (g0.size() > 1 || g1.size() > 1) {
        int c1 = g0.back().second;
        int c2 = g1.back().second;
        if (c1 != c2) {
            ans.push_back(make_pair(s1 + g0.back().first, s2 + g1.back().first));
            int ns2 = s1 + g0.back().first;
            int ns1 = s2 + g1.back().first;
            s1 = ns1;
            s2 = ns2;
            g0.pop_back();
            g1.pop_back();
            if (g0.empty()) g0.push_back(make_pair(0, c2));
            if (g1.empty()) g1.push_back(make_pair(0, c1));
        }
        else {
            if (g0.size() >= g1.size()) {
                ans.push_back({s1 + g0.back().first, 0});
                s2 += s1 + g0.back().first;
                s1 = 0;
                g0.pop_back();
            }
            else if (g1.size() > g0.size()) {
                ans.push_back({s2 + g1.back().first, 0});
                s1 += s2 + g1.back().first;
                s2 = 0;
                g1.pop_back();
            }
        }
    }
}

vector < pair < int, int > > ans, nans;
vector < pair < int, int > > f[2];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s[0] >> s[1];
    for (int i = 0; i < 2; i++) {
        int cur = 1;
        char type = s[i][0];
        for (int j = 1; j < s[i].size(); j++) {
            if (s[i][j] == type) {
                cur++;
            }
            else {
                f[i].push_back(make_pair(cur, type - 'a'));
                type = s[i][j];
                cur = 1;
            }
        }
        f[i].push_back(make_pair(cur, type - 'a'));
        reverse(f[i].begin(), f[i].end());
    }
    bool swapped = false;
    if (f[0].size() < f[1].size()) {
        swapped = true;
        swap(f[0], f[1]);
    }
    vector < pair < int, int > > nf0 = f[0];
    vector < pair < int, int > > nf1 = f[1];
    calc(nf0, nf1, ans);
    int sz1 = f[0].size();
    int sz2 = f[1].size();
    for (int j = (sz1 - sz2 - 5) / 2; j <= (sz1 - sz2 + 5) / 2; j++) {
        for (int k1 = 0; k1 < 2; k1++) {
            if (j >= f[0].size()) continue;
            if (j <= 0) continue;
            if (k1 > f[1].size()) continue;
            vector < pair < int, int > > buf, buf1;
            vector < pair < int, int > > nans;
            vector < pair < int, int > > nf1 = f[0];
            vector < pair < int, int > > nf2 = f[1];
            int sum = 0;
            for (int k = 0; k < j; k++) {
                buf.push_back(nf1.back());
                sum += nf1.back().first;
                nf1.pop_back();
            }
            int sum2 = 0;
            for (int k = 0; k < k1; k++) {
                buf1.push_back(nf2.back());
                sum2 += nf2.back().first;
                nf2.pop_back();
            }
            nans.push_back(make_pair(sum, sum2));
            if ((!nf2.empty()) && (buf.back().second == nf2.back().second)){
                    nf2.back().first += buf.back().first;
                    buf.pop_back();
            }
            while (!buf.empty()) {
                nf2.push_back(buf.back());
                buf.pop_back();
            }
            if ((!buf1.empty()) && buf1.back().second == nf1.back().second) {
                nf1.back().first += buf1.back().first;
                buf1.pop_back();
            }
            while (!buf1.empty()) {
                nf1.push_back(buf1.back());
                buf1.pop_back();
            }
            calc(nf1, nf2, nans);
            if (ans.size() > nans.size()) ans = nans;
        }
    }
    /*int exp = 0;
    if (f[0].size() == f[1].size()) {
        if (f[0].back().second == f[1].back().second) exp = f[0].size();
    }
    else exp = max(f[0].size(), f[1].size()) - 1;
    assert(ans.size() <= exp);*/
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (!swapped) cout << ans[i].first << " " << ans[i].second << '\n';
        else cout << ans[i].second << " " << ans[i].first << '\n';
    }
    return 0;
}