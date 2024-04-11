//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL


#include <unistd.h>
#include <algorithm>
#include <array>
#include <cctype>
#include <cstring>
#include <string>
#include <type_traits>
#include <vector>


namespace yosupo {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

}  // namespace internal

int bsf(unsigned int n) { return __builtin_ctz(n); }
int bsf(unsigned long n) { return __builtin_ctzl(n); }
int bsf(unsigned long long n) { return __builtin_ctzll(n); }
int bsf(unsigned __int128 n) {
    unsigned long long low = (unsigned long long)(n);
    unsigned long long high = (unsigned long long)(n >> 64);
    return low ? __builtin_ctzll(low) : 64 + __builtin_ctzll(high);
}

int bsr(unsigned int n) {
    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);
}
int bsr(unsigned long n) {
    return 8 * (int)sizeof(unsigned long) - 1 - __builtin_clzl(n);
}
int bsr(unsigned long long n) {
    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);
}
int bsr(unsigned __int128 n) {
    unsigned long long low = (unsigned long long)(n);
    unsigned long long high = (unsigned long long)(n >> 64);
    return high ? 127 - __builtin_clzll(high) : 63 - __builtin_ctzll(low);
}

}  // namespace yosupo

#include <cassert>
#include <numeric>
#include <type_traits>

namespace yosupo {

namespace internal {

template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value ||
                                  internal::is_signed_int128<T>::value ||
                                  internal::is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

template <class T>
using is_integral_t = std::enable_if_t<is_integral<T>::value>;

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace yosupo

namespace yosupo {

struct Scanner {
  public:
    Scanner(FILE* fp) : fd(fileno(fp)) {}

    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }

    int read_unsafe() { return 0; }
    template <class H, class... T> int read_unsafe(H& h, T&... t) {
        bool f = read_single(h);
        if (!f) return 0;
        return 1 + read_unsafe(t...);
    }

  private:
    static constexpr size_t SIZE = 1 << 15;

    bool read_single(std::string& ref) {
        if (!skip_space()) return false;
        ref = "";
        while (true) {
            char c = top();
            if (c <= ' ') break;
            ref += c;
            st++;
        }
        return true;
    }
    bool read_single(double& ref) {
        std::string s;
        if (!read_single(s)) return false;
        ref = std::stod(s);
        return true;
    }

    template <class T, internal::is_signed_int_t<T>* = nullptr>
    bool read_single(T& sref) {
        using U = internal::to_unsigned_t<T>;
        if (!skip_space(50)) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        U ref = 0;
        do {
            ref = 10 * ref + (line[st++] & 0x0f);
        } while (line[st] >= '0');
        sref = neg ? -ref : ref;
        return true;
    }
    template <class U, internal::is_unsigned_int_t<U>* = nullptr>
    bool read_single(U& ref) {
        if (!skip_space(50)) return false;
        ref = 0;
        do {
            ref = 10 * ref + (line[st++] & 0x0f);
        } while (line[st] >= '0');
        return true;
    }

    int fd = -1;
    char line[SIZE];
    size_t st = 0, ed = 0;
    bool eof = false;
    bool reread() {
        if (ed - st >= 50) return true;
        if (st > SIZE / 2) {
            std::memmove(line, line + st, ed - st);
            ed -= st;
            st = 0;
        }
        if (eof) return false;
        auto u = ::read(fd, line + ed, SIZE - ed);
        if (u == 0) {
            eof = true;
            line[ed] = '\0';
            u = 1;
        }
        ed += u;
        return true;
    }

    char top() {
        if (st == ed) {
            bool f = reread();
            assert(f);
        }
        return line[st];
    }

    bool skip_space(unsigned int token_len = 0) {
        while (true) {
            while (st != ed && line[st] <= ' ') st++;
            if (ed - st > token_len) return true;
            for (auto i = st; i < ed; i++) {
                if (line[i] <= ' ') return true;
            }
            if (!reread()) return false;
        }
    }
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fd(fileno(_fp)) {}
    ~Printer() { flush(); }

    void flush() {
        ::write(fd, line, pos);
        pos = 0;
    }

  private:
    static std::array<std::array<char, 2>, 100> small;
    static std::array<unsigned long long, 20> tens;

    static constexpr size_t SIZE = 1 << 15;
    int fd;
    char line[SIZE];
    size_t pos = 0;
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }

    template <class T, internal::is_signed_int_t<T>* = nullptr>
    void write_single(const T& val) {
        using U = internal::to_unsigned_t<T>;
        if (val == 0) {
            write_single('0');
            return;
        }
        if (pos > SIZE - 50) flush();
        U uval = val;
        if (val < 0) {
            write_single('-');
            uval = -uval;
        }
        write_unsigned(uval);
    }

    template <class U, internal::is_unsigned_int_t<U>* = nullptr>
    void write_single(U uval) {
        if (uval == 0) {
            write_single('0');
            return;
        }
        if (pos > SIZE - 50) flush();

        write_unsigned(uval);
    }

    template <class U, internal::is_unsigned_int_t<U>* = nullptr>
    static int calc_len(U x) {
        int i = (bsr(x) * 3 + 3) / 10;
        if (x < tens[i])
            return i;
        else
            return i + 1;
    }

    template <class U,
              internal::is_unsigned_int_t<U>* = nullptr,
              std::enable_if_t<sizeof(U) <= 8>* = nullptr>
    void write_unsigned(U uval) {
        size_t len = calc_len(uval);
        pos += len;

        char* ptr = line + pos;
        while (uval >= 100) {
            ptr -= 2;
            memcpy(ptr, small[uval % 100].data(), 2);
            uval /= 100;
        }
        if (uval >= 10) {
            memcpy(ptr - 2, small[uval].data(), 2);
        } else {
            *(ptr - 1) = char('0' + uval);
        }
    }

    template <
        class U,
        std::enable_if_t<internal::is_unsigned_int128<U>::value>* = nullptr>
    void write_unsigned(U uval) {
        static char buf[50];
        size_t len = 0;
        while (uval > 0) {
            buf[len++] = char((uval % 10) + '0');
            uval /= 10;
        }
        std::reverse(buf, buf + len);
        memcpy(line + pos, buf, len);
        pos += len;
    }

    void write_single(const std::string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const std::vector<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};

std::array<std::array<char, 2>, 100> Printer::small = [] {
    std::array<std::array<char, 2>, 100> table;
    for (int i = 0; i <= 99; i++) {
        table[i][1] = char('0' + (i % 10));
        table[i][0] = char('0' + (i / 10 % 10));
    }
    return table;
}();
std::array<unsigned long long, 20> Printer::tens = [] {
    std::array<unsigned long long, 20> table;
    for (int i = 0; i < 20; i++) {
        table[i] = 1;
        for (int j = 0; j < i; j++) {
            table[i] *= 10;
        }
    }
    return table;
}();

}  // namespace yosupo

#include <iostream>
#include <vector>

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>


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
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
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
        assert(s != t);

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
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
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


namespace yosupo {

template <class Cap, class Cost> struct CostScalingGraph {
    CostScalingGraph(int n) : _n(n), excess(n) {}

    int _n;
    struct Edge {
        int from, to;
        Cap lower_cap, upper_cap, flow;
        Cost cost;
    };

    std::vector<Edge> _edges;
    std::vector<Cap> excess;
    std::vector<Cost> dual;
    Cost max_cost = 0;

    void add_edge(int from, int to, Cap lower_cap, Cap upper_cap, Cost cost) {
        assert(lower_cap <= upper_cap);
        max_cost = std::max(max_cost, cost);
        max_cost = std::max(max_cost, -cost);
        _edges.push_back({from, to, lower_cap, upper_cap, 0, cost});
    }

    void add_excess(int v, Cap x) {
        excess[v] += x;
    }

    struct _Edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::pair<bool, Cost> solve() {
        for (auto e : _edges) {
            excess[e.to] += e.lower_cap;
            excess[e.from] -= e.lower_cap;
        }
        atcoder::mf_graph<Cap> mf_g(_n + 2);
        int sv = _n, tv = sv + 1;
        for (auto e : _edges) {
            mf_g.add_edge(e.from, e.to, e.upper_cap - e.lower_cap);
        }
        Cap excess_s_sum = 0, excess_t_sum = 0;
        for (int i = 0; i < _n; i++) {
            if (0 < excess[i]) {
                excess_s_sum += excess[i];
                mf_g.add_edge(sv, i, excess[i]);
            } else if (excess[i] < 0) {
                excess_t_sum += -excess[i];
                mf_g.add_edge(i, tv, -excess[i]);
            }
        }
        if (excess_s_sum != excess_t_sum || mf_g.flow(sv, tv) != excess_s_sum) {
            return {false, Cost(0)};
        }

        std::vector<std::vector<_Edge>> g(_n);
        std::vector<std::pair<int, int>> pos;
        int m = int(_edges.size());
        for (int i = 0; i < m; i++) {
            auto e = mf_g.get_edge(i);
            Cost cost = _edges[i].cost * _n;
            int from_id = int(g[e.from].size());
            int to_id = int(g[e.to].size());
            if (e.from == e.to) to_id++;
            pos.push_back({e.from, from_id});
            g[e.from].push_back({e.to, to_id, e.cap - e.flow, cost});
            g[e.to].push_back({e.from, from_id, e.flow, -cost});
        }

        solve(g);

        Cost answer = 0;
        for (int i = 0; i < m; i++) {
            auto p = pos[i];
            auto &e = _edges[i];
            auto ge = g[p.first][p.second];
            auto flow = e.upper_cap - ge.cap;
            e.flow = flow;
            answer += flow * e.cost;
        }

        dual = std::vector<Cost>(_n);

        while (true) {
            bool update = false;
            for (int i = 0; i < _n; i++) {
                for (auto e : g[i]) {
                    if (!e.cap) continue;
                    auto cost = dual[i] + e.cost / _n;
                    if (cost < dual[e.to]) {
                        dual[e.to] = cost;
                        update = true;
                    }
                }
            }
            if (!update) break;
        }

        return {true, answer};
    }

    void solve(std::vector<std::vector<_Edge>> &g) {
        std::vector<Cost> dual(_n);
        Cost eps = _n * max_cost + 1;
        auto refine = [&]() {
            std::vector<Cap> excess(_n);
            auto cost = [&](int from, const _Edge& e) {
                return e.cost + dual[from] - dual[e.to];
            };
            auto push = [&](int from, _Edge& e, Cap cap) {
                excess[from] -= cap;
                excess[e.to] += cap;
                g[e.to][e.rev].cap += cap;
                e.cap -= cap;
            };
            for (int u = 0; u < _n; u++) {
                for (auto& e : g[u]) {
                    if (e.cap && cost(u, e) < 0) {
                        push(u, e, e.cap);
                    }
                }
            }
            std::vector<bool> actives_on(_n);
            atcoder::internal::simple_queue<int> actives;
            std::vector<int> iter(_n);

            auto relabel = [&](auto u) {
                iter[u] = 0;
                Cost down = (_n + 1) * max_cost;
                for (auto e : g[u]) {
                    if (e.cap) {
                        down = std::min(down, eps + cost(u, e));
                    }
                }
                dual[u] -= down;
                actives.push(u);
                actives_on[u] = true;
            };

            for (int i = 0; i < _n; i++) {
                if (excess[i] > 0) {
                    actives.push(i);
                    actives_on[i] = true;
                }
            }

            while (actives.size()) {
                int u = actives.front();
                actives.pop();
                actives_on[u] = false;
                for (int& i = iter[u]; i < int(g[u].size()); i++) {
                    auto& e = g[u][i];
                    if (e.cap && cost(u, e) < 0) {
                        push(u, e, std::min(excess[u], e.cap));
                        if (!actives_on[e.to] && excess[e.to] > 0) {
                            actives_on[e.to] = true;
                            actives.push(e.to);
                        }
                        if (excess[u] == 0) {
                            break;
                        }
                    }
                }
                if (excess[u] > 0) {
                    relabel(u);
                }
            }

            eps = 0;
            for (int u = 0; u < _n; u++) {
                for (auto& e : g[u]) {
                    if (e.cap) {
                        eps = std::max(eps, -(e.cost + dual[u] - dual[e.to]));
                    }
                }
            }
        };

        while (eps > 1) {
            eps = std::max<Cost>(eps >> 2, 1);
            refine();
        }
    }
};

}
using namespace yosupo;

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL

ostream& operator<<(ostream& os, __int128_t x) {
    if (x < 0) {
        os << "-";
        x *= -1;
    }
    if (x == 0) {
        return os << "0";
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}
ostream& operator<<(ostream& os, __uint128_t x) {
    if (x == 0) {
        return os << "0";
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p);
template <class T> ostream& operator<<(ostream& os, const V<T>& v);
template <class T> ostream& operator<<(ostream& os, const deque<T>& v);
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a);
template <class T> ostream& operator<<(ostream& os, const set<T>& s);
template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& m);

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    bool f = false;
    for (auto d : v) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}

template <class T> ostream& operator<<(ostream& os, const deque<T>& v) {
    os << "[";
    bool f = false;
    for (auto d : v) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a) {
    os << "[";
    bool f = false;
    for (auto d : a) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}

template <class T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool f = false;
    for (auto d : s) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "}";
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& s) {
    os << "{";
    bool f = false;
    for (auto p : s) {
        if (f) os << ", ";
        f = true;
        os << p.first << ": " << p.second;
    }
    return os << "}";
}

struct PrettyOS {
    ostream& os;
    bool first;

    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
#endif

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

int main() {
    int n, m;
    sc.read(n, m);
    CostScalingGraph<ll, __int128> g(n+1);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        sc.read(x);
        a[i] = x;
    }
    for(int i=0;i<n+1;i++){
        g.add_excess(i, 0);
        g.add_edge(i, n, 0, 1, 0);
        g.add_edge(n, i, 0, 1, 0);
    }
    long long INF = 1LL<<30;
  
    for (int i = 0; i < m; i++) {
        int u, v;
        sc.read(u, v);
        --u, --v;
        g.add_edge(v, u, 0, INF, a[v]-a[u]);
    }

    auto res = g.solve();
    for(int v=0;v<n;++v){
      a[v] += g.dual[v] - g.dual[n];
      if(v) cout << " ";
      cout << a[v];
    }
    cout << endl;
    return 0;
}