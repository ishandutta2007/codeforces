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


template <typename T>
ll sum(T A){
  ll x = 0;
  for(auto& y: A) x += y;
  return x;
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

vi read_vec(int n, int off = 0) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
    x += off;
  }
  return A;
}

string read_str() {
  string s;
  cin >> s;
  return s;
}
#line 3 "main.cpp"

const ll INF = 1 << 30;

ll calc(vi A, ll a, ll b) {
  auto N = A.size();
  ll cnt = 0;
  ll i = find(all(A), a) - A.begin();
  if (i == N) return INF;
  while (i > 0) {
    swap(A[i - 1], A[i]);
    --i;
    ++cnt;
  }
  ll j = find(A.begin() + 1, A.end(), b) - A.begin();
  if (j == N) return INF;
  while (j > 1) {
    swap(A[j - 1], A[j]);
    --j;
    ++cnt;
  }
  ll k = N - 1;
  while (A[k] == 0) {
    --k;
  }
  while (k < A.size() - 1) {
    swap(A[k], A[k + 1]);
    ++k;
    ++cnt;
  }
  assert(A[N - 1] != 0);
  if (A[0] != a) return INF;
  if (A[1] != b) return INF;
  return cnt;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  auto N = read();
  vi A;
  while (N) {
    A.eb(N % 10);
    N /= 10;
  }
  ll x = INF;
  x = min(x, calc(A, 0, 0));
  x = min(x, calc(A, 5, 2));
  x = min(x, calc(A, 0, 5));
  x = min(x, calc(A, 5, 7));
  if (x == INF) x = -1;
  print(x);
  return 0;
}