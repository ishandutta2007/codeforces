/*input
5
1 4
3 5
8 86
68 86
6 86868

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
const int N = 2e5;
const int M = 2 * N + 5;

int primes[M];
void eratosthene() {
  for (int i = 2; i <= M - 5; i++)
    if (primes[i] == 0)
      for (int j = i; j <= M - 5; j += i)
        primes[j] = i;
}

vector<int> listDivisors(int num) {
  vector<int> ans = {1};
  while (num != 1) {
    int p = primes[num];
    int buf = 1;
    int sz = ans.size();
    while (num % p == 0) {
      num /= p;
      buf *= p;
      loop(i, 0, sz - 1) { ans.push_back(ans[i] * buf); }
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}

vector<pair<int, int>> seg[N + 5];

void calc(int k) {
  vector<int> divisors2 = listDivisors(2 * k);
  divisors2.pop_back();
  divisors2.pop_back();

  loop(i, 0, divisors2.size() - 1) {
    int cnt = 0;
    loop(j, i + 1, divisors2.size() - 1) {
      if (k % divisors2[i] == 0 && k % divisors2[j] == 0)
        cnt++;
      else if (divisors2[i] + divisors2[j] > k)
        cnt++;
    }
    if (cnt != 0)
      seg[k].push_back({divisors2[i], cnt});
  }
}

int numTriplets(int l, int r) {
  int len = (r - l + 1);
  return len * (len - 1) * (len - 2) / 6;
}

struct BITx {
  int tree[N + 5];
  BITx() { memset(tree, 0, sizeof(tree)); }
  void update(int i, int val) {
    for (; i; i -= i & -i)
      tree[i] += val;
  }
  int get(int i) {
    int ret = 0;
    for (; i < N + 5; i += i & -i)
      ret += tree[i];
    return ret;
  }
} BIT;

void updateIn(int R) {
  for (auto [pos, val] : seg[R]) {
    BIT.update(pos, val);
  }
}

struct Query {
  int l, r, id, ans;
  Query(int l, int r, int id) : l(l), r(r), id(id), ans(0) {}
};

vector<Query> queries;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  eratosthene();
  loop(i, 1, N) { calc(i); }

  int T;
  cin >> T;
  loop(cT, 1, T) {
    int l, r;
    cin >> l >> r;
    queries.push_back({l, r, cT});
  }

  sort(queries.begin(), queries.end(),
       [](const Query &a, const Query &b) { return a.r < b.r; });

  int R = 0;
  for (auto &[l, r, id, ans] : queries) {
    while (R < r) {
      R++;
      updateIn(R);
    }

    ans = numTriplets(l, r) - BIT.get(l);
  }

  sort(queries.begin(), queries.end(),
       [](const Query &a, const Query &b) { return a.id < b.id; });

  for (auto &[l, r, id, ans] : queries) {
    cout << ans << endl;
  }
}