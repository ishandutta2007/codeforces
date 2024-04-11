#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  long long n, a, b;
  cin >> n >> a >> b;
  long long resa = (long long)1e9;
  long long resb = (long long)1e9;
  n *= 6;
  for (long long mn = 1; mn <= 1000 * 1000; mn++) {
    {
      long long cura = mn;
      long long curb = n / mn + (n % mn ? 1 : 0);
      cura = max(cura, a);
      curb = max(curb, b);
      if (cura * curb < resa * resb)
        resa = cura, resb = curb;
    }
    {
      long long curb = mn;
      long long cura = n / mn + (n % mn ? 1 : 0);
      cura = max(cura, a);
      curb = max(curb, b);
      if (cura * curb < resa * resb)
        resa = cura, resb = curb;
    }
  }
  cout << resa * resb << endl;
  cout << resa << " " << resb;
  return 0;
}