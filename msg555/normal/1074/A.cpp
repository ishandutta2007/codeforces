#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> xs(N);
  for (int i = 0; i < N; i++) {
    cin >> xs[i];
  }
  sort(xs.begin(), xs.end());

  int base = 0;
  vector<int> ys(M);
  for (int i = 0; i < M; i++) {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    if (x1 == 1) {
      if (x2 == 1000000000) {
        base++;
      } else {
        ys.push_back(x2);
      }
    }
  }
  sort(ys.begin(), ys.end());

  int result = ys.size();
  int j = 0;
  for (int i = 0; i < ys.size(); i++) {
    while (j < xs.size() && xs[j] <= ys[i]) {
      j++;
    }
    result = min(result, int(ys.size() - 1 - i) + j);
  }
  cout << base + result << endl;

  return 0;
}