#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, a, b; cin >> n >> m >> a >> b; --a; --b;
  
  int ar = a / m;
  int ac = a % m;
  int br = b / m;
  int bc = b % m;

  int res;
  if(b + 1 == n) {
    res = (ar == br || ac == 0) ? 1 : 2;
  } else if(ar == br || ac == 0 && bc + 1 == m) {
    res = 1;
  } else if(ar + 1 == br || bc + 1 == ac || bc + 1 == m || ac == 0) {
    res = 2;
  } else {
    res = 3;
  }
  cout << res << endl;
}