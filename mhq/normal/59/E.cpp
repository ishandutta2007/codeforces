#include <bits/stdc++.h>
using namespace std;
vector < int > g1[3005];
pair < int, int > prv[3005][3005];
int n, m, k;
map < pair < int, pair < int, int > > , int > t;
//int dist[3005][3005];
queue < pair < int, int > > q;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g1[x].push_back(y);
        g1[y].push_back(x);
    }
    for (int i = 1; i <= k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        t[make_pair(a, make_pair(b, c))] = 1;
    }
    for (int i = 0; i < g1[1].size(); i++) {
        q.push(make_pair(1, g1[1][i]));
        //dist[1][g1[1][i]] = 1;
        prv[1][g1[1][i]] = make_pair(1, 1);
    }
    int ind1 = -1;
    int ind2 = -1;
    bool ok = false;
    while (!q.empty()) {
        //if (ok) break;
        pair < int, int > v = q.front();
        q.pop();
        int x = v.first;
        int y = v.second;
        if (y == n) {
            ind2 = n;
            ind1 = x;
            break;
        }
        for (int i = 0; i < g1[y].size(); i++) {
            if (ok) break;
            int to = g1[y][i];
            if (prv[y][to] != make_pair(0, 0)) continue;
            if (t[make_pair(x, make_pair(y, to))]!= 0) continue;
            prv[y][to] = make_pair(x, y);
            q.push(make_pair(y, to));
        }
    }
    if (ind2 == -1) {
        cout << -1;
        return 0;
    }
    //cout << ind1 << " " << ind2 << endl;
    //cout << "HERE" << endl;
    vector < pair < int, int > > ans;
    while (make_pair(ind1, ind2) != make_pair(1, 1)) {
        ans.push_back(make_pair(ind1, ind2));
        int c1 = prv[ind1][ind2].first;
        int c2 = prv[ind1][ind2].second;
        ind1 = c1;
        ind2 = c2;
    }
    cout << ans.size() << '\n';
    cout << 1 << " ";
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].second << " ";
    }
    return 0;
}