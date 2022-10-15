#include <bits/stdc++.h>

//@formatter:off
namespace {
#define int long long
    using namespace std;
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << '\n'; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << '\n'; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer_ref(T &ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    const char *to_string(const vector<int> &v){ostringstream ss; for (const auto &item : v) ss << item << (whitespace(item) ? " " : ""); return ss.str().c_str();}
    const char *to_string(const vector<vector<int>> &v){string *s = new string; for (const auto & item : v) *s += string(to_string(item)) + "   "; return s->c_str();}
    const char *to_string(const pair<int, int> &p){ostringstream ss; ss << p.first << ", " << p.second; return ss.str().c_str();}
//    const char *to_string(const pair<int, vector<int>> &p){ostringstream ss; ss << p.first << ", " << p.second; return ss.str().c_str();}
    const char *to_string(const map<int, int> &m){ostringstream ss; for (const auto & item : m) ss << "(" << item << ") "; return ss.str().c_str();}
//    const char *to_string(const map<int, vector<int>> &m){ostringstream ss; for (const auto & item : m) ss << "(" << item << ") "; return ss.str().c_str();}
    const char *to_string(const set<int> &s){ostringstream ss; for (const auto & item : s) ss << "(" << item << ") "; return ss.str().c_str();}
}
//@formatter:on

void solve();


namespace Graph {
    struct Vertex {
        int color = 0;
        int time_in, time_out;
        int comp = -1;
        int n;
        vector<Vertex *> children;

        friend ostream &operator<<(ostream &os, const Vertex &vertex) {
            os << vertex.n << " " << vertex.comp << "\n";
            return os;
        }
    };

    namespace TopSort {
/*
 * v   u
 * time_uot[u] > time_out[v],   .
 */
        int time = 0;

        vector<Vertex> ans;
        vector<Vertex> &G = ans;

        void dfs(Vertex *v) {
            v->color = 1;
            v->time_in = time;
            for (auto w : v->children) {
                ++time;
                if (w->color == 2) continue;
                //   w->color != 1
                // w->color == 0
                if (w->color == 0) dfs(w);
                ++time;
            }
            v->time_out = time;
            ans.push_back(*v);
            v->color = 2;
        }

        void topological_sort(vector<Vertex> &graph) {
            for (Vertex &v : graph) {
                if (v.color == 0) dfs(&v);
            }
//            stable_sort(graph.begin(), graph.end(),
//                        [](Vertex a, Vertex b) { return a.time_out > b.time_out; });
            reverse(ans.begin(), ans.end());

            //  ans  graph  
        }
    }

    namespace Condensation {
        /* u    v  ,         .
         *    -        
         *     -  .  .
         *
         */
        void set_comp(Vertex *u, int c) {
            u->comp = c;
            for (auto w : u->children) {
                if (w->comp == -1) set_comp(w, c);
            }
        }

        vector<Vertex> graph_r(vector<Vertex> &graph) {
            vector<Vertex> g_r = *new vector<Vertex>(graph.size());
            for (int i = 0; i < g_r.size(); ++i) g_r[i].n = graph[i].n;
            for (int i = 0; i < graph.size(); ++i) {
                for (auto w : graph[i].children) {
                    g_r[w->n].children.push_back(&g_r[i]);
                }
            }
            return g_r;
        }

        void condense(vector<Vertex> &graph) {
            TopSort::topological_sort(graph);
            int c = 0;
            vector<Vertex> g_r = graph_r(graph);
            for (auto x : TopSort::ans) {
                auto &v = g_r[x.n];
                if (v.comp == -1) set_comp(&v, c++);
                cerr << v.n << "\n";
            }
            for (int i = 0; i < g_r.size(); ++i) {
                graph[i].comp = g_r[i].comp;
            }
            cerr << "?";
//            delete &g_r;
            cerr << "!!!\n" << graph;
        }
    }
}


signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(); } catch (ExitException) {}} while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    cin >> cnt;
    vector<int> segments(1, 1);
    segments.reserve(n);
    for (int i = 1; i < n; ++i) {
        if (cnt[i] == cnt[i - 1]) segments.back()++; else segments.push_back(1);
    }
    int g = segments[0];
    int s = 0;
    int i = 1;
    for (; i < segments.size(); ++i) {
        s += segments[i];
        if (s > g) break;
    }
    int b = 0;
    ++i;
    for (; i < segments.size(); ++i) {
        b += segments[i];
        if (b > g) break;
    }
    if (b <= g) answer("0 0 0");
    if (s + b + g > n / 2) answer("0 0 0");
    ++i;
    int sum = s + b + g;
    for (; i < segments.size(); ++i) {
        sum += segments[i];
        if (sum > n / 2) break;
        b += segments[i];
    }
    cout << g << " " <<s <<" " << b << "\n";
}