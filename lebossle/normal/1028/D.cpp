#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long int lli;

const lli MOD = 1e9+7;

const int MAX = 4e8;

int main() {
  int n;
  cin >> n;
  set<int> prices;
  prices.insert(-1);
  prices.insert(MAX);
  int maxBuy = -1;
  int minSell = MAX;
  lli sol=1;
  for (int t=0; t<n; ++t) {
    string op; int p;
    cin >> op >> p;
    if (op == "ADD") {
      prices.insert(p);
    } else {
      if (p > maxBuy && p < minSell) {
        sol = (sol*2)%MOD;
      } else if (p < maxBuy || p > minSell) {
        sol = 0;
      }
      prices.erase(p);
      auto it = prices.upper_bound(p);
      minSell = *it;
      it--;
      maxBuy = *it;
    }
  }
  lli amt=0;
  for (int p : prices)
    if (p > maxBuy && p < minSell)
      amt++;
  sol = (sol*(amt+1))%MOD;
  cout << sol << endl;
}