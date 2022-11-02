#include <bits/stdc++.h>

using namespace std;

const string L = "RGBYW";

int main() {
  #ifdef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> c1;
  vector<int> c2;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    c1.push_back(L.find(s[0]));
    c2.push_back(s[1] - '1');
  }
  int res = 10;
  for (int m1 = 0; m1 < (1 << 5); m1++)
    for (int m2 = 0; m2 < (1 << 5); m2++) {
      bool ok = true;
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
          bool diff = false;
          if (c1[i] == c1[j] && c2[i] == c2[j])
            continue;
          if (c1[i] != c1[j] && ((m1 & (1 << c1[i])) || (m1 & (1 << c1[j]))))
            diff = true;
          if (c2[i] != c2[j] && ((m2 & (1 << c2[i])) || (m2 & (1 << c2[j]))))
            diff = true;
          if (!diff)
            ok = false;
        }
      if (ok)
        res = min(res, __builtin_popcount(m1) + __builtin_popcount(m2));
    }
  cout << res;

  return 0;
}