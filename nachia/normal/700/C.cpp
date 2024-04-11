#line 1 "Main.cpp"

#ifndef ATCODER_MAXFLOW_HPP
#define ATCODER_MAXFLOW_HPP 1

#include <algorithm>
#ifndef ATCODER_INTERNAL_QUEUE_HPP
#define ATCODER_INTERNAL_QUEUE_HPP 1

#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_QUEUE_HPP

#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

#endif  // ATCODER_MAXFLOW_HPP


#include <array>
#line 2 "nachia-library\\misc\\fastio.hpp"

#include <cstdio>
#include <string>

namespace nachia{


const unsigned int INPUT_BUF_SIZE = 1 << 17;
const unsigned int OUTPUT_BUF_SIZE = 1 << 17;

char input_buf[INPUT_BUF_SIZE];

struct InputBufIterator{
private:
    unsigned int p = INPUT_BUF_SIZE;
public:
    using MyType = InputBufIterator;
    static bool is_whitespace(char ch){
        switch(ch){
            case ' ': case '\n': case '\r': case '\t': return true;
        }
        return false;
    }
    char seek_char(){
        if(p == INPUT_BUF_SIZE){
            size_t len = fread(input_buf, 1, INPUT_BUF_SIZE, stdin);
            if(len != INPUT_BUF_SIZE) input_buf[len] = '\0';
            p = 0;
        }
        return input_buf[p];
    }
    void skip_whitespace(){
        while(is_whitespace(seek_char())) p++;
    }
    unsigned int next_uint(){
        skip_whitespace();
        unsigned int buf = 0;
        while(true){
            char tmp = seek_char();
            if('9' < tmp || tmp < '0') break;
            buf = buf * 10 + (tmp - '0');
            p++;
        }
        return buf;
    }
    int next_int(){
        skip_whitespace();
        if(seek_char() == '-'){
            p++;
            return (int)(-next_uint());
        }
        return (int)next_uint();
    }
    unsigned long long next_ulong(){
        skip_whitespace();
        unsigned long long buf = 0;
        while(true){
            char tmp = seek_char();
            if('9' < tmp || tmp < '0') break;
            buf = buf * 10 + (tmp - '0');
            p++;
        }
        return buf;
    }
    long long next_long(){
        skip_whitespace();
        if(seek_char() == '-'){
            p++;
            return (long long)(-next_ulong());
        }
        return (long long)next_ulong();
    }
    char next_char(){
        skip_whitespace();
        char buf = seek_char();
        p++;
        return buf;
    }
    std::string next_token(){
        skip_whitespace();
        std::string buf;
        while(true){
            char ch = seek_char();
            if(is_whitespace(ch) || ch == '\0') break;
            buf.push_back(ch);
            p++;
        }
        return buf;
    }
    MyType& operator>>(unsigned int& dest){ dest = next_uint(); return *this; }
    MyType& operator>>(int& dest){ dest = next_int(); return *this; }
    MyType& operator>>(unsigned long& dest){ dest = next_ulong(); return *this; }
    MyType& operator>>(long& dest){ dest = next_long(); return *this; }
    MyType& operator>>(unsigned long long& dest){ dest = next_ulong(); return *this; }
    MyType& operator>>(long long& dest){ dest = next_long(); return *this; }
    MyType& operator>>(std::string& dest){ dest = next_token(); return *this; }
    MyType& operator>>(char& dest){ dest = next_char(); return *this; }
};


char output_buf[OUTPUT_BUF_SIZE] = {};

struct FastOutputTable{
    char dig3lz[1000][4];
    char dig3nlz[1000][4];
    FastOutputTable(){
        for(unsigned int d=0; d<1000; d++){
            unsigned int x = d;
            unsigned int i = 0;
            dig3lz[d][i++] = ('0' + x / 100 % 10);
            dig3lz[d][i++] = ('0' + x /  10 % 10);
            dig3lz[d][i++] = ('0' + x /   1 % 10);
            dig3lz[d][i++] = '\0';
        }
        for(unsigned int d=0; d<1000; d++){
            unsigned int x = d;
            unsigned int i = 0;
            if(x >= 100) dig3nlz[d][i++] = ('0' + x / 100 % 10);
            if(x >=  10) dig3nlz[d][i++] = ('0' + x /  10 % 10);
            if(x >=   1) dig3nlz[d][i++] = ('0' + x /   1 % 10);
            dig3nlz[d][i++] = '\0';
        }
    }
} fastoutput_table_inst;

struct OutputBufIterator{
    using MyType = OutputBufIterator;
    unsigned int p = 0;
    static constexpr unsigned int POW10(int d){ return (d<=0) ? 1 : (POW10(d-1)*10); }
    static constexpr unsigned long long POW10LL(int d){ return (d<=0) ? 1 : (POW10LL(d-1)*10); }
    void next_char(char c){
        output_buf[p++] = c;
        if(p == OUTPUT_BUF_SIZE){
            fwrite(output_buf, p, 1, stdout);
            p = 0;
        }
    }
    void next_eoln(){
        next_char('\n');
    }
    void next_cstr(const char* s){
        unsigned int i = 0;
        while(s[i]) next_char(s[i++]);
    }
    void next_dig9(unsigned int x){
        unsigned int y;
        y = x / POW10(6); x -= y * POW10(6);
        next_cstr(fastoutput_table_inst.dig3lz [y]);
        y = x / POW10(3); x -= y * POW10(3);
        next_cstr(fastoutput_table_inst.dig3lz [y]);
        y = x;
        next_cstr(fastoutput_table_inst.dig3lz [y]);
    }
    void next_uint(unsigned int x){
        unsigned int y = 0;
        if(x >= POW10(9)){
            y = x / POW10(9); x -= y * POW10(9);
            next_cstr(fastoutput_table_inst.dig3nlz[y]);
            next_dig9(x);
        }
        else if(x >= POW10(6)){
            y = x / POW10(6); x -= y * POW10(6);
            next_cstr(fastoutput_table_inst.dig3nlz[y]);
            y = x / POW10(3); x -= y * POW10(3);
            next_cstr(fastoutput_table_inst.dig3lz [y]);
            next_cstr(fastoutput_table_inst.dig3lz [x]);
        }
        else if(x >= POW10(3)){
            y = x / POW10(3); x -= y * POW10(3);
            next_cstr(fastoutput_table_inst.dig3nlz[y]);
            next_cstr(fastoutput_table_inst.dig3lz [x]);
        }
        else if(x >= 1){
            next_cstr(fastoutput_table_inst.dig3nlz[x]);
        }
        else{
            next_char('0');
        }
    }
    void next_int(int x){
        if(x >= 0) next_uint(x);
        else{
            next_char('-');
            next_uint((unsigned int)-x);
        }
    }
    void next_ulong(unsigned long long x){
        unsigned int y = 0;
        if(x >= POW10LL(18)){
            y = x / POW10LL(18); x -= y * POW10LL(18);
            next_uint(y);
            y = x / POW10LL(9); x -= y * POW10LL(9);
            next_dig9(y);
            next_dig9(x);
        }
        else if(x >= POW10LL(9)){
            y = x / POW10LL(9); x -= y * POW10LL(9);
            next_uint(y);
            next_dig9(x);
        }
        else{
            next_uint(x);
        }
    }
    void next_long(long long x){
        if(x >= 0) next_ulong(x);
        else{
            next_char('-');
            next_ulong((unsigned long long)-x);
        }
    }
    void write_to_file(bool flush = false){
        fwrite(output_buf, p, 1, stdout);
        if(flush) fflush(stdout);
        p = 0;
    }
    ~OutputBufIterator(){ write_to_file(); }
    MyType& operator<<(unsigned int tg){ next_uint(tg); return *this; }
    MyType& operator<<(unsigned long tg){ next_ulong(tg); return *this; }
    MyType& operator<<(unsigned long long tg){ next_ulong(tg); return *this; }
    MyType& operator<<(int tg){ next_int(tg); return *this; }
    MyType& operator<<(long tg){ next_long(tg); return *this; }
    MyType& operator<<(long long tg){ next_long(tg); return *this; }
    MyType& operator<<(const std::string& tg){ next_cstr(tg.c_str()); return *this; }
    MyType& operator<<(const char* tg){ next_cstr(tg); return *this; }
    MyType& operator<<(char tg){ next_char(tg); return *this; }
};

} // namespace nachia
#line 2 "nachia-library\\graph\\undirected-graph-contraction.hpp"

#line 2 "nachia-library\\graph\\adjacency-list.hpp"

#include <vector>
#include <utility>

namespace nachia{
    
struct AdjacencyList{
public:
    struct AdjacencyListRange{
        using iterator = typename std::vector<int>::const_iterator;
        iterator begi, endi;
        iterator begin() const { return begi; }
        iterator end() const { return endi; }
        int size() const { return (int)std::distance(begi, endi); }
        const int& operator[](int i) const { return begi[i]; }
    };
private:
    int mn;
    std::vector<int> E;
    std::vector<int> I;
public:
    AdjacencyList(int n, const std::vector<std::pair<int,int>>& edges, bool rev){
        mn = n;
        std::vector<int> buf(n+1, 0);
        for(auto [u,v] : edges){ ++buf[u]; if(rev) ++buf[v]; }
        for(int i=1; i<=n; i++) buf[i] += buf[i-1];
        E.resize(buf[n]);
        for(int i=(int)edges.size()-1; i>=0; i--){
            auto [u,v] = edges[i];
            E[--buf[u]] = v;
            if(rev) E[--buf[v]] = u;
        }
        I = std::move(buf);
    }
    AdjacencyList(const std::vector<std::vector<int>>& edges = {}){
        int n = mn = edges.size();
        std::vector<int> buf(n+1, 0);
        for(int i=0; i<n; i++) buf[i+1] = buf[i] + edges[i].size();
        E.resize(buf[n]);
        for(int i=0; i<n; i++) for(int j=0; j<(int)edges[i].size(); j++) E[buf[i]+j] = edges[i][j];
        I = std::move(buf);
    }
    static AdjacencyList from_raw(std::vector<int> targets, std::vector<int> bounds){
        AdjacencyList res;
        res.mn = bounds.size() - 1;
        res.E = std::move(targets);
        res.I = std::move(bounds);
        return res;
    }
    AdjacencyListRange operator[](int u) const {
        return AdjacencyListRange{ E.begin() + I[u], E.begin() + I[u+1] };
    }
    int num_vertices() const { return mn; }
    int size() const { return num_vertices(); }
    int num_edges() const { return E.size(); }
    AdjacencyList reversed_edges() const {
        AdjacencyList res;
        int n = res.mn = mn;
        std::vector<int> buf(n+1, 0);
        for(int v : E) ++buf[v];
        for(int i=1; i<=n; i++) buf[i] += buf[i-1];
        res.E.resize(buf[n]);
        for(int u=0; u<n; u++) for(int v : operator[](u)) res.E[--buf[v]] = u;
        res.I = std::move(buf);
        return res;
    }
};

} // namespace nachia
#line 4 "nachia-library\\graph\\undirected-graph-contraction.hpp"

#include <cassert>
#include <algorithm>
#line 9 "nachia-library\\graph\\undirected-graph-contraction.hpp"

namespace nachia{

class UndirectedGraphContraction{
public:

    struct ContractionResult{
        std::vector<int> mapping;
        int n;
        std::vector<std::pair<int,int>> undirectedEdges;
    };

    static void BucketSort(std::vector<std::pair<int,int>>& a, int max_val){
        int n = a.size();

        std::vector<int> ord1(n);
        std::vector<int> buckets_size(max_val+1, 0);
        for(int i=0; i<n; i++) buckets_size[a[i].second]++;
        for(int i=0; i<max_val; i++) buckets_size[i+1] += buckets_size[i];
        for(int i=n-1; i>=0; i--) ord1[--buckets_size[a[i].second]] = i;

        std::vector<int> ord2(n);
        for(int i=0; i<=max_val; i++) buckets_size[i] = 0;
        for(int i=0; i<n; i++) buckets_size[a[i].first]++;
        for(int i=0; i<max_val; i++) buckets_size[i+1] += buckets_size[i];
        for(int i=n-1; i>=0; i--) ord2[--buckets_size[a[ord1[i]].first]] = ord1[i];

        std::vector<std::pair<int,int>> res(n);
        for(int i=0; i<n; i++) res[i] = a[ord2[i]];
        std::swap(a, res);
    }

    static void UniqueEdges(std::vector<std::pair<int,int>>& edges){
        int maxVal = 0;
        for(auto& e : edges) maxVal = std::max(maxVal, std::max(e.first, e.second));
        BucketSort(edges, maxVal+1);
        edges.erase(std::unique(edges.begin(), edges.end()), edges.end());
    }

    static std::vector<int> Connectivity(const nachia::AdjacencyList& adj){
        int n = adj.num_vertices();
        std::vector<int> dsu(n, -1);
        int newN = 0;
        for(int s=0; s<n; s++) if(dsu[s] == -1){
            std::vector<int> bfs = {s};
            dsu[s] = newN;
            for(int i=0; i<(int)bfs.size(); i++){
                int p = bfs[i];
                for(int nx : adj[p]) if(dsu[nx] == -1){
                    dsu[nx] = newN;
                    bfs.push_back(nx);
                }
            }
            newN++;
        }
        return dsu;
    }

    static ContractionResult GraphContractionWithColor(const nachia::AdjacencyList& adj, const std::vector<int>& color){
        int n = adj.num_vertices();
        assert((int)color.size() == n);
        ContractionResult res;
        std::vector<std::pair<int,int>> edges;
        for(int u=0; u<n; u++) for(int v : adj[u]) if(u < v) if(color[u] == color[v]) edges.push_back(std::make_pair(u, v));
        std::vector<int> dsu = Connectivity(nachia::AdjacencyList(n, edges, true));
        edges.clear();
        for(int u=0; u<n; u++) for(int v : adj[u]) if(u < v) if(dsu[u] != dsu[v]) edges.push_back(std::make_pair(u, v));
        res.n = 1 + *std::max_element(dsu.begin(), dsu.end());
        UniqueEdges(edges);
        res.undirectedEdges = std::move(edges);
        res.mapping = std::move(dsu);
        return res;
    }

    static ContractionResult GraphContractionWithEdges(const nachia::AdjacencyList& adj, const nachia::AdjacencyList& contraction){
        return GraphContractionWithColor(adj, Connectivity(contraction));
    }
};

} // namespace nachia
#line 2 "nachia-library\\graph\\two-edge-connected-components.hpp"

#line 2 "nachia-library\\graph\\adjacency-list-indexed.hpp"

#line 5 "nachia-library\\graph\\adjacency-list-indexed.hpp"

namespace nachia{

struct AdjacencyListEdgeIndexed{
public:
    struct Edge { int to; int edgeidx; };
    struct AdjacencyListRange{
        using iterator = typename std::vector<Edge>::const_iterator;
        iterator begi, endi;
        iterator begin() const { return begi; }
        iterator end() const { return endi; }
        int size() const { return (int)std::distance(begi, endi); }
        const Edge& operator[](int i) const { return begi[i]; }
    };
private:
    int mn;
    std::vector<Edge> E;
    std::vector<int> I;
public:
    AdjacencyListEdgeIndexed(int n, const std::vector<std::pair<int,int>>& edges, bool rev){
        mn = n;
        std::vector<int> buf(n+1, 0);
        for(auto [u,v] : edges){ ++buf[u]; if(rev) ++buf[v]; }
        for(int i=1; i<=n; i++) buf[i] += buf[i-1];
        E.resize(buf[n]);
        for(int i=(int)edges.size()-1; i>=0; i--){
            auto [u,v] = edges[i];
            E[--buf[u]] = { v, i };
            if(rev) E[--buf[v]] = { u, i };
        }
        I = std::move(buf);
    }
    AdjacencyListEdgeIndexed() : AdjacencyListEdgeIndexed(0, {}, false) {}
    AdjacencyListRange operator[](int u) const {
        return AdjacencyListRange{ E.begin() + I[u], E.begin() + I[u+1] };
    }
    int num_vertices() const { return mn; }
    int size() const { return num_vertices(); }
    int num_edges() const { return E.size(); }
    AdjacencyListEdgeIndexed reversed_edges() const {
        AdjacencyListEdgeIndexed res;
        int n = res.mn = mn;
        std::vector<int> buf(n+1, 0);
        for(auto [v,i] : E) ++buf[v];
        for(int i=1; i<=n; i++) buf[i] += buf[i-1];
        res.E.resize(buf[n]);
        for(int u=0; u<n; u++) for(auto [v,i] : operator[](u)) res.E[--buf[v]] = {u,i};
        res.I = std::move(buf);
        return res;
    }
};

} // namespace nachia
#line 4 "nachia-library\\graph\\two-edge-connected-components.hpp"

#line 7 "nachia-library\\graph\\two-edge-connected-components.hpp"

#include <iostream>
namespace nachia{

struct TwoEdgeConnectedComponents{
    std::vector<int> color;
    std::vector<int> bridges;
    std::vector<std::pair<int, int>> colorAdjacency;
    int colorCount;
    TwoEdgeConnectedComponents(const AdjacencyListEdgeIndexed& eg){
        int n = eg.num_vertices();
        std::vector<int> P(n,-1);
        std::vector<int> ord(n,-1);
        int ordi = 0;
        std::vector<int> mem(eg.num_edges() + 1);
        int memi = 0;
        for(int s=0; s<n; s++) if(ord[s] == -1){
            mem[memi++] = s;
            while(memi){
                int p = mem[--memi];
                if(ord[p] != -1) continue;
                ord[p] = ordi++;
                for(auto [to, i] : eg[p]){
                    if(p == to) continue;
                    if(ord[to] != -1) continue;
                    P[to] = i;
                    mem[memi++] = to;
                }
            }
        }
        std::vector<int> I(n);
        for(int i=0; i<n; i++) I[ord[i]] = i;
        std::vector<int> rev(n,n);
        for(int i=0; i<n; i++) rev[i] = i;
        for(int i=n-1; i>=0; i--){
            int p = I[i];
            int pre = -1;
            for(auto e : eg[p]){
                if(P[p] == e.edgeidx) pre = e.to;
                else if(ord[rev[p]] > ord[e.to]) rev[p] = e.to;
            }
            if(pre != -1) if(ord[rev[pre]] > ord[rev[p]]) rev[pre] = rev[p];
        }

        for(int p : I) rev[p] = rev[rev[p]];
        int newN = 0;
        std::vector<int> mapping(n, -1);
        for(int p : rev) if(mapping[p] == -1) mapping[p] = newN++;
        colorCount = newN;
        color.assign(n, -1);
        for(int i=0; i<n; i++) color[i] = mapping[rev[i]];
        bridges = {};
        for(int u=0; u<n; u++) for(auto e : eg[u]) if(u < e.to && color[u] != color[e.to]){
            colorAdjacency.push_back(std::make_pair(color[u], color[e.to]));
            bridges.push_back(e.edgeidx);
        }
    }
};

}

#line 2 "nachia-library\\tree\\tree-edge-path.hpp"

#line 4 "nachia-library\\tree\\tree-edge-path.hpp"

#line 6 "nachia-library\\tree\\tree-edge-path.hpp"

namespace nachia{

// no path -> empty
// T undirected
std::vector<int> UnitTreeEdgePath(const AdjacencyListEdgeIndexed& T, int s, int t){
    std::vector<int> bfs = {s};
    std::vector<int> pre(T.num_vertices(), -1);
    std::vector<int> preE(T.num_vertices(), -1);
    pre[s] = -2;
    for(int i=0; i<(int)bfs.size(); i++){
        int p = bfs[i];
        for(auto e : T[p]) if(pre[e.to] == -1){
            pre[e.to] = p;
            preE[e.to] = e.edgeidx;
            bfs.push_back(e.to);
        }
    }
    if(pre[t] == -1) return {-1};
    if(pre[t] == -2) return {};
    std::vector<int> res = {};
    int pos = t;
    while(pos != s){
        res.push_back(preE[pos]);
        pos = pre[pos];
    }
    std::reverse(res.begin(), res.end());
    return res;
}

} // namespace nachia

#line 2 "nachia-library\\graph\\biconnected-components-nonrecursive.hpp"

#line 5 "nachia-library\\graph\\biconnected-components-nonrecursive.hpp"

#line 7 "nachia-library\\graph\\biconnected-components-nonrecursive.hpp"

namespace nachia{

class BiconnectedComponentsNonrecursive{
private:
    int mn;
    int mm;
    int mnum_bcs;
    std::vector<std::pair<int, int>> medges;
    std::vector<int> edgeidx_to_bcidx;
public:
    BiconnectedComponentsNonrecursive(int n, std::vector<std::pair<int, int>> edges){

        mn = n;
        int m = edges.size();
        medges = std::move(edges);
        AdjacencyListEdgeIndexed adj(n, medges, true);

        std::vector<int> vtx_to_dfsi(n);
        std::vector<int> dfs_parent(n, -1);
        std::vector<int> dfs_parentp(n, -1);
        std::vector<int> dfs_backedge(n, -1);
        int dfsi = 0;
        
        int num_bcs = 0;
        std::vector<int> res(m);

        std::vector<int> mem(n*2);
        int memi = 0;

        for(int i=0; i<n; i++) if(dfs_parent[i] == -1){
            dfs_parent[i] = -2;
            mem[memi++] = i; mem[memi++] = 0;
            while(memi){
                int ei = mem[--memi];
                int p = mem[--memi];
                if(ei == 0){
                    vtx_to_dfsi[p] = dfs_backedge[p] = dfsi++;
                }
                while(true){
                    if(ei == adj[p].size()){
                        if(0 <= dfs_parentp[p]){
                            dfs_backedge[dfs_parentp[p]] = ::std::min(dfs_backedge[dfs_parentp[p]], dfs_backedge[p]);
                        }
                        break;
                    }
                    auto [nx,i] = adj[p][ei++];
                    if(dfs_parent[nx] != -1){
                        dfs_backedge[p] = ::std::min(dfs_backedge[p], vtx_to_dfsi[nx]);
                    }
                    else{
                        dfs_parent[nx] = i;
                        dfs_parentp[nx] = p;
                        memi++; mem[memi++] = ei;
                        mem[memi++] = nx; mem[memi++] = 0;
                        break;
                    }
                }
            }
        }

        for(int i=0; i<n; i++) if(dfs_parent[i] < 0){
            mem[memi++] = i;
            while(memi){
                int p = mem[--memi];
                if(dfs_parent[p] < 0){
                    for(auto [nx,i] : adj[p]) if(dfs_parent[nx] == i){
                        mem[memi++] = nx; dfs_backedge[nx] = num_bcs++;
                    }
                    continue;
                }
                for(auto [nx,i] : adj[p]){
                    if(dfs_parent[nx] != i) res[i] = dfs_backedge[p];
                    else{
                        mem[memi++] = nx;
                        dfs_backedge[nx] = (dfs_backedge[nx] < vtx_to_dfsi[p]) ? dfs_backedge[p] : num_bcs++;
                    }
                }
            }
        }

        edgeidx_to_bcidx = ::std::move(res);
        mm = m;
        mnum_bcs = num_bcs;
    }

    int get_num_bcs() const { return mnum_bcs; }

    std::vector<std::vector<int>> get_bcs() const {
        std::vector<std::vector<int>> res(mnum_bcs);
        for(int i=0; i<mm; i++){
            res[edgeidx_to_bcidx[i]].push_back(i);
        }
        return res;
    }

    AdjacencyList get_bct() const {
        int bct_n = mn + mnum_bcs;
        AdjacencyList bc_edgelists; {
            std::vector<int> buf(mnum_bcs+1);
            for(int bci : edgeidx_to_bcidx) ++buf[bci];
            for(int i=1; i<=mnum_bcs; i++) buf[i] += buf[i-1];
            std::vector<int> E(buf.back());
            for(int i=0; i<mm; i++) E[--buf[edgeidx_to_bcidx[i]]] = i;
            bc_edgelists = AdjacencyList::from_raw(std::move(E), std::move(buf));
        }
        std::vector<std::pair<int, int>> res(bct_n * 2 - 1);
        int resi = 0;
        int bci = 0;
        std::vector<int> visited(mn, -1);
        for(bci=0 ; bci<mnum_bcs; bci++){
            for(int e : bc_edgelists[bci]){
                auto [u,v] = medges[e];
                if(visited[u] != bci){ visited[u] = bci; res[resi++] = {mn+bci,u}; }
                if(visited[v] != bci){ visited[v] = bci; res[resi++] = {mn+bci,v}; }
            }
        }
        for(int i=0; i<mn; i++) if(visited[i] == -1) res[resi++] = {bct_n++,i};
        res.resize(resi);
        return AdjacencyList(bct_n, res, true);
    }
};

} // namespace nachia
#line 186 "Main.cpp"

struct Answer{
    int weight;
    std::vector<int> edges;
};

bool operator<(Answer l, Answer r){ return l.weight < r.weight; }

std::vector<int> getEdgeInvMapping(
    std::vector<std::pair<int,int>>& edges,
    nachia::UndirectedGraphContraction::ContractionResult contraction
){
    std::vector<int> res;
    int idx = -1;
    for(auto& e : edges){
        idx++;
        e.first = contraction.mapping[e.first];
        e.second = contraction.mapping[e.second];
        if(e.first == e.second) continue;
        std::swap(edges[res.size()], e);
        res.push_back(idx);
    }
    edges.resize(res.size());
    return res;
}

#line 213 "Main.cpp"

// 2 lists of edges
std::array<std::vector<int>, 2> takeTwoPaths(int n, const std::vector<std::pair<int,int>>& edges, int s, int t){
    atcoder::mf_graph<int> mf(n);
    int m = edges.size();
    std::vector<std::pair<int,int>> edgeid(m);
    for(int i=0; i<m; i++){
        edgeid[i].first = mf.add_edge(edges[i].first, edges[i].second, 1);
        edgeid[i].second = mf.add_edge(edges[i].second, edges[i].first, 1);
    }
    int f = mf.flow(s, t, 2);
    assert(f == 2);
    std::vector<std::pair<int,int>> effEdges;
    std::vector<int> effEdgesMapping;
    for(int i=0; i<m; i++) if(mf.get_edge(edgeid[i].first).flow){
        effEdges.push_back(std::make_pair(edges[i].first, edges[i].second));
        effEdgesMapping.push_back(i);
    }
    for(int i=0; i<m; i++) if(mf.get_edge(edgeid[i].second).flow){
        effEdges.push_back(std::make_pair(edges[i].second, edges[i].first));
        effEdgesMapping.push_back(i);
    }
    nachia::AdjacencyListEdgeIndexed effAdj(n, effEdges, false);
    std::vector<int> visEdge(n, 0);
    std::array<std::vector<int>, 2> paths;
    for(int i=0; i<2; i++){
        paths[i].push_back(effAdj[s][visEdge[s]++].edgeidx);
        while(true){
            int p = effEdges[paths[i].back()].second;
            if(p == t) break;
            paths[i].push_back(effAdj[p][visEdge[p]++].edgeidx);
        }
        for(int& ei : paths[i]) ei = effEdgesMapping[ei];
    }
    return paths;
}

int main(){
    nachia::InputBufIterator iitr;
    nachia::OutputBufIterator oitr;

    int N = iitr.next_uint();
    int M = iitr.next_uint();
    int S = iitr.next_uint() - 1;
    int T = iitr.next_uint() - 1;
    std::vector<std::pair<int, int>> edges(M);
    std::vector<int> W(M);
    for(int i=0; i<M; i++){
        edges[i].first = iitr.next_uint() - 1;
        edges[i].second = iitr.next_uint() - 1;
        W[i] = iitr.next_uint();
    }

    std::vector<int> edgeMappingInv;
    const int INF = 2001001001;
    Answer ans = {INF, {}};

    {
        auto twoEdge = nachia::TwoEdgeConnectedComponents(nachia::AdjacencyListEdgeIndexed(N, edges, true));
        auto bridgeIdxs = nachia::UnitTreeEdgePath(
            nachia::AdjacencyListEdgeIndexed(twoEdge.colorCount, twoEdge.colorAdjacency, true),
            twoEdge.color[S], twoEdge.color[T]
        );
        if(bridgeIdxs == std::vector<int>{-1}){
            oitr << "0\n0\n\n";
            return 0;
        }
        //oitr.write_to_file(true);
        for(auto& ei : bridgeIdxs) ei = twoEdge.bridges[ei];
        for(auto& ei : bridgeIdxs) ans = std::min(ans, Answer{ W[ei], {ei} });
        //for(auto& ei : bridgeIdxs) oitr << ei << " ";
        //oitr << "\n";
        //oitr.write_to_file(true);
        std::vector<std::pair<int,int>> bridges;
        for(int ei : bridgeIdxs) bridges.push_back(edges[ei]);
        auto contraction = nachia::UndirectedGraphContraction::GraphContractionWithEdges(
            nachia::AdjacencyList(N, edges, true),
            nachia::AdjacencyList(N, bridges, true)
        );
        edgeMappingInv = getEdgeInvMapping(edges, contraction);
        N = contraction.n;
        M = edges.size();
        S = contraction.mapping[S];
        T = contraction.mapping[T];
    }
    
    //oitr << "ans1 = " << ans.weight << "\n"; oitr.write_to_file(true);
    //oitr << "edgeMappingInv = [ ";
    //for(int a : edgeMappingInv) oitr << a << " ";
    //oitr << "]\n";

    if(S != T){
        auto paths = takeTwoPaths(N, edges, S, T);
        for(int i=0; i<2; i++){
            //oitr << "path[" << i << "] = [ ";
            //for(int a : paths[i]) oitr << edgeMappingInv[a] << " ";
            //oitr << "]\n";
            //oitr.write_to_file(true);
        }

        std::vector<int> edgeLiving(M, 0);
        for(int pathI=0; pathI<2; pathI++){
            std::vector<int> edgeMask(M, 1);
            for(int ei : paths[pathI^1]) edgeMask[ei] = 0;
            std::vector<std::pair<int,int>> edges2;
            std::vector<int> edges2Idx;
            for(int i=0; i<M; i++) if(edgeMask[i]){
                edges2.push_back(edges[i]);
                edges2Idx.push_back(i);
            }
            //oitr << "edges2 : ";
            //for(auto e : edges2) oitr << "(" << e.first << "," << e.second << ")";
            //oitr << "\n";
            for(int ei : paths[pathI]) edgeMask[ei] = 0;
            auto twoEdge2 = nachia::TwoEdgeConnectedComponents(nachia::AdjacencyListEdgeIndexed(N, edges2, true));
            for(int ei : twoEdge2.bridges) if(edgeMask[edges2Idx[ei]] == 0) edgeLiving[edges2Idx[ei]] = 1 + pathI;
        }
        //oitr << "edgeLiving : ";
        //for(int i : edgeLiving) oitr << i;
        //oitr << "\n";
        {
            std::vector<std::pair<int,int>> edges2;
            for(int i=0; i<M; i++) if(edgeLiving[i] == 0) edges2.push_back(edges[i]);
            auto contraction = nachia::UndirectedGraphContraction::GraphContractionWithEdges(
                nachia::AdjacencyList(N, edges, true),
                nachia::AdjacencyList(N, edges2, true)
            );
            auto newEdgeMappingInv = getEdgeInvMapping(edges, contraction);
            std::vector<int> newEdgeLiving;
            for(int ei : newEdgeMappingInv) newEdgeLiving.push_back(edgeLiving[ei]);
            for(int& ei : newEdgeMappingInv) ei = edgeMappingInv[ei];
            std::swap(edgeMappingInv, newEdgeMappingInv);
            std::swap(edgeLiving, newEdgeLiving);
            N = contraction.n;
            M = edges.size();
            S = contraction.mapping[S];
            T = contraction.mapping[T];
        }
        //oitr << "N = " << N << "\n";
        //oitr << "edges : ";
        //for(auto e : edges) oitr << "(" << e.first << "," << e.second << ")";
        //oitr << "\n";
        //oitr << "edgeMappingInv : [";
        //for(int ei : edgeMappingInv) oitr << " " << ei;
        //oitr << " ]\n";
        {
            auto bcs = nachia::BiconnectedComponentsNonrecursive(N, edges).get_bcs();
            for(auto& bc : bcs){
                int bestEdge[2] = { -1,-1 };
                //oitr << "bc : [";
                //for(int ei : bc) oitr << " " << edgeMappingInv[ei];
                //oitr << " ]\n";
                for(int ei : bc){
                    int pathId = edgeLiving[ei] - 1;
                    if(bestEdge[pathId] == -1 || W[edgeMappingInv[bestEdge[pathId]]] > W[edgeMappingInv[ei]]) bestEdge[pathId] = ei;
                }
                if(bestEdge[0] != -1 && bestEdge[1] != -1){
                    int u = edgeMappingInv[bestEdge[0]];
                    int v = edgeMappingInv[bestEdge[1]];
                    ans = std::min(ans, Answer{ W[u]+W[v], {u,v} });
                }
            }
        }
    }

    if(ans.weight == INF){
        oitr << "-1\n";
    }
    else{
        oitr << ans.weight << "\n";
        oitr << ans.edges.size() << "\n";
        for(int i=0; i<(int)ans.edges.size(); i++){
            if(i) oitr << " ";
            oitr << (ans.edges[i] + 1);
        }
        oitr << "\n";
    }

    return 0;
}