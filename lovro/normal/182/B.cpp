#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define repeat(n) for ( int repc = (n); repc > 0; --repc )
typedef long long int64;

int main() {
  cin.sync_with_stdio(0);

  int D, n;
  cin >> D >> n;

  int displayed = 0;
  int64 res = 0;
  repeat (n) {
    int days;
    cin >> days;
    
    if (displayed != 0) {
      res += D - displayed;
      displayed = 0;
    }
    displayed = (displayed + days) % D;
  }

  cout << res << '\n';

  return 0;
}