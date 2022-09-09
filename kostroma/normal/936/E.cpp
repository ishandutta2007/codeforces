//MIPT Cryptozoology 17.2
#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
    //assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

void precalc() {
}

template<typename T>
inline T nxt() {
    T cur;
    cin >> cur;
    return cur;
}

//#define int li
//const int mod = 1000000007;

struct Vertex {
    int x, l, r;
    int start_index;
    tuple<int, int, int> key() const {
        return make_tuple(x, l, r);
    }
    bool operator < (const Vertex& ot) const {
        return key() < ot.key();
    }
    int get_index(int y) {
        return start_index + y - l;
    }
};

vector<Vertex> vertices;
const int C = 300010;
//unordered_map<int, int> vertex_index[C];

struct VertexIndexer {
    vector<pair<int, int>> values;
    void append(Vertex& cur, int id) {
        for (int y = cur.l; y <= cur.r; ++y) {
            values.emplace_back(y, id);
        }
    }
    int get_pos(int y) {
        if (values.empty()) {
            return -1;
        }
        int L = 0, R = values.size();
        while (L + 1 < R) {
            int M = (L + R) / 2;
            if (values[M].first > y) {
                R = M;
            } else {
                L = M;
            }
        }
        if (values[L].first != y) {
            return -1;
        }
        return L;
    }
};

VertexIndexer vertex_index[C];

vector<char> used;
int n = 0;
vector<int> centroid_parent;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Point {
    int x, y;
    pair<int, int> key() const {
        return make_pair(x, y);
    }
    bool operator == (const Point& ot) const {
        return key() == ot.key();
    }
    bool operator < (const Point& ot) const {
        return key() < ot.key();
    }
    Point move(int dir) const {
        return {x + dx[dir], y + dy[dir]};
    }
};

struct PointHash {
    int operator() (const Point& pt) const {
        return (pt.x * 5342532) + pt.y;
    }
};

struct DistInfo {
    int dist;
    int best_start;
};

const int INF = (int)1e9;

struct Node {
    int cur_min[2];
    int& operator [] (int c) {
        return cur_min[c];
    }
};

Node inf_node() {
    Node res;
    res.cur_min[0] = res.cur_min[1] = INF;
    return res;
}

Node get_from_val(int val, int pos) {
    Node res;
    res.cur_min[0] = val + pos;
    res.cur_min[1] = val - pos;
    return res;
}

Node merge(const Node& q, const Node& w) {
    Node res;
    for (int i = 0; i < 2; ++i) {
        res.cur_min[i] = min(q.cur_min[i], w.cur_min[i]);
    }
    return res;
}

struct SegTree {
    int shift;
    vector<Node> tree;
    SegTree(int n) {
        shift = 1;
        while (shift < n) {
            shift *= 2;
        }
        tree.assign(2 * shift, inf_node());
    }
    void update(int pos, int val) {
        //tree[v + shift] = merge(tree[v + shift], get_from_val(val, v));
        int v = pos + shift;
        while (v) {
            bool f = false;
            if (tree[v][0] > val + pos) {
                tree[v][0] = val + pos;
                f = true;
            }
            if (tree[v][1] > val - pos) {
                tree[v][1] = val - pos;
                f = true;
            }
            if (!f) {
                break;
            }
            v /= 2;
        }
    }
    Node get_res(int l, int r) {
        Node res = inf_node();
        l += shift;
        r += shift;
        while (l < r) {
            if (l & 1) {
                res = merge(res, tree[l]);
                ++l;
                continue;
            }
            if (r & 1) {
                --r;
                res = merge(res, tree[r]);
                continue;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

int get_vertex_number(Point cur) {
    int cur_pos = vertex_index[cur.x].get_pos(cur.y);
    if (cur_pos == -1) {
        return -1;
    }
    return vertex_index[cur.x].values[cur_pos].second;
}

const int L = 19;

const int MAGIC = 50000;

int num_bucket[C];

DistInfo all_dist[L][C];

struct Vicinity {
    Vertex center;
    SegTree tree;
    int depth;
    Vicinity() : tree(0) {}
    int size() const {
        return center.r - center.l + 1;
    }
    DistInfo get_dist(int cur_id) {
        return all_dist[depth][cur_id];
    }
    Vicinity(Vertex center, int center_id, int depth) : center(center), tree(center.r - center.l + 1), depth(depth) {
        queue<pair<Point, DistInfo>> q;
        auto& dist = all_dist[depth];
        for (int y = center.l; y <= center.r; ++y) {
            int cur_id = center.get_index(y);
            q.push({{center.x, y}, {0, y}});
            dist[cur_id] = {0, y};
        }
        while (!q.empty()) {
            auto pt = q.front().first;
            auto cur_res = q.front().second;
            ++cur_res.dist;
            q.pop();
            for (int dir = 0; dir < 4; ++dir) {
                Point cur = pt.move(dir);
                int v_id = get_vertex_number(cur);
                if (v_id == -1 || used[v_id]) {
                    continue;
                }
                int cur_pos = vertices[v_id].get_index(cur.y);
                if (dist[cur_pos].dist != -1) {
                    continue;
                }
                centroid_parent[v_id] = center_id;
                dist[cur_pos] = cur_res;
                q.push({cur, cur_res});
            }
        }
    }
};

vector<Vicinity> data;
vector<vector<int>> g;
vector<int> cnt, max_cnt;
vector<int> comp;

void dfs1(int v, int p) {
    cnt[v] = 1;
    max_cnt[v] = 0;
    comp.push_back(v);
    for (int to : g[v]) {
        if (to == p || used[to]) continue;
        dfs1(to, v);
        max_cnt[v] = max(max_cnt[v], cnt[to]);
        cnt[v] += cnt[to];
    }
}

void kill_center(int v, int depth) {
    if (used[v]) {
        return;
    }
    comp.clear();
    dfs1(v, v);
    int center = -1;
    for (int x : comp) {
        if (max_cnt[x] <= cnt[v] / 2 && cnt[v] - cnt[x] <= cnt[v] / 2) {
            center = x;
            break;
        }
    }
    assert(center != -1);
    v = center;
    data[v] = Vicinity(vertices[v], v, depth);
    used[v] = true;
    for (int to : g[v]) {
        kill_center(to, depth + 1);
    }
}

void solve(__attribute__((unused)) bool read) {
    int N;
    //read = false;
    if (read) {
        cin >> N;
    } else {
        N = 300000;
    }
    vector<int> xs;
    vector<vector<int>> a(C);
    for (int i = 0; i < N; ++i) {
        int x, y;
        if (read) {
            cin >> x >> y;
        } else {
            x = i + 1;
            y = C / 2;
        }
        xs.push_back(x);
        a[x].push_back(y);
    }
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    for (int i = 0; i < MAGIC; ++i) {
        int l = i * (li)xs.size() / MAGIC, r = (i + 1) * (li)xs.size() / MAGIC;
        r = min(r, (int)xs.size());
        for (int j = xs[l]; j < xs[r]; ++j) {
            num_bucket[j] = i;
        }
    }

    int pref = 0;
    for (int i = 0; i < C; ++i) {
        sort(all(a[i]));
        for (int j = 0; j < a[i].size(); ) {
            int r = j + 1;
            while (r < a[i].size() && a[i][r] == a[i][r - 1] + 1) {
                ++r;
            }
            Vertex cur = {i, a[i][j], a[i][r - 1], pref};
            Vertex cand = {i - 1, cur.l, cur.r, pref};
            auto it = lower_bound(all(vertices), cand);
            if (it != vertices.begin() && prev(it)->x == cand.x && prev(it)->r >= cur.l) {
                --it;
            }
            g.push_back(vector<int>());
            while (it != vertices.end() && it->x == cand.x && max(it->l, cur.l) <= min(it->r, cur.r)) {
                g[it - vertices.begin()].push_back(n);
                ++it;
            }
            for (int y = cur.l; y <= cur.r; ++y) {
                vertex_index[cur.x].values.push_back({y, n});
            }
            vertices.push_back(cur);
            pref += cur.r - cur.l + 1;
            ++n;
            j = r;
        }
    }

    for (int d = 0; d < L; ++d) {
        for (int i = 0; i < N; ++i) {
            all_dist[d][i] = {-1, -1};
        }
    }

    int n_edges = 0;
    for (int i = 0; i < n; ++i) {
        for (int to : g[i]) {
            if (to > i) {
                ++n_edges;
                g[to].push_back(i);
            }
        }
    }
    assert(n_edges == n - 1);
    used.assign(n, false);
    centroid_parent.assign(n, -1);
    data.resize(n);
    cnt.assign(n, 0);
    max_cnt.assign(n, 0);
    kill_center(0, 0);

    int Q;
    if (read) {
        cin >> Q;
    } else {
        Q = 300000;
    }
    while (Q--) {
        int t, x, y;
        if (read) {
            cin >> t >> x >> y;
        } else {
            t = rand() % 2 + 1;
            x = rand() % N + 1;
            y = C / 2;
        }
        int res = INF;
        int init = get_vertex_number({x, y});
        int cur_pos = vertices[init].get_index(y);
        for (int v = init; v != -1; v = centroid_parent[v]) {
            auto cur_dist = data[v].get_dist(cur_pos);
            int in_id = cur_dist.best_start - data[v].center.l;
            auto& tree = data[v].tree;
            if (t == 1) {
                tree.update(in_id, cur_dist.dist);
            } else {
                res = min(res, tree.get_res(in_id, data[v].size())[0] - in_id + cur_dist.dist);
                res = min(res, tree.get_res(0, in_id)[1] + in_id + cur_dist.dist);
            }
        }
        if (t == 2) {
            if (res >= INF / 2) res = -1;
            cout << res << "\n";
        }
    }

}