#include <bits/stdc++.h>
using namespace std;
int n, m;
vector < pair < int, int > > v;
vector < int > g[5 * (int)1e5];
vector < int > all;
vector < pair < int, int > > seg[5 * (int)1e5];
map < int, int > s;
int dp[5 * (int)1e5];
int ndp[5 * (int)1e5];
void upd(int i, int j, int l) {
    if (dp[j] > seg[i][j].second) return;
    int pt = max(dp[j], seg[i + 1][l].first);
    if (pt > seg[i + 1][l].second || pt > seg[i][j].second) return;
    if (pt > seg[i][j].second || pt < seg[i][j].first) return;
    ndp[l] = min(ndp[l], pt);
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    v.resize(m);
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i].first >> v[i].second;
        all.push_back(v[i].first);
        if (v[i].first == n && v[i].second == n) {
            cout << -1;
            return 0;
        }
    }
    all.push_back(1);
    all.push_back(n);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    int sz = 0;
    int i = 0;
    for (int i = 0; i < all.size(); i++){
        sz++;
        s[all[i]] = sz;
        if (i == all.size() - 1) break;
        if (all[i + 1] - all[i] == 1) continue;
        else sz++;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= sz; i++) {
        g[i].push_back(0);
    }
    for (int i = 0; i < v.size(); i++) {
        g[s[v[i].first]].push_back(v[i].second);
    }
    for (int i = 1; i <= sz; i++) {
        g[i].push_back(n + 1);
    }
    // <l1, r1>
    for (int i = 1; i <= sz; i++) {
        for (int j = 0; j + 1 < g[i].size(); j++) {
            if (g[i][j] + 1 > g[i][j + 1] - 1) continue;
            seg[i].push_back(make_pair(g[i][j] + 1, g[i][j + 1] - 1));
        }
    }
    int inf = n + 100;
    for (int i = 0; i < seg[1].size(); i++) dp[i] = inf;
    dp[0] = 1;
    for (int i = 1; i + 1 <= sz; i++) {
        for (int j = 0; j < seg[i + 1].size(); j++) ndp[j] = inf;
        int l = 0;
        for (int j = 0; j < seg[i].size(); j++) {
            while (l + 1 < seg[i + 1].size() && seg[i + 1][l].second < seg[i][j].first) l++;
            for (int t = l; t < seg[i + 1].size(); t++) {
                if (seg[i + 1][t].first > seg[i][j].second) break;
                upd(i, j, t);
            }
        }
        for (int j = 0; j < seg[i + 1].size(); j++) dp[j] = ndp[j];
    }
    if (dp[seg[sz].size() - 1] <= n) cout << 2 * n - 2;
    else cout << -1;
	return 0;
}