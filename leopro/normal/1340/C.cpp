#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename F, typename S>inline bool whitespace(const pair<F, S> &) { return false; }
    template<typename F, typename S>ostream &operator<<(ostream &os, const pair<F, S> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename F, typename S>istream &operator>>(istream &is, pair<F, S> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0) { vector<T> res(v.size()+1-from); res[0] = 0; for (int i = from; i < v.size(); ++i) res[i+1-from] = res[i-from] + v[i]; return res; }
    template<typename F, typename S>F min(F a, S b){return a < (F)b ? a : b; }
    template<typename F, typename S>F max(F a, S b){return a < (F)b ? b : a; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    template<typename T>void answer(T ans){out << ans << "\n"; throw exit_exception();}
    struct autoint{int x; autoint(){in >> x;} operator int(){return x;} autoint(autoint &i){x = i.x;} int operator=(int i){ return x = i; }
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };
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

//struct graph {
//    struct vertex {
//        struct edge {
//            vertex *p;
//            int w;
//
//            edge(vertex *p, int w) : p(p), w(w) {}
//        };
//
//        int n;
//        int time = 1e9;
//        vector<edge> edges;
//        vector<bool> used;
//
//        vertex(int i, int g) : n(i), used(g) {}
//    };
//
//    vector<vertex *> vertices;
//
//    graph(int n, int g) : vertices(n) { for (int i = 0; i < n; ++i) vertices[i] = new vertex(i, g); }
//};

//struct pos {
//    int cur;
//    int v;
//
//    pos(int c, int v) : cur(c), v(v) {}
//
//    bool operator<(const pos &pos) const {
//        if (cur != pos.cur) return cur < pos.cur;
//        return v < pos.v;
//    }
//};

typedef pair<int, int> pos;
#define cur first
#define v second

vector<vector<bool>> used(10'000, vector<bool>(1000));

void solve() {
    autoint n, m;
    vector<int> d(m);
    cin >> d;
    stable_sort(d.begin(), d.end());
    autoint g, r;

    vector<int> time(m, 1e9);

//    graph G(m, g + 1);
//    for (int j = 0; j + 1 < m; ++j) {
//        G.vertices[j]->edges.emplace_back(G.vertices[j + 1], d[j + 1] - d[j]);
//        G.vertices[j + 1]->edges.emplace_back(G.vertices[j], d[j + 1] - d[j]);
//    }

    vector<vector<int>> set(1e7+1);
    int i = 0;
    set[0].emplace_back(0);
    while (!set.empty()) {
        while (i < set.size() && set[i].empty())++i;
        if (i == set.size()) break;
        int p = set[i].back();
        set[i].erase(set[i].end() - 1);
        
        int cur = i;

        if (p < m - 1) {
            int w = (d[p + 1] - d[p]);
            if ((cur % g) + w > g || used[p + 1][(cur % g) + w]) goto NEXT;
            used[p + 1][(cur % g) + w] = true;
            time[p + 1] = min(time[p + 1], cur + w);
            set[cur + w].emplace_back(p + 1);
        }NEXT:;
        if (p > 0) {
            int w = d[p] - d[p - 1];
            if ((cur % g) + w > g || used[p - 1][(cur % g) + w]) continue;
            used[p - 1][(cur % g) + w] = true;
            time[p - 1] = min(time[p - 1], cur + w);
            set[cur + w].emplace_back(p - 1);
        }


    }
    cout << (time.back() == (int) 1e9 ? -1 : time.back() + (time.back() - 1) / g * r);
}