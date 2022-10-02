#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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
#line 2 "main.cpp"

#line 1 "/home/maspy/library/flow/mincostflow.hpp"
template <typename Cap, typename Cost>
struct MinCostFlow {
 protected:
  using P = pair<Cost, int>;
  struct edge {
    int to;
    Cap cap;
    Cost cost;
    int rev;
    bool isrev;
  };
  vector<Cost> h;
  vector<Cost> dist;
  vector<int> prevv, preve;
  bool negative;

 public:
  int V;
  vector<vector<edge>> G;
  Cost INF = numeric_limits<Cost>::max();
  MinCostFlow() {}
  MinCostFlow(int v) : h(v), dist(v), prevv(v), preve(v), negative(false), V(v), G(v) {}
  void add(int from, int to, Cap cap, Cost cost) {
    assert(0 <= from && from < V);
    assert(0 <= to && to < V);
    assert(0 <= cap);
    if (cap == 0) return;
    if (cost < 0) negative = true;
    G[from].push_back({to, cap, cost, (int)G[to].size(), false});
    G[to].push_back({from, 0, -cost, (int)G[from].size() - 1, true});
  }
  Cost min_cost_flow(int s, int t, Cap f, bool DAG = false) {
    assert(0 <= s && s < V);
    assert(0 <= t && t < V);
    assert(s != t);
    assert(0 < f);
    Cost res = 0;
    fill(h.begin(), h.end(), 0);
    auto dijkstra = [&]() {
      priority_queue<P, vector<P>, greater<P>> pq;
      fill(dist.begin(), dist.end(), INF);
      dist[s] = 0;
      pq.push(P(0, s));
      while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < (int)G[v].size(); i++) {
          edge& e = G[v][i];
          if (e.cap <= 0 || dist[e.to] <= dist[v] + e.cost + h[v] - h[e.to]) continue;
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          pq.push(P(dist[e.to], e.to));
        }
      }
    };

    if (DAG) {
      fill(dist.begin(), dist.end(), INF);
      dist[s] = 0;
      vector<int> deg_in(V);
      for (int i = 0; i < V; i++) {
        for (const auto& e : G[i]) deg_in[e.to] += (e.cap > 0);
      }
      vector<int> st;
      for (int i = 0; i < V; i++)
        if (!deg_in[i]) st.push_back(i);
      for (int n = 0; n < V; n++) {
        if (int(st.size()) == n) assert(false);
        int now = st[n];
        for (int i = 0; i < (int)G[now].size(); i++) {
          edge& e = G[now][i];
          if (e.isrev) continue;
          deg_in[e.to]--;
          if (deg_in[e.to] == 0) st.push_back(e.to);
          if (e.cap <= 0 || dist[now] == INF || dist[e.to] <= dist[now] + e.cost) continue;
          dist[e.to] = dist[now] + e.cost;
          prevv[e.to] = now;
          preve[e.to] = i;
        }
      }
    } else if (!negative)
      dijkstra();
    else {
      fill(dist.begin(), dist.end(), INF);
      dist[s] = 0;
      for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
          for (int i = 0; i < (int)G[v].size(); i++) {
            edge& e = G[v][i];
            if (e.cap <= 0 || dist[v] == INF || dist[e.to] <= dist[v] + e.cost) continue;
            dist[e.to] = dist[v] + e.cost;
            prevv[e.to] = v;
            preve[e.to] = i;
            if (u == V - 1) assert(false);
          }
        }
      }
    }
    while (true) {
      if (dist[t] == INF) return INF;
      for (int v = 0; v < V; v++) h[v] += dist[v];

      Cap d = f;
      for (int v = t; v != s; v = prevv[v]) {
        d = min(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge& e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
      if (f == 0) break;
      dijkstra();
    }
    return res;
  }
};
#line 4 "main.cpp"

void solve() {
  STR(S);
  LL(N);
  vc<string> A(N);
  vi lim(N);
  FOR(i, N) {
    STR(T);
    LL(x);
    A[i] = T;
    lim[i] = x;
  }
  vi I = {ll(S.size())};
  FOR(i, N) I.eb(I.back() + A[i].size());

  auto in_S = [&](ll i) -> ll { return i; };
  auto in_A = [&](ll n, ll i) -> ll { return I[n] + i; };
  auto common = [&](ll n) -> ll { return I.back() + n; };
  ll source = common(N - 1) + 1;
  ll sink = source + 1;

  MinCostFlow<ll, ll> MCF(sink + 1);
  FOR(i, N) { MCF.add(source, common(i), lim[i], i + 1); }
  FOR(n, N) FOR(i, A[n].size()) { MCF.add(common(n), in_A(n, i), 1, 0); }
  FOR(n, N) FOR(i, A[n].size()) FOR(s, S.size()) {
    if (A[n][i] == S[s]) { MCF.add(in_A(n, i), in_S(s), 1, 0); }
  }
  FOR(s, S.size()) MCF.add(in_S(s), sink, 1, 0);
  ll cost = MCF.min_cost_flow(source, sink, S.size());
  if (cost > (1LL << 50)) cost = -1;
  print(cost);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}