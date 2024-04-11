#include <iostream>
#include <numeric>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;

constexpr int N = 3e5 + 1;

int64_t a[N], p[N];

struct FT {
  using T = int64_t;
  static constexpr int N = ::N;

  T& op(T& val, const T& arg) {
    return val += arg;
  }

  void build() {
    for (int i = 0; i < N; ++i) if ((i | (i + 1)) < N) {
      op(ft[i | (i + 1)], ft[i]);
    }
  }

  void update(int i, T val = 1) {
    for (; i < N; i |= i + 1) {
      op(ft[i], val);
    }
  }

  T query(int i) {
    T res{};
    for (; i; i &= i - 1) {
      op(res, ft[i - 1]);
    }
    return res;
  }

  void rupdate(int i, T val = 1) { return update(N - i - 1, val); }

  T rquery(int i) { return query(N - 1 - i); }

private:
  T ft[N];
} ft[2];

void solve(int n) {
  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = a[i]; j < N; j += a[i]) {
      p[i] += ft[0].rquery(j - 1);
      ft[1].update(j, a[i]);
    }
    sum += a[i];
    ft[0].rupdate(a[i]);
    p[i] = sum + a[i] * (i - p[i]) - ft[1].query(a[i] + 1);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  solve(n);
  partial_sum(p, p + n, p);
  for (int i = 0; i < n; ++i) {
    cout << p[i] << ' ';
  }
  cout << '\n';
}