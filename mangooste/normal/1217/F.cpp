#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

struct disjoin_set_union {
    vector<int> parent;
    vector<int> rank;
    vector<pair<int, int>> updates;

    disjoin_set_union(int n) : parent(n), rank(n, 1) {
        iota(all(parent), 0);
    }

    void set_default() {
        iota(all(parent), 0);
        fill(all(rank), 1);
        updates.clear();
    }

    int root(int v) {
        return parent[v] == v ? v : root(parent[v]);
    }

    void unite(int v, int u, bool update) {
        v = root(v);
        u = root(u);
        if (v == u)
            return;

        if (rank[v] < rank[u])
            swap(v, u);

        parent[u] = v;
        rank[v] += rank[u];
        if (update)
            updates.emplace_back(v, u);
    }

    void roll_back() {
        while (!updates.empty()) {
            const auto [v, u] = updates.back();
            updates.pop_back();
            rank[v] -= rank[u];
            parent[u] = u;
        }
    }
};

struct query {
    int type, v, u;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<query> queries(q);
    for (auto &[type, v, u] : queries) {
        cin >> type >> v >> u;
        v--, u--;
    }

    int current_id = 0;
    map<pair<int, int>, int> edge_id;
    vector<array<int, 2>> id(q);

    for (int i = 0; i < q; i++)
        if (queries[i].type == 1)
            for (int last : {0, 1}) {
                const pair<int, int> edge = minmax((queries[i].v + last) % n, (queries[i].u + last) % n);
                if (edge_id.count(edge) == 0)
                    edge_id[edge] = current_id++;

                id[i][last] = edge_id[edge];
            }

    const int B = sqrt(q);
    disjoin_set_union dsu(n);
    vector<pair<int, int>> last_seen(current_id, {-1, -1});
    vector<char> bad(current_id);

    vector<pair<int, int>> bad_edges;
    bad_edges.reserve(2 * B);

    int last_answer = 0;
    for (int i = 0; i < q;) {
        int from = i, to = min(q, i + B);

        fill(all(bad), 0);
        for (int j = from; j < to; j++)
            if (queries[j].type == 1)
                bad[id[j][0]] = bad[id[j][1]] = 1;

        dsu.set_default();
        bad_edges.clear();

        for (int j = 0; j < from; j++)
            if (queries[j].type == 1)
                for (int last : {0, 1})
                    if (last_seen[id[j][last]] == pair<int, int>{j, last}) {
                        if (!bad[id[j][last]])
                            dsu.unite((queries[j].v + last) % n, (queries[j].u + last) % n, false);
                        else
                            bad_edges.emplace_back(minmax((queries[j].v + last) % n, (queries[j].u + last) % n));
                    }

        for (int j = from; j < to; j++)
            if (queries[j].type == 1) {
                if (last_seen[id[j][last_answer]].first == -1) {
                    last_seen[id[j][last_answer]] = {j, last_answer};
                    bad_edges.emplace_back(minmax((queries[j].v + last_answer) % n, (queries[j].u + last_answer) % n));
                } else {
                    last_seen[id[j][last_answer]] = {-1, -1};
                    bad_edges.erase(find(all(bad_edges), pair<int, int>(minmax((queries[j].v + last_answer) % n, (queries[j].u + last_answer) % n))));
                }
            } else {
                for (const auto &[u, v] : bad_edges)
                    dsu.unite(v, u, true);

                last_answer = dsu.root((queries[j].v + last_answer) % n) == dsu.root((queries[j].u + last_answer) % n);
                cout << last_answer;
                dsu.roll_back();
            }

        i = to;
    }
    cout << '\n';
}