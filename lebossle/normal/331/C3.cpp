#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> ii;

map<ii, ii> memo;
ii f(lli x, lli d, lli p) {
  ii key(x, d);
  if (memo.count(key))
    return memo[key];

  if (x == 0 && d == 0)
    return ii(0, 0);
  lli curd = max(d, x/p);
  if (p == 1)
    return make_pair(1, x-curd);

  lli rem = x%p;
  ii ans = f(rem, curd, p/10);
  x = x-rem + ans.second;
  if (x >= 0) {
    ii aux = f(x, d, p);
    ans = ii(ans.first+aux.first, aux.second);
  }

  memo[key] = ans;
  return ans;
}

int main() {
  lli n;
  cin >> n;
  cout << f(n, 0, 1000000000000000000LL).first << endl;
}