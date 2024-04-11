#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<int> inp(n);
  for (int& i : inp)
    cin >> i;
  set<int> s(inp.begin(), inp.end());
  set<int> used;
  cout << n-s.size() << endl;
  for (int i : inp) {
    if (used.count(i)) {
      int j = i-(i%10);
      for (int d=0; d<10; ++d) {
        if (!used.count(j+d) && !s.count(j+d))
          i = j+d;
      }
    }
    used.insert(i);
    printf("%04d\n", i);
  }
}
 
int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    solve();
  }
}