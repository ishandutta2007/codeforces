#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set<string> d;
  set<string> rd;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    d.insert(s);
  }
  string ansp, ansm;
  for (auto s: d) {
    auto ts = s;
    reverse(ts.begin(), ts.end());
    if (s == ts) {
      ansm = s;
    } else if (d.count(ts) && !rd.count(s)) {
      ansp += s;
      rd.insert(ts);
    }
  }
  cout << ansp.size() * 2 + ansm.size() << '\n';
  cout << ansp << ansm;
  reverse(ansp.begin(), ansp.end());
  cout << ansp;
}