#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e4 + 100;
vector < pair < int, int > > g[maxN];
const int maxK = 210;
int l[maxK], r[maxK];
int a[maxK], b[maxK];
int n, m, k;
int s1, s2, f;
vector < int > all;
void add(int f) {
    all.push_back(f);
}
ll dist[maxK][maxK];
int id[maxN];
ll now_dist[maxN];
const ll INF = 1e18;
void calc(int v) {
    priority_queue < pair < ll, int > > q;
    for (int i = 1; i <= n; i++) now_dist[i] = INF;
    now_dist[v] = 0;
    q.push(make_pair(-now_dist[v], v));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        ll d = -t.first;
        int u = t.second;
        if (now_dist[u] != d) continue;
        //cout << d << " " << u << " " << v << endl;
        for (auto to : g[u]) {
            if (now_dist[to.first] > d + to.second) {
                now_dist[to.first] = d + to.second;
                q.push({-now_dist[to.first], to.first});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (id[i] != -1) {
            dist[id[v]][id[i]] = now_dist[i];
        }
    }
}
ll copD[maxK][maxK];
bool changed[maxK];
ll D[2][maxK];
bool used[maxK];
void go(int id, int v) {
    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; i++) {
        D[id][i] = INF;
    }
    D[id][v] = 0;
    for (int i = 1; i <= n; i++) {
        pair < ll, int > best = make_pair(INF, 0);
        for (int j = 1; j <= n; j++) {
            if (!used[j]) best = min(best, make_pair(D[id][j], j));
        }
        if (best.second == 0) break;
        int nv = best.second;
        used[nv] = true;
        for (int p = 1; p <= n; p++) {
            D[id][p] = min(D[id][p], D[id][nv] + dist[nv][p]);
        }
    }
}
void win() {
    /*cout << n << " GGG" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }*/
    for (int i = 1; i <= k; i++) {
        go(0, s1);
        go(1, s2);
        for (int j = 1; j <= k; j++) {
            if (D[0][a[j]] < D[1][a[j]] && !changed[j]) {
               // cout << a[j] << " " << b[j] << " HERERER" << endl;
                changed[j] = true;
                dist[a[j]][b[j]] = min(dist[a[j]][b[j]], (ll)l[j]);
                break;
            }
        }
    }
    go(0, s1); go(1, s2);
    if (D[0][f] < D[1][f]) {
        cout << "WIN" << '\n';
        for (int i = 1; i <= k; i++) {
            if (changed[i]) cout << l[i] << " ";
            else cout << r[i] << " ";
        }
        exit(0);
    }
}
void draw() {
    memset(changed, 0, sizeof changed);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = copD[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        go(0, s1);
        go(1, s2);
        for (int j = 1; j <= k; j++) {
            if (D[0][a[j]] <= D[1][a[j]] && !changed[j]) {
                changed[j] = true;
                dist[a[j]][b[j]] = min(dist[a[j]][b[j]], (ll)l[j]);
                break;
            }
        }
    }
    go(0, s1); go(1, s2);
    if (D[0][f] <= D[1][f]) {
        cout << "DRAW" << '\n';
        for (int i = 1; i <= k; i++) {
            if (changed[i]) cout << l[i] << " ";
            else cout << r[i] << " ";
        }
        exit(0);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    cin >> s1 >> s2 >> f;
    add(s1); add(s2); add(f);
    for (int i = 1; i <= m; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        g[from].emplace_back(make_pair(to, val));
    }
    for (int i = 1; i <= k; i++) {
        cin >> a[i] >> b[i] >> l[i] >> r[i];
        add(a[i]);
        add(b[i]);
        g[a[i]].emplace_back(make_pair(b[i], r[i]));
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    memset(id, -1, sizeof id);
    for (int i = 0; i < all.size(); i++) {
        id[all[i]] = i + 1;
    }
    for (int i = 0; i < all.size(); i++) {
        calc(all[i]);
    }
    s1 = id[s1]; s2 = id[s2]; f = id[f];
    for (int i = 1; i <= k; i++) {
        a[i] = id[a[i]];
        b[i] = id[b[i]];
    }
    n = all.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            copD[i][j] = dist[i][j];
        }
    }
    win();
    draw();
    cout << "LOSE";
    return 0;
}