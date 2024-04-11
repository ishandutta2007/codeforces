#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define MOD 1000000007
#define MAXN 200010

int madd(int x, int y) {
  x += y;
  if (x < 0) x += MOD;
  if (x >= MOD) x -= MOD;
  return x;
}

int mmul(int x, int y) {
  return (1ll * x * y) % MOD;
}

int FACT[MAXN];
int IFACT[MAXN];

int ncr(int n, int r) {
  return mmul(FACT[n], mmul(IFACT[r], IFACT[n - r]));
/*
  int res = 1;
  for (int i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
*/
}

int mexp(int x, int e) {
  int r = 1;
  for (int i = 31 - __builtin_clz(e); i >= 0; i--) {
    r = (1ll * r * r) % MOD;
    if (e & 1 << i) {
      r = (1ll * r * x) % MOD;
    }
  }
  return r;
}

int main() {
  for (int i = FACT[0] = IFACT[0] = 1; i < MAXN; i++) {
    FACT[i] = mmul(FACT[i - 1], i);
    IFACT[i] = mexp(FACT[i], MOD - 2);
  }

  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  string S; cin >> S;

  vector<pair<pair<int, int>, int> > query;
  for (int t = 1; t <= T; t++) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      cin >> S;
      continue;
    }

    int N; cin >> N;
    query.push_back(make_pair(make_pair(S.size(), N), t - 1));
  }

  vector<int> result(T, -1);
  sort(query.begin(), query.end());
  for (int i = 0; i < query.size(); ) {
    int sz = 0;
    int ssz = query[i].first.first;
    while (i + sz < query.size() && ssz == query[i + sz].first.first) {
      sz++;
    }

    for (int j = 0, res = 0, ncrterm = 1, me25 = 1; ; j++) {
      while (sz > 0 && query[i].first.second < j + ssz) {
        result[query[i].second] = res;
        sz--;
        i++;
      }
      if (sz == 0) {
        break;
      }
      res = mmul(res, 26);
      res = madd(res, mmul(ncr(ssz - 1 + j, j), me25));
      me25 = mmul(me25, 25);
    }
  }

  for (int i = 0; i < result.size(); i++) {
    if (result[i] != -1) {
      cout << result[i] << '\n';
    }
  }
/*
    if (N < S.size()) {
      cout << "0\n";
      continue;
    }

    N -= S.size();

    int res = 0;
    for (int i = 0; i <= N; i++) {
      res += ncr(S.size() - 1 + i, i) * mexp(25, i) * mexp(26, N - i);
    }
    cout << res << endl;
*/

  return 0;
}