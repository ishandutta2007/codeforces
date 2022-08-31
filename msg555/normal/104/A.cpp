#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;
  if(N < 11 || N > 21) cout << 0 << endl;
  else if(N == 20) cout << 15 << endl;
  else cout << 4 << endl;
}