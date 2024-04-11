#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
const int maxN = (int)1e5 + 10;
int f = 0;
set < pair < int, int > > s[maxN]; // we, ans
pair < pair < int, int >, int > edge[maxN];
int ans[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = make_pair(make_pair(u, v), w);
    }
    for (int i = m; i >= 1; i--) {
        int u = edge[i].first.first;
        int v = edge[i].first.second;
        int w = edge[i].second;
        auto it = s[v].lower_bound(make_pair(w + 1, -1));
        int t = 1;
        if (it != s[v].end()) t += (*it).second;
        ans[i] = t;
        f = max(f, t);
        auto it1 = s[u].lower_bound(make_pair(w, -1));
        if (it1 != s[u].end()) {
            if ((*it1).second >= t) {
                continue;
            }
        }
        while (1) {
            auto it1 = s[u].lower_bound(make_pair(w, -1));
            if (it1 == s[u].begin()) break;
            it1--;
            if ((*it1).second < t) {
                s[u].erase(it1);
            }
            else break;
        }
        s[u].insert(make_pair(w, t));
    }
    cout << f;
    return 0;
}