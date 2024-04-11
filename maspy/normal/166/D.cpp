#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ll8 = __int128;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using vvvvvc = vector<vvvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FORIN(x, A) for (auto&& x : A)
#define FOR_nCk(s, n, k) \
  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1))) 
#define FOR_SUB(t, s) for(ll t = s; t >= 0; t = (t==0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()

#define elif else if

#define popcnt_int __builtin_popcount
#define popcnt __builtin_popcountll

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

#define INT(...) \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...) \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...) \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...) \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &a) {for(auto &i : a) scan(i);}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}

vi s_to_vi(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto&& x : A) {
    ++C[x];
  }
  return C;
}

template <typename T>
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){
    return A[i] < A[j] || (A[i] == A[j] && i < j);
  });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

template <typename T>
vc<T> merge_sort(vc<T>& A, vc<T>& B) {
  vc<T> C;
  C.reserve(A.size() + B.size());
  merge(all(A), all(B), back_inserter(C));
  return C;
}
#line 2 "main.cpp"

#line 4 "main.cpp"

#line 1 "/home/maspy/library/flow/maxflow.hpp"

template <class T>
struct simple_queue {
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

template <class Cap>
struct mf_graph {
 public:
  mf_graph() : _n(0) {}
  explicit mf_graph(int n) : _n(n), g(n) {}

  int add(int frm, int to, Cap cap) {
    assert(0 <= frm && frm < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    int m = int(pos.size());
    pos.push_back({frm, int(g[frm].size())});
    int frm_id = int(g[frm].size());
    int to_id = int(g[to].size());
    if (frm == to) to_id++;
    g[frm].push_back(_edge{to, to_id, cap});
    g[to].push_back(_edge{frm, frm_id, 0});
    return m;
  }

  struct edge {
    int frm, to;
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

  Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
  Cap flow(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);

    std::vector<int> level(_n), iter(_n);
    simple_queue<int> que;

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
        Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
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
    simple_queue<int> que;
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
#line 6 "main.cpp"

void solve() {
  LL(N);
  //  -> 
  map<ll, pi> A;
  FOR(i, N) {
    LL(a, b);
    A[b] = mp(i + 1, a);
  }

  const ll INF = 1LL << 60;
  auto get = [&](ll s) -> pi {
    if (A.count(s)) return A[s];
    return mp(-1, INF);
  };

  LL(M);
  VEC(pi, B, M);
  FOR(i, M) swap(B[i].fi, B[i].se);
  auto I = argsort(B);

  /*
  
   s 
    s, s+1 
  */

  vvv(ll, DP, M + 1, 2, 2, -INF);
  using T = tuple<ll, ll, ll>;
  vvv(T, PAR, M + 1, 2, 2, mt(-1, -1, -1));
  DP[0][0][0] = 0;

  FOR(m, M) {
    auto &dp = DP[m];
    auto &newdp = DP[m + 1];
    auto &par = PAR[m + 1];

    ll i = I[m];
    ll s = B[i].fi;
    ll d = B[i].se;
    // print(s, d);

    FOR(a, 2) FOR(b, 2) {
      if (dp[a][b] == -INF) continue;
      ll t = (m == 0 ? -10 : B[I[m - 1]].fi);
      bool x1, x2;
      if (t < s - 1) x1 = false;
      elif (t == s - 1) x1 = b;
      elif (t == s) x1 = a;
      if (t <= s - 1) x2 = false;
      elif (t == s) x2 = b;

      if (x1 == 0 && get(s).se <= d &&
          chmax(newdp[1][x2], dp[a][b] + get(s).se)) {
        par[1][x2] = mt(get(s).fi, a, b);
      }
      if (x2 == 0 && get(s + 1).se <= d &&
          chmax(newdp[x1][1], dp[a][b] + get(s + 1).se)) {
        par[x1][1] = mt(get(s + 1).fi, a, b);
      }
      // 
      if (chmax(newdp[x1][x2], dp[a][b])) par[x1][x2] = mt(-1, a, b);
    }
  }
  ll ans = -INF;
  ll a = -1, b = -1;
  FOR(c, 2) FOR(d, 2) if (chmax(ans, DP[M][c][d])) { a = c, b = d; }

  print(ans);
  vc<pi> ANS;
  ll m = M;

  while (m) {
    // print(m, a, b, DP[m][a][b]);
    auto [t, c, d] = PAR[m][a][b];
    if (t != -1) { ANS.eb(mp(I[m - 1] + 1, t)); }
    --m;
    a = c, b = d;
  }
  print(ANS.size());
  FORIN(p, ANS) print(p);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}