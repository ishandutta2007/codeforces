#include <iostream>
#include <map>

using namespace std;

constexpr int K = 50;
int a[K];
int k, l, nnum;
map<int, int> comb[K];

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> k;
    cin.ignore();
    for (int i = 0; i < k; ++i) {
      a[i] = cin.get() - '0';
    }
    comb[0].emplace(0, -1);
    for (l = 1; l <= k; ++l) {
      comb[l].clear();
      for (auto& [num, pos]: comb[l - 1]) {
        for (int i = pos + 1; i < k; ++i) {
          nnum = num * 10 + a[i];
          if (comb[l].count(nnum) == 0) {
            int notprime = nnum == 1;
            for (int j = 2; j * j <= nnum; ++j) {
              notprime |= nnum % j == 0;
            }
            if (notprime) {
              goto output;
            }
            comb[l][nnum] = i;
          }
        }
      }
    }
output:
    cout << l << '\n' << nnum << '\n';
  }
  return 0;
}