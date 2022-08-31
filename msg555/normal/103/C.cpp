#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, k, p; cin >> n >> k >> p;
  for(int i = 0; i < p; i++) {
    long long x; cin >> x; x--;
    if(k == 0) {
      cout << '.';
    } else if(k == 1) {
      cout << (x + 1 == n ? 'X' : '.');
    } else if(2 * k >= n) {
      if(x % 2 == 1 || x >= 2 * (n - k)) {
        cout << 'X';
      } else {
        cout << '.';
      }
    } else {
      long long lft = n - k - (k - 1);
      if(x < lft) {
        cout << '.';
      } else if(lft % 2) {
        cout << ((n - x) % 2 ? 'X' : '.');
      } else {
        if(x + 1 == n) {
          cout << 'X';
        } else {
          cout << ((n - x) % 2 ? '.' : 'X');
        }
      }
    }
  }
  cout << endl;
}