#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
  int n;
  cin >> n;
  vector<lli> a(n);
  for (lli& i : a)
    cin >> i;
  lli sum=0;
  for (lli i : a)
    sum += i;
  if (sum == 1) {
    cout << -1 << endl;
    return 0;
  }
  vector<lli> divs;
  for (lli i=1; i*i<=sum; ++i)
    if (sum%i == 0) {
      divs.push_back(i);
      divs.push_back(sum/i);
    }
  lli best=1e18;
  for (lli d : divs) if (d>1) {
    lli ans=0;
    lli acum=0;
    for (lli i : a) {
      ans += abs(acum);
      acum += i;
      acum %= d;
      if (d-acum < acum)
        acum -= d;
    }
    best = min(best, ans);
  }
  cout << best << endl;
}