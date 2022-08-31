#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define INF 1000000000

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<pair<int, int> > A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  int result = 0;
  for (int i = 0; i < 2; i++) {
    int mnx = INF;
    int mxx = -INF;
    int mny = INF;
    int mxy = -INF;
    for (auto pt : A) {
      mnx = min(mnx, pt.first);
      mxx = max(mxx, pt.first);
      mny = min(mny, pt.second);
      mxy = max(mxy, pt.second);
    }

    for (auto pt : A) {
      result = max(result, (pt.first - mnx) + (pt.second - mny));
      result = max(result, (pt.first - mnx) + (mxy - pt.second));
      result = max(result, (mxx - pt.first) + (pt.second - mny));
      result = max(result, (mxx - pt.first) + (mxy - pt.second));
    }

    if (!i) for (auto& pt : A) {
      pt = make_pair(pt.second, -pt.first);
    }
  }
  cout << 2 * result;

  int result_4 = 0;
  for (int i = 0; i < N; i++) {
    int j = (i + 1) % N;
    result_4 += abs(A[j].first - A[i].first) + abs(A[j].second - A[i].second);
  }

  for (int i = 4; i <= N; i++) {
    cout << ' ' << result_4;
  }
  cout << endl;

  return 0;
}