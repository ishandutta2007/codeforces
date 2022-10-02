#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
#define int ll
using pi = pair<int, int>;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define FOR3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define FOR_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define all(x) x.begin(), x.end()

#define eb emplace_back
#define mp make_pair
#define mt make_tuple

template <typename T>
void print(T x) {
  cout << x << "\n";
}

template <typename A, typename B>
void print(A x, B y, string sep = " ") {
  cout << x << sep << y << "\n";
}

template <typename A, typename B, typename C>
void print(A x, B y, C z, string sep = " ") {
  cout << x << sep << y << sep << z << "\n";
}

template <typename T>
void print_seq(T begin, T end, string sep = " ") {
  if (begin != end) {
    cout << *(begin++);
    for (auto it = begin; it != end; it++) {
      cout << sep << (*it);
    }
  }
  cout << "\n";
}

template <typename T>
void print_all(T A, string sep = " ") {
  print_seq(all(A), sep);
}

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

ll read() {
  ll i;
  cin >> i;
  return i;
}

pi read2() {
  ll a, b;
  cin >> a >> b;
  return {a, b};
}

tuple<ll, ll, ll> read3() {
  ll a, b, c;
  cin >> a >> b >> c;
  return {a, b, c};
}

template <typename T>
vector<T> read_vec(int n, int off = 0) {
  vector<T> A(n);
  for (auto&& x : A) {
    cin >> x;
    x += off;
  }
  return A;
}

string readstr() {
  string s;
  cin >> s;
  return s;
}
#line 3 "/home/maspy/library/data_structure/unionfind.hpp"

struct UnionFind {
  int num;
  int comp;
  vi v_sz, e_sz, par;
  UnionFind(int n) : num(n), comp(n), v_sz(n, 1), e_sz(n, 0), par(n) { iota(par.begin(), par.end(), 0); }
  int find(int x) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  bool merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      e_sz[x]++;
      return false;
    }
    comp--;
    if (v_sz[x] < v_sz[y]) swap(x, y);
    e_sz[x] += e_sz[y] + 1;
    v_sz[x] += v_sz[y];
    par[y] = x;
    return true;
  }

  vi find_all() {
    vi A(num);
    FOR(i, num) A[i] = find(i);
    return A;
  }
};
#line 4 "main.cpp"

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll N = read();
  ll M = read();

  vi deg(N);
  auto uf = UnionFind(N);

  FOR(_, M) {
    auto [a, b] = read2();
    --a;
    --b;
    uf.merge(a, b);
    ++deg[a];
    ++deg[b];
  }

  vi ok(N, 1);

  FOR(v, N) {
    if (uf.find(v) != v) ok[v] = 0;
    if (deg[v] != 2) ok[uf.find(v)] = false;
  }
  ll ans = accumulate(all(ok), 0);
  print(ans);
  return 0;
}