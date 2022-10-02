#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

void YESNO(bool bl) {
  cout << (bl ? "YES" : "NO") << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vi v({a, b, c, d});
    sort(v.begin(), v.end());
    int second = v[2];
    int x = min(max(a, b), max(c, d));
    YESNO(second == x);
  }
  return 0;
}