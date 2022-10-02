#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
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
#define all(x) x.begin(), x.end()

#define elif else if

#define popcnt __builtin_popcount

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

#define INT(...)                                                                                                                                               \
  int __VA_ARGS__;                                                                                                                                           \
  IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
  ll __VA_ARGS__;                                                                                                                                            \
  IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
  string __VA_ARGS__;                                                                                                                                        \
  IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
  char __VA_ARGS__;                                                                                                                                          \
  IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
  double __VA_ARGS__;                                                                                                                                        \
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
  sort(all(ids), [&](ll i, ll j){return mp(A[i],i)<=mp(A[j],j);});
  return ids;
}


template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
#line 3 "main.cpp"

void solve() {
  LL(H, W);
  vector<string> A(H + 2);
  FOR(h, H + 2) A[h].assign(W + 2, '.');
  FOR3(h, 1, H + 1) {
    STR(S);
    FOR(w, W) A[h][w + 1] = S[w];
  }
  // 
  vi diff_X, diff_Y;
  FOR3(h, 1, H + 2) {
    bool diff = false;
    FOR(w, W + 2) if (A[h][w] != A[h - 1][w]) diff = true;
    if (diff) diff_X.eb(h);
  }
  FOR3(w, 1, W + 2) {
    bool diff = false;
    FOR(h, H + 2) if (A[h][w] != A[h][w - 1]) diff = true;
    if (diff) diff_Y.eb(w);
  }
  if (diff_X.size() == 0 || diff_X.size() > 8 || diff_Y.size() > 8) {
    NO();
    return;
  }

  auto add_nbd = [&](ll H, vi diff) -> vi {
    vi cand;
    FORIN(x, diff) {
      FOR3(d, -2, 2) {
        ll y = x + d;
        if (y >= MIN(diff) && y < MAX(diff)) cand.eb(y);
      }
    }
    UNIQUE(cand);
    return cand;
  };

  auto cand_X = add_nbd(H, diff_X);
  auto cand_Y = add_nbd(H, diff_Y);

  ll nx = cand_X.size(), ny = cand_Y.size();
  ll min_X = MIN(diff_X);
  ll max_X = MAX(diff_X) - 1;
  ll min_Y = MIN(diff_Y);
  ll max_Y = MAX(diff_Y) - 1;

  auto cover = [&](ll x1, ll y1, ll x2, ll y2, ll h, ll w) -> bool {
    if (x1 < h && h < x2 && y1 < w && w < y2) return false;
    if (x1 <= h && h <= x2 && y1 <= w && w <= y2) return true;
    return false;
  };

  auto check = [&](ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) -> bool {
    FORIN(x, diff_X) {
      bool ok = false;
      FORIN(rx, vi({x1, x2, x3, x4})) {
        if (x == rx || x == rx + 1) {
          ok = true;
          break;
        }
      }
      if (!ok) return false;
    }
    FORIN(y, diff_Y) {
      bool ok = false;
      FORIN(ry, vi({y1, y2, y3, y4})) {
        if (y == ry || y == ry + 1) {
          ok = true;
          break;
        }
      }
      if (!ok) return false;
    }
    FORIN(h, cand_X) FORIN(w, cand_Y) {
      FOR3(dx, -2, 2) FOR3(dy, -2, 2) {
        if (h + dx <= 0 || H < h + dx || w + dy <= 0 || W < w + dy) continue;
        bool cov1 = cover(x1, y1, x2, y2, h + dx, w + dy);
        bool cov2 = cover(x3, y3, x4, y4, h + dx, w + dy);
        bool cov = cov1 || cov2;
        if (cov ^ (A[h + dx][w + dy] == '#')) return false;
      }
    }
    return true;
  };

  FORIN(x1, cand_X) FORIN(x3, cand_X) {
    if (x1 > x3) continue;
    if (min(x1, x3) != min_X) continue;
    FORIN(y1, cand_Y) FORIN(y3, cand_Y) {
      if (min(y1, y3) != min_Y) continue;
      FORIN(x2, cand_X) FORIN(x4, cand_X) {
        if (max(x2, x4) != max_X) continue;
        if (x2 < x1 + 2) continue;
        if (x4 < x3 + 2) continue;
        FORIN(y2, cand_Y) {
          if (y2 < y1 + 2) continue;
          FORIN(y4, cand_Y) {
            if (y4 < y3 + 2) continue;
            if (max(y2, y4) != max_Y) continue;
            if (check(x1, y1, x2, y2, x3, y3, x4, y4)) {
              YES();
              print(x1, y1, x2, y2);
              print(x3, y3, x4, y4);
              return;
            }
          }
        }
      }
    }
  }
  NO();
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}