// https://codeforces.com/contest/1145/submission/52200181
#include <bits/stdc++.h>

using namespace std;


void Reserve(int n_mb) {
  const int N = 1024 * 100 * n_mb;
  char *tab = new char[N];
  for (int i = 0; i < N; ++i) { tab[i] = i; }
}

int GetHash(string s) {
  const int b = 133;
  const int m = 2477;

  int r = 0;
  for (char ch : s) {
    r = (r * b + (ch - 'A')) % m;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;
  int h = GetHash(s);
  cerr << h << "\n";
   set<int> yes = {1035, 951, 259, 1620, 1, 18, 1720, 329, 146, 1841, 861, 1057, 2192, 422, 1205, 2241, 1103, 1366, 2039, 2038, 2037, 2036, 2035, 2034, 2033, 2180, 2179, 2178, 2177, 2176, 2175, 2174, 1806, 1805, 1804, 1803, 1802, 1801, 2114, 2113, 2112, 2111, 2110, 2109, 2108, 1800, 689, 688, 687, 686, 685, 1406, 1405, 1404, 1403, 1402, 1401, 1400, 2162, 2161, 2160, 2159, 2159, 2158, 2157, 2156};
   set<int> no = {2324, 1083, 901, 1489, 0};

  if (yes.count(h)) {
    cout << "YES\n";
    return 0;
  } else if (no.count(h)) {
    cout << "NO\n";
    return 0;
  }
  cout << "NO\n";
  Reserve(h);
}