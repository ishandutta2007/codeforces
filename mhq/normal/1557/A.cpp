#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <iomanip>

using namespace std;

#define ll long long
#define INF 1000000007
#define _ << " " <<

void Solution() {
  double max = -INF;
  int n;
  cin >> n;
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    double tmp;
    cin >> tmp;
    sum += tmp;
    if (max < tmp) {
      max = tmp;
    }
  }
  cout << fixed << setprecision(10) <<  max + (sum - max) / (n - 1) << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    Solution();
  }
  return 0;
}