#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define ZERO(v) memset((v), 0, sizeof (v))

const int MAXN = 5001;

int n;

struct Loga {
  Loga() { ZERO(arr); }

  void add(int p) {
    for (++p; p <= n; p += p&-p) {
      ++arr[p];
    }
  }

  int query(int p) const {
    int ans = 0;
    for (++p; p > 0; p -= p&-p) {
      ans += arr[p];
    }
    return ans;
  }

  short arr[MAXN+1];
};

int main() {
  cin.sync_with_stdio(0);

  cin >> n;
  vector<int> perm(n);
  for (int &x : perm) {
    cin >> x;
  }

  int initial = 0;
  {
    Loga loga;
    for (int i=0; i<n; ++i) {
      initial += i - loga.query(perm[i]);
      loga.add(perm[i]);
    }
  }
  // debug(initial);

  int ans = initial, anscnt = 0;
  for (int i=0; i<n; ++i) {
    Loga loga;
    int B = perm[i];
    int qb = 0;
    for (int j=i+1; j<n; ++j) {
      int A = perm[j];
      if (A < B) {
        int qa = loga.query(A);
        int swaps = initial - 1 - 2 * (qb - qa);
        if (swaps < ans) {
          ans = swaps;
          anscnt = 1;
        } else if (swaps == ans) {
          ++anscnt;
        }
      }
      loga.add(A);
      qb += A < B;
    }
  }
  cout << ans << ' ' << anscnt << '\n';
  return 0;
}