#include <bits/stdc++.h>

using namespace std;

int k, n1, n2, n3, t1, t2, t3;
int t = 0;
vector<int> f;

bool can(int x) {
  int c1 = f.end() - upper_bound(f.begin(), f.end(), t + x - t1);
  int c2 = f.end() - upper_bound(f.begin(), f.end(), t + x - t2);
  int c3 = f.end() - upper_bound(f.begin(), f.end(), t + x - t3);
  if (c1 >= n1)
    return false;
  if (c2 >= n2)
    return false;
  if (c3 >= n3)
    return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  for (int p = 1; p <= k; p++) {
    int l = 0;
    int r = 1000 * 1000;
    while (l < r) {
      int m = (l + r) / 2;
      if (can(m))
        r = m;
      else
        l = m + 1;
    }
    t += l;
    f.push_back(t);
  }
  cout << t + t1 + t2 + t3;

  return 0;
}