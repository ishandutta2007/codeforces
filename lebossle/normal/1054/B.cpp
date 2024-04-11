#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int mex=0;
  for (int i=0; i<n; ++i) {
    int x;
    cin >> x;
    if (x > mex) {
      cout << i+1 << endl;
      return 0;
    }
    mex = max(mex, x+1);
  }
  cout << -1 << endl;
}