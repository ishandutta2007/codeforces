#include <bits/stdc++.h>
 
//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()+1); res[0] = 0; for (int i = 0; i < v.size(); ++i) res[i+1] = res[i] + v[i]; return res; }
    class exit_exception : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw exit_exception();}
}
//@formatter:on
 
void solve();
 
signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}
 
namespace graphs {
    struct graph {
        struct vertex {
            struct edge {
                vertex *p;
                int weight;
 
                edge(vertex *p, int w) : p(p), weight(w) {}
 
                bool operator<(const edge &e) const { return *p < *e.p; }
            };
 
            vector<edge> edges;
            int n, component, up, depth, degree;
            int x, y;
            bool visited = false;
            bool artpoint;
 
            bool operator<(const vertex &v) const { return n < v.n; }
 
            bool operator==(const vertex &v) const { return n == v.n; }
 
            explicit vertex(int n = 0) : component(-1), n(n), depth(1e15), up(-1), degree(0) {}
 
            explicit vertex(int n, int x, int y) : component(-1), n(n), depth(1e15), up(-1), degree(0), x(x), y(y) {}
 
            void dfs() {
                for (edge &e : edges) {
                    e.p->dfs();
                }
            }
 
            int dist(int t){
                if (t < 0) return 0;
                if (edges.empty()) return 1;
                return 1 + edges.front().p->dist(t - edges.front().weight);
            }
 
            void relax() {
                for (edge e : edges) {
                    if (e.p->depth > depth + e.weight) e.p->depth = depth + e.weight;
                }
            }
 
            void set_comp(int c) {
                if (component != -1) return; else component = c;
                for (edge &e : edges) e.p->set_comp(c);
            }
 
            void bfs() {
                up = depth = 0;
                queue<vertex *> queue;
                queue.push(this);
                while (!queue.empty()) {
                    vertex *v = queue.front();
                    queue.pop();
                    for (edge e : v->edges) {
                        if (e.p->depth != -1) continue;
                        queue.push(e.p);
                        e.p->up = e.p->depth = v->depth + 1;
                    }
                }
            }
 
            void top_sort(vector<vertex *> &top_sorted) {
                visited = true;
                for (edge e : edges) {
                    if (!e.p->visited) e.p->top_sort(top_sorted);
                }
                top_sorted.push_back(this);
            }
 
            bool find(vertex *f, vector<vertex *> way) {
                if (*this == *f) return true;
                visited = true;
                for (edge e : edges) {
                    if (!e.p->visited) {
                        if (e.p->find(f, way)) {
                            way.push_back(this);
                            return true;
                        }
                    }
                }
                return false;
            }
 
            void find_artpoints(vertex *parent) {
                visited = true;
                int count = 0;
                for (edge e : edges) {
                    if (!e.p->visited) {
                        e.p->up = e.p->depth = depth + 1;
                        e.p->find_artpoints(this);
                        count++;
                        up = min(up, e.p->up);
                        degree = max(degree, e.p->up);
                    }
                    if (e.p != parent)
                        up = min(up, e.p->depth);
                }
                if ((parent != nullptr && degree >= depth && count > 0) || (parent == nullptr && count > 1))
                    this->artpoint = true;
            }
 
            friend ostream &operator<<(ostream &os, vertex *v) {
                os << v->n + 1;
                return os;
            }
        };
 
        vector<vertex *> vertices;
        int vertex_count, edge_count;
        bool directed, weight;
 
        explicit graph(int n, int m, bool directed = false, bool weight = false)
                : vertices(n), vertex_count(n), edge_count(m), directed(directed), weight(weight) {
            for (int i = 0; i < n; ++i) {
                vertices[i] = new vertex(i);
            }
        }
 
        inline vertex *operator[](int idx) { return vertices[idx]; }
 
        void link(int i, int j, int w = 1) {
            w = abs(vertices[i]->x - vertices[j]->x) + abs(vertices[i]->y - vertices[j]->y);
            vertices[i]->edges.emplace_back(vertices[j], w);
            if (!directed) vertices[j]->edges.emplace_back(vertices[i], w);
        }
 
        void create(int R, int x) {
            for (vertex *v : vertices) v->edges.clear();
            for (int i = 0; i < vertex_count; ++i) {
                for (int j = i + 1; j < vertex_count; ++j) {
                    if (i == x || j == x) continue;
                    if (((vertices[i]->x - vertices[j]->x) * (vertices[i]->x - vertices[j]->x) +
                         (vertices[i]->y - vertices[j]->y) * (vertices[i]->y - vertices[j]->y)) <= R)
                        link(i, j);
                }
            }
        }
 
        friend istream &operator>>(istream &is, graph &G) {
            for (int i = 0; i < G.edge_count; ++i) {
                int u = 0, v = 0, w = 1;
                cin >> u >> v;
                if (G.weight) cin >> w;
                G.link(u - 1, v - 1, w);
            }
            return is;
        }
 
        vector<vertex *> find_artpoints() {
            for (vertex *v : vertices) v->visited = false;
            for (vertex *v : vertices) {
                if (!v->visited) {
                    v->up = v->depth = 0;
                    v->find_artpoints(nullptr);
                }
            }
            vector<vertex *> artpoints = *new vector<vertex *>;
            for (vertex *v : vertices) {
                if (v->artpoint) artpoints.push_back(v);
            }
            return artpoints;
        }
 
        vector<vertex *> top_sort() {
            for (vertex *v : vertices) v->visited = false;
            vector<vertex *> top_sorted = *new vector<vertex *>;
            for (vertex *v : vertices) {
                if (!v->visited) {
                    v->top_sort(top_sorted);
                }
            }
            reverse(top_sorted.begin(), top_sorted.end());
            return top_sorted;
        }
 
        vector<vertex *> way(int s, int t) {
            for (vertex *v : vertices) v->visited = false;
            vector<vertex *> ans;
            vertices[s]->find(vertices[t], ans);
            return ans;
        }
 
        int dist(int i,int t){
            return vertices[i]->dist(t);
        }
 
        int comp_count() {
            for (vertex *v : vertices) v->component = -1;
            int c = 0;
            for (vertex *v : vertices) {
                if (v->component == -1) v->set_comp(c++);
            }
            return c;
        }
    };
 
    struct tree : graph {
        vertex *root;
 
        explicit tree(int n, int root = 0, bool weight = false)
                : graph(n, n - 1, true, weight), root(vertices[0]) {}
 
        friend istream &operator>>(istream &is, tree &T) {
            for (int i = 0; i < T.edge_count; ++i) {
                int parent = 0, weight = 0;
                cin >> parent;
                if (weight) cin >> weight;
                T[parent]->edges.emplace_back(T[i + 1], weight);
            }
            return is;
        }
    };
 
}
using namespace graphs;
 
void solve() {
    int x0, y0, a_x, a_y, b_x, b_y, x_s, y_s, t;
    cin >> x0 >> y0 >> a_x >> a_y >> b_x >> b_y >> x_s >> y_s >> t;
    pair<int, int> point = {x0, y0};
    graph G(1, 0, true, true);
    G.vertices[0] = new graph::vertex(0, x_s, y_s);
    for (int i = 0; i < 200; ++i) {
        G.vertices.push_back(new graph::vertex(i + 1, point.first, point.second));
        if (point.first > 5e18 / a_x || point.second > 5e18 / a_y) break;
        point.first = point.first * a_x + b_x;
        point.second = point.second * a_y + b_y;
    }
    for (int i = 1; i < G.vertices.size(); ++i)G.link(0, i);
    for (int i = 1; i + 1 < G.vertices.size(); ++i) G.link(i, i + 1);
    int ans = 0;
    for (int i = 1; i < G.vertices.size(); ++i){
        int d =  G.dist(i,t - G.vertices[0]->edges[i - 1].weight);
        ans = max(ans,d);
    }
    for (int i = 1; i < G.vertices.size(); ++i) G.vertices[i]->edges.clear();
    for (int i = 2; i < G.vertices.size(); ++i) G.link(i,i - 1);
    for (int i = 1; i < G.vertices.size(); ++i){
        int d =  G.dist(i,t - G.vertices[0]->edges[i - 1].weight);
        ans = max(ans,d);
    }
    answer(ans);
}