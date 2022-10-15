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
    class exit_exception : exception {};
    void answer(){}
    template<typename First, typename... Args>void answer(First&& val, Args&&... ans){cout << val << "\n"; answer(ans...); throw exit_exception();}
    struct autoint{ int x; autoint(int i):x(i){} autoint():x(0){cin >> x;} operator int(){return x;}                                               //NOLINT
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };   //NOLINT
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0) { vector<T> res(v.size()+1-from); res[0] = 0; for (int i = from; i < v.size(); ++i) res[i+1-from] = res[i-from] + v[i]; return res; }
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

struct vertex {
    map<vertex *, int> links;
    int value, n;
    bool visited;

    vertex(int v, int n) : value(v), n(n), visited(false) {}

    void link(vertex *u) {
        links[u]++;
        u->links[this]++;
    }
};



void visit(vertex *v) {
    if (v->visited) return;
    v->visited = true;
    for (auto p : v->links) visit(p.first);
}

bool connected(vector<vertex *> &graph) {
    visit(graph.front());
    return find_if(graph.begin(), graph.end(), [](vertex *v) { return !v->visited; }) == graph.end();
}

void divide_into_cycles(vector<vertex *> &graph, vector<int> &cycle, int cur) {
    while (!graph[cur]->links.empty()) {

        vertex *next = graph[cur]->links.begin()->first;
        if (--next->links[graph[cur]] == 0) next->links.erase(graph[cur]);
        if (--graph[cur]->links[next] == 0) graph[cur]->links.erase(next);

        divide_into_cycles(graph, cycle, next->n);
    }
    cycle.push_back(graph[cur]->value);
}

void solve() {
    autoint n;
    vector<int> b(n - 1), c(n - 1);
    cin >> b >> c;
    map<int, int> count;
    for (int i = 0; i < n - 1; ++i) {
        count[b[i]]++;
        count[c[i]]++;
        if (b[i] > c[i]) answer(-1);
    }
    vector<int> odds;
    for (auto pair: count) {
        if (pair.second % 2 == 1) odds.push_back(pair.first);
    }
    if (odds.size() != 2 && odds.size() != 0) answer(-1);

    vector<vertex *> graph(count.size());

    map<int, int> y;
    int d = -1;
    for (auto p : count) {
        y[p.first] = ++d;
        graph[d] = new vertex(p.first, d);
    }
    for (int i = 0; i < n - 1; ++i) {
        graph[y[b[i]]]->link(graph[y[c[i]]]);
    }

    int begin = (odds.empty() ? 0 : odds.front());
if (!connected(graph)) answer(-1);
    vector<int> cycle;
    divide_into_cycles(graph, cycle, y[begin]);
    cout << cycle;
}