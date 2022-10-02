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
#define fi first
#define se second
#define VEC vector


// [
ll in() {
  ll i;
  cin >> i;
  return i;
}

vi vin(int n) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
  }
  return A;
}
// ]

// [
void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}
// ]

vector<int> prime_table(ll N) {
  assert(N >= 2);
  ++N;
  vector<bool> is_prime(N);

  for (int i = 3; i < N; i += 2) is_prime[i] = true;
  is_prime[2] = true;
  for (int p = 3;; p += 2) {
    int i = p * p;
    if (i >= N) break;
    if (!is_prime[p]) continue;
    for (; i < N; i += p + p) {
      is_prime[i] = false;
    }
  }
  vector<int> primes;
  primes.reserve(N);
  primes.emplace_back(2);
  for (int p = 3; p < N; p += 2) {
    if (is_prime[p]) primes.emplace_back(p);
  }
  return primes;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  auto N = in();
  auto A = vin(N);

  ll MAX = 10'000'010;
  auto primes = prime_table(MAX);

  const ll INF = 1LL << 60;
  VEC<pi> data(MAX, mp(INF, INF));

  auto add = [&](pi& p, ll x) -> void {
    if (p.fi > x) {
      p.se = p.fi;
      p.fi = x;
    } else if (p.se > x) {
      p.se = x;
    }
  };

  auto merge = [&](pi& p, pi& q) -> void {
    add(p, q.fi);
    add(p, q.se);
  };

  for (auto&& x : A) {
    add(data[x], x);
  }

  for (auto&& p : primes) {
    ll N = MAX - 1;
    FOR3_R(i, 1, (N / p) + 1) { merge(data[i], data[i * p]); }
  }

  ll best_lcm = INF;
  ll best_d = -1;

  FOR(d, MAX) {
    auto [x, y] = data[d];
    if (y < INF) {
      ll lcm = x / d * y;
      if (best_lcm > lcm) {
        best_lcm = lcm;
        best_d = d;
      }
    }
  }
  auto [x, y] = data[best_d];
  ll xi = -1, yi = -1;
  VEC<bool> done(N);
  FOR(i, N) {
    if (A[i] == x) {
      xi = i;
      done[i] = true;
      break;
    }
  }
  FOR(i, N) {
    if (!done[i] && A[i] == y) {
      yi = i;
      break;
    }
  }
  if (xi > yi) swap(xi, yi);
  print(++xi, ++yi);

  return 0;
}