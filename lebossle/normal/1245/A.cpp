#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    solve();
  }
}

int gcd(int a, int b) {
  if (a==0)
    return b;
  return gcd(b%a, a);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << (gcd(a, b)==1 ? "Finite" : "Infinite") << '\n';
}