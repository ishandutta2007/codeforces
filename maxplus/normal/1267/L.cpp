#include <algorithm>
#include <iostream>

using namespace std;

string words[1000];

int main() {
  int n, l, k; cin >> n >> l >> k;
  string s; cin >> s;
  sort(s.begin(), s.end());
  int x = 0, y = k - 1, pos = 0;
  while (words[y].size() < l) {
    for (int i = x; i <= y; ++i) {
      words[i] += s[pos++];
    }
    while (words[x].back() != words[y].back()) {
      ++x;
    }
  }
  for (int i = 0; i < n; ++i) {
    while (words[i].size() < l) {
      words[i] += s[pos++];
    }
    cout << words[i] << '\n';
  }
}