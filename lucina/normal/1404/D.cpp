#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10;

namespace atcoder {
// Reference:
// B. Aspvall, M. Plass, and R. Tarjan,
// A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
// Formulas
namespace internal {
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
}


struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::scc_graph scc;
};
}
using two_sat = atcoder::two_sat;

int n;
int a[nax];
int last[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;

    if (n % 4 == 0) {
        cout << "First" << endl;
        for (int i = 1 ; i <= 2 * n ; ++ i) {
            cout << (i % n) + 1 << ' ';
        }
        cout << endl;
        int result;
        cin >> result;
        assert(result == 0);
        return 0;
    } else if (n % 2 == 0) {
        /// n = 2 * k
        cout << "First" << endl;
        //// 1 2 3 4 5 6 7 8 9 10 11 12
        for (int i = 1, cur = 1 ; i <= 2 * n ; i += 4) {
            cout << cur << ' ' << cur + 1 << ' ' << cur << ' ' << cur + 1 << ' ';
            cur += 2;
        }
        cout << endl;
        int result;
        cin >> result;
        assert(result == 0);
        return 0;
    }

    cout << "Second" << endl;
    for (int i = 1 ; i <= 2 * n ; ++ i) {
        cin >> a[i];
    }
    two_sat sat(2 * n);

    auto add_clause = [&](int i, int j) {
        ///
        -- i, -- j; /// 0-indexed sigh
      //  cout << i << ' ' << j << '\n';
        /// (i | j) & ( ~i | ~j) /// right?
        sat.add_clause(i, true, j, true);
        sat.add_clause(i, false, j, false);
    };


    for (int i = 1 ; i <= n ; ++ i) {
        add_clause(i, n + i);
    }

    for (int i = 1 ; i <= 2 * n ; ++ i) {
        if (last[a[i]]) {
            add_clause(i, last[a[i]]);
        }
        last[a[i]] = i;
    }


    assert(sat.satisfiable());

    vector <bool> answer = sat.answer();

    answer.insert(answer.begin(), false);
    int64_t sum = 0;
    for (int i = 1 ; i <= 2 * n ; ++ i) {
        if (answer[i]) {
            sum += i;
        }
    }

    bool invert = false;
    if (sum % (2 * n)) invert = true;

    for (int i = 1 ; i <= 2 * n ; ++ i) {
        if (answer[i] ^ invert)
            cout << i << ' ';
    }

    cout << endl;


    /**
        for odd case
        notice that if you can choose sum modulo(n) equal to zero
        its complement also have sum modulo (n) equal to zero as well.
        But their parities are different, so we can ignore mod(2n) and solve mod(n) instead!
        for every number
        it means that we have 0, 0, 1, 1, 2, 2, 3, 3, ..., n - 1. n - 1
        From what we've given, we could see it as some kind of clauses.
        (x, n + x) must choose exactly one.
        (x, y) must choose exactly one.
        So we can easily solve it as two sat.
        Q: Why can  we always choose (0, 1, 2, ....., n - 1)?
        A:
        p0 p1 p2 p3 ......... p9
        0   1  2  3 4 5 6 7 8 9
        assume that at any point of time we can represent it this way.
        The operation that first can do and meaningful is just swap two numbers in some columns
        But since it's permutation, it's just become some cycle.
        By swapping any number involved in cycle, the property remain.
        The rest is to solve 2sat.
    */
}
/*
    Good Luck
        -Lucina
*/