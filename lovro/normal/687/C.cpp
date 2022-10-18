#define NDEBUG
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;


const int MAX = 505;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  static bitset<MAX> dp[MAX][MAX];
  dp[0][0].set(0);
  for (int i=0; i<n; ++i) {
    int c;
    cin >> c;
    for (int a=0; a<=k; ++a) {
      dp[i+1][a] |= dp[i][a];
      if (a+c <= k) {
        dp[i+1][a+c] |= dp[i][a];
      }
      dp[i+1][a] |= dp[i][a] << c;
    }
  }
  vector<int> out;
  for (int a=0; a<=k; ++a) {
    if (dp[n][a].test(k-a)) {
      out.push_back(a);
    }
  }
  cout << out.size() << '\n';
  for (int i=0; i<(int)out.size(); ++i) {
    cout << out[i] << "\n "[i < (int)out.size() - 1];
  }
}