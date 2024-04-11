#include <bits/stdc++.h>

using namespace std;

int main()
{
  bool a, b, c, d;
  cin >> a >> b >> c >> d;
  bool a1, b1, c1, d1;
  a1 = a^b;
  b1 = c | d;
  c1 = c & b;
  d1 = d ^ a;
  a1 = a1 & b1;
  b1 = c1 | d1;
  a1 = a1 ^ b1;
  cout << a1;
  return 0;
}