#include <bits/stdc++.h>
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
void printseq(T begin, T end, string sep = " ") {
  if(begin != end){
    cout << *(begin++);
    for (auto it = begin; it != end; it++) {
      cout << sep << (*it);
    }
  }
  cout << "\n";
}

template <typename T>
void printall(T A, string sep = " ") {
  printseq(all(A), sep);
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

vi readvi(int n, int off = 0) {
  vi v(n);
  for (auto&& x : v) {
    x = read() + off;
  }
  return v;
}

string readstr() {
  string s;
  cin >> s;
  return s;
}

vi solve(ll N){
  auto f = [](auto&& self, ll N){
    if(N==2 || N == 3){
      return vi({-1});
    }
    if(N<=8){
      if(N==4) return vi({3,1,4,2});
      if(N==5) return vi({2,4,1,3,5});
      if(N==6) return vi({2,5,3,1,4,6});
      if(N==7) return vi({6,3,1,4,2,5,7});
      if(N==8) return vi({7,3,5,1,4,2,6,8});
    }
    auto A = self(self, N-4);
    ll x = A.back();
    A.pop_back();
    A.eb(x+1);
    A.eb(x+3);
    A.eb(x);
    A.eb(x+2);
    A.eb(x+4);
    return A;
  };
  return f(f, N);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  auto T = read();
  FOR(_, T) {
    ll N = read();
    printall(solve(N));
  }
  return 0;
}