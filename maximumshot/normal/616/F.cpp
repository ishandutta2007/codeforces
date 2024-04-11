#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

#define FAST_ALLOCATOR_MEMORY 4e8
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
inline void * operator new ( size_t n ) {
    char *res = allocator_memory + allocator_pos;
    allocator_pos += n;
    assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
    return (void *)res;
}
inline void operator delete ( void * ) noexcept { }
//inline void * operator new [] ( size_t ) { assert(0); }
//inline void operator delete [] ( void * ) { assert(0); }
#endif


const int A = 27; // Alphabet size
struct SuffixTree {
    struct Node { // [l, r) !!!
        int l, r, link, par;
        unordered_map<int, int> nxt;
        Node(): l(-1), r(-1), link(-1), par(-1) { }
        Node(int _l, int _r, int _link, int _par):
                l(_l), r(_r), link(_link), par(_par) { }
        int &next(int c) {
            if (!nxt.count(c))
                nxt[c] = -1;
            return nxt[c];
        }
        int get_len() const { return r - l; }};
    struct State { int v, len; };
    vector<Node> t; State cur_state; vector<int> s;
    SuffixTree(): cur_state({0, 0}) { t.push_back(Node()); }
    State go(State st, int l, int r) { // v -> v + s[l, r) !!!
        while(l < r) {
            if(st.len == t[st.v].get_len()) {
                State nx = State({ t[st.v].next(s[l]), 0 });
                if(nx.v == -1) return nx; st = nx; continue; }
            if(s[ t[st.v].l + st.len ] != s[l]) return State({-1, -1});
            if(r - l < t[st.v].get_len() - st.len) return State({st.v, st.len + r - l});
            l += t[st.v].get_len() - st.len, st.len = t[st.v].get_len();}return st;}
    int get_vertex(State st) {if(t[st.v].get_len() == st.len) return st.v;
        if(st.len == 0) return t[st.v].par;
        Node &v = t[st.v]; Node &pv = t[v.par]; Node add(v.l, v.l + st.len, -1, v.par);
        pv.next(s[v.l]) = (int)t.size(); add.next(s[v.l + st.len]) = st.v;
        v.par = (int)t.size(), v.l += st.len, t.push_back(add);return (int)t.size() - 1;}
    int get_link(int v) {
        if(t[v].link != -1) return t[v].link;
        if(t[v].par == -1) return 0;
        int to = get_link(t[v].par);
        to = get_vertex(go(State({to, t[to].get_len()}), t[v].l + (t[v].par == 0), t[v].r));
        return t[v].link = to;}
    void add_symbol(int c) {
        s.push_back(c); while(1) {
            State hlp = go( cur_state, (int)s.size() - 1, (int)s.size() );
            if(hlp.v != -1) { cur_state = hlp; break; }
            int v = get_vertex(cur_state); Node add((int)s.size() - 1, +inf, -1, v);
            t.push_back(add); t[v].next(c) = (int)t.size() - 1;
            cur_state.v = get_link(v), cur_state.len = t[cur_state.v].get_len();
            if(!v) break;}}};

ll dfs(
        int v,
        const vector<vector<int>>& g,
        const vector<int>& cost,
        const SuffixTree& tree,
        ll depth,
        ll& res,
        const vector<pii>& sharps
) {
    ll sm = 0;
    for (int to : g[v]) {
        const auto& node = tree.t[to];
        int l = node.l;
        int r = min((int) tree.s.size(), node.r);
        auto fnd = lower_bound(sharps.begin(), sharps.end(), make_pair(l, -1));
        if (fnd == sharps.end() || fnd->first >= r) {
            sm += dfs(to, g, cost, tree, depth + r - l, res, sharps);
        } else {
            int pos, symbol;
            tie(pos, symbol) = *fnd;
            if (pos > l)
                res = max(res, (depth + pos - l) * cost[symbol]);
            sm += cost[symbol];
        }
    }
    res = max(res, depth * sm);
    return sm;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    SuffixTree tree;

    vector<pii> sharps;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s)
            tree.add_symbol(c - 'a');
        sharps.emplace_back((int) tree.s.size(), i);
        tree.add_symbol(26 + i);
    }

    int sz = (int) tree.t.size();

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    vector<int> par(sz, -1);

    for (int i = 0; i < sz; i++) {
        const auto& node = tree.t[i];
        par[i] = node.par;
    }

    vector<vector<int>> g(sz);
    for (int i = 0; i < sz; i++)
        if (par[i] != -1)
            g[par[i]].push_back(i);

    ll res = 0;

    dfs(0, g, cost, tree, 0, res, sharps);

    cout << res << "\n";

    return 0;
}