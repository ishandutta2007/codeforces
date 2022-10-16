#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

constexpr int N = 1e5;

vector<int> ch[N];
int b[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int j; cin >> j;
    ch[--j].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int nemp = 0;
  vector<int> f;
  for (int i = 0; i < k; ++i) {
    sort(ch[i].begin(), ch[i].end(), [](int x, int y) { return b[x] < b[y]; });
    nemp += ch[i].empty();
    for (int k = 0; k + 1 < ch[i].size(); ++k) {
      f.push_back(b[ch[i][k]]);
    }
  }
  sort(f.begin(), f.end());
  cout << accumulate(f.begin(), f.begin() + nemp, 0ll) << '\n';
}