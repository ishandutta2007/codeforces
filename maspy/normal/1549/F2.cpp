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

using u64 = unsigned long long;
inline u64 binary_gcd(u64 a, u64 b) {
  if (a == 0 || b == 0) return a + b;
  char n = __builtin_ctzll(a);
  char m = __builtin_ctzll(b);
  a >>= n;
  b >>= m;
  n = min(n, m);
  while (a != b) {
    u64 d = a - b;
    char s = __builtin_ctzll(d);
    bool f = a > b;
    b = f ? b : a;
    a = (f ? d : -d) >> s;
  }
  return a << n;
}

ll solve_D1(vc<pi>& XY) {
  vv(ll, CNT, 4, 4);
  FORIN(p, XY) {
    ll a = p.fi, b = p.se;
    CNT[a % 4][b % 4]++;
  }

  auto check = [&](int a, int b, int c) -> bool {
    int xa = a / 4, ya = a % 4;
    int xb = b / 4, yb = b % 4;
    int xc = c / 4, yc = c % 4;
    int gab = binary_gcd(abs(xa - xb), abs(ya - yb));
    int gbc = binary_gcd(abs(xb - xc), abs(yb - yc));
    int gca = binary_gcd(abs(xc - xa), abs(yc - ya));
    return (gab + gbc + gca) % 4 == 0;
  };
  // distinct
  ll ANS = 0;
  FOR(a, 16) {
    FOR(b, a) {
      FOR(c, b) {
        int xa = a / 4, ya = a % 4;
        int xb = b / 4, yb = b % 4;
        int xc = c / 4, yc = c % 4;
        ll ca = CNT[xa][ya];
        ll cb = CNT[xb][yb];
        ll cc = CNT[xc][yc];
        if (check(a, b, c)) ANS += ca * cb * cc;
      }
    }
  }
  // aab
  FOR(a, 16) {
    FOR(b, 16) {
      int xa = a / 4, ya = a % 4;
      int xb = b / 4, yb = b % 4;
      ll ca = CNT[xa][ya];
      ll cb = CNT[xb][yb];
      if (a == b) continue;
      if (check(a, a, b)) ANS += ca * (ca - 1) / 2 * cb;
    }
  }
  // aaa
  FOR(a, 16) {
    int xa = a / 4, ya = a % 4;
    ll ca = CNT[xa][ya];
    if (check(a, a, a)) ANS += ca * (ca - 1) * (ca - 2) / 6;
  }
  return ANS;
}

void solve() {
  // 3gcd
  LL(N);
  vc<pi> XY(N);
  FOR(i, N) {
    INT(a, b);
    XY[i] = mp(a, b);
  }

  ll ANS = 0;

  FOR(x, 2) {
    FOR(y, 2) {
      vc<pi> XY1;
      FORIN(p, XY) {
        if (p.fi % 2 == x && p.se % 2 == y) {
          XY1.eb(p);
        }
      }
      ANS += solve_D1(XY1);
    }
  }

  /*
   2  gcd 
  (gcd mod 4, x mod 4, y mod 4) 
  */
  FOR(i, N) {
    vi CNT(64);
    FOR(j, N) {
      if (i == j) continue;
      int dx = XY[i].fi - XY[j].fi;
      int dy = XY[i].se - XY[j].se;
      int g = binary_gcd(abs(dx), abs(dy)) % 4;
      dx %= 4;
      dy %= 4;
      if (dx < 0) dx += 4;
      if (dy < 0) dy += 4;
      // g, dx, dy
      int k = 16 * g + 4 * dx + dy;
      ++CNT[k];
    }

    auto check = [&](int a, int b) -> bool {
      int ga = a / 16, xa = (a / 4) % 4, ya = a % 4;
      int gb = b / 16, xb = (b / 4) % 4, yb = b % 4;
      if (ga % 2 == 0 || gb % 2 == 0) return false;
      if ((xa - xb) % 2 == 1 || (ya - yb) % 2 == 1) return false;
      int S = abs(xa * yb - ya * xb);
      if (S % 2 == 1) return false;
      S /= 2;

      int gab = binary_gcd(abs(xa - xb), abs(ya - yb));
      int P = ga + gb + gab;
      int I = P / 2 + 1 + S;
      return I % 2 != 0;
    };

    //  2 
    FOR(a, 64) {
      FOR(b, a) {
        if (check(a, b)) ANS += CNT[a] * CNT[b];
      }
    }
    // 
    FOR(a, 64) {
      if (check(a, a)) ANS += CNT[a] * (CNT[a] - 1) / 2;
    }
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}