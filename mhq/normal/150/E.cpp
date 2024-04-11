#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
const int INF = (int)1e9;
int n, l, r;
vector < pair < int, int > > g[maxN];
bool used[maxN];
int sz[maxN];
int bal[maxN], len[maxN];
int WE = 0;

void dfs(int root, int par) {
    sz[root] = 1;
    for (auto t : g[root]) {
        int to = t.first;
        if (to == par || used[to]) continue;
        dfs(to, root);
        sz[root] += sz[to];
    }
}

int TOTAL = 0;

int dfs_cen(int root, int par) {
    bool ok = true;
    for (auto t : g[root]) {
        int to = t.first;
        if (to == par || used[to]) continue;
        int cc = dfs_cen(to, root);
        if (cc != -1) return cc;
        if (2 * sz[to] > TOTAL) ok = false;
    }
    if (ok && 2 * (TOTAL - sz[root]) < TOTAL) return root;
    else return -1;
}

void dfs_calc(int v, int par, vector < int >& vert) {
    vert.push_back(v);
    for (auto t : g[v]) {
        if (used[t.first] || t.first == par) continue;
        len[t.first] = len[v] + 1;
        if (t.second >= WE) bal[t.first] = bal[v] + 1;
        else bal[t.first] = bal[v] - 1;
        dfs_calc(t.first, v, vert);
    }
}

int U, V;

int t[4 * maxN];
int cur_max[maxN], cur_ind[maxN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = cur_max[tl];
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = max(t[v + v], t[v + v + 1]);
}

void upd(int v, int tl, int tr, int r, int val) {
    if (tl == r && tr == r) {
        t[v] = val;
        return ;
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) upd(v + v, tl, tm, r, val);
    else upd(v + v + 1, tm + 1, tr, r, val);
    t[v] = max(t[v + v], t[v + v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return -INF;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return max(get(v + v, tl, tm, l, min(tm, r)), get(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}


int fnd(int v, int par, int le, int ba) {
    if (len[v] == le && bal[v] == ba) return v;
    for (auto t : g[v]) {
        if (used[t.first] || t.first == par) continue;
        int d = fnd(t.first, v, le, ba);
        if (d != -1) return d;
    }
    return -1;
}

bool solve(int root, bool recover) {
    dfs(root, -1);
   // cout << root << " " << recover << " " << WE << endl;
    TOTAL = sz[root];

    int cent = dfs_cen(root, -1);
    assert(cent != -1);

    dfs(cent, -1);
    vector < vector < int > > paths;
    vector < int > my_roots;
    int mx_len = 0;
    for (auto t : g[cent]) {
        if (used[t.first]) continue;
        my_roots.push_back(t.first);
        vector < int > cur;
        if (t.second >= WE) bal[t.first] = 1;
        else bal[t.first] = -1;
        len[t.first] = 1;
        dfs_calc(t.first, cent, cur);

        vector < int > cur_path;
        int maxi_len = 0;
        for (auto it : cur) {
            if ((l <= len[it] && len[it] <= r) && bal[it] >= 0) {
                if (recover) {
                    U = cent;
                    V = it;
                }
                return true;
            }
            maxi_len = max(maxi_len, len[it]);
        }
        cur_path.resize(maxi_len + 1, -INF);

        for (auto it : cur) {
            cur_path[len[it]] = max(cur_path[len[it]], bal[it]);
        }
        paths.push_back(cur_path);
        mx_len = max(mx_len, maxi_len);
    }

    if (2 * mx_len >= l) {
        vector<pair<int, int> > two_maxes(mx_len + 1, make_pair(-1, -1));
        // first - max, second - max
        for (int i = 0; i < paths.size(); i++) {
            for (int j = 0; j < paths[i].size(); j++) {
                int cur_bal = paths[i][j];
                if (two_maxes[j].first == -1 || paths[two_maxes[j].first][j] < cur_bal) {
                    two_maxes[j].second = two_maxes[j].first;
                    two_maxes[j].first = i;
                } else if (two_maxes[j].second == -1 || paths[two_maxes[j].second][j] < cur_bal) {
                    two_maxes[j].second = i;
                }
            }
        }
        for (int i = 1; i < two_maxes.size(); i++) {
            assert(two_maxes[i].first != -1);
            cur_max[i] = paths[two_maxes[i].first][i];
            cur_ind[i] = two_maxes[i].first;
        }
        // >= 1
        build(1, 1, mx_len);
        for (int i = 0; i < paths.size(); i++) {
            for (int j = 1; j < paths[i].size(); j++) {
                if (two_maxes[j].first == i) {
                    if (two_maxes[j].second == -1) {
                        cur_ind[j] = -1;
                        upd(1, 1, mx_len, j, -INF);
                    } else {
                        cur_ind[j] = two_maxes[j].second;
                        upd(1, 1, mx_len, j, paths[two_maxes[j].second][j]);
                    }
                }
            }
            for (int j = 1; j < paths[i].size(); j++) {
                int l1 = max(1, l - j);
                int r1 = min(mx_len, r - j);
                if (l1 > r1) continue;
                int max_bal = get(1, 1, mx_len, l1, r1);
                if (max_bal + paths[i][j] >= 0) {
                    if (!recover) return true;
                    U = fnd(my_roots[i], cent, j, paths[i][j]);
                    assert(U != -1);
                    for (int to = l1; to <= r1; to++) {
                        if (cur_ind[to] == -1) {
                            continue;
                        }
                        if (paths[cur_ind[to]][to] == max_bal) {
                            V = fnd(my_roots[cur_ind[to]], cent, to, paths[cur_ind[to]][to]);
                            return true;
                        }
                    }
                    assert(false);
                }
            }
            for (int j = 1; j < paths[i].size(); j++) {
                if (two_maxes[j].first == i) {
                    cur_ind[j] = i;
                    upd(1, 1, mx_len, j, paths[i][j]);
                }
            }
        }
    }
    used[cent] = true;
    random_shuffle(my_roots.begin(), my_roots.end());
    for (int to : my_roots) {
        if (sz[to] == 1) continue;
        if (solve(to, recover)) return true;
    }
    return false;
}

bool ok(int we, bool recover) {
    memset(used, 0, sizeof used);
    WE = we;
    return solve(1, recover);
}

int ti = 1;
int la[maxN];
int bck[maxN];
vector < pair < pair < int, int >, int > > ed;
void go_dfs(int v, int par) {
    la[v] = ti;
    bck[la[v]] = v;
    ti++;
    for (auto t : g[v]) {
        if (t.first == par) continue;
        go_dfs(t.first, v);
    }
}
void init() {
    go_dfs(1, -1);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (auto ttt : ed) {
        g[la[ttt.first.first]].emplace_back(la[ttt.first.second], ttt.second);
        g[la[ttt.first.second]].emplace_back(la[ttt.first.first], ttt.second);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> l >> r;
    vector < int > we;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        we.push_back(c);
        ed.emplace_back(make_pair(make_pair(a, b), c));
    }
    init();
    sort(we.begin(), we.end());
    we.push_back((int)1e9 + 100);
    int l = 0;
    int r = we.size() - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ok(we[mid], false)) l = mid;
        else r = mid;
    }
    ok(we[l], true);
    cout << bck[U] << " " << bck[V];
    return 0;
}